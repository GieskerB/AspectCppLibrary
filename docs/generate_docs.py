import os
import re

class DocEntry:
    """Represents a single documented item (e.g., aspect, pointcut, attribute)."""
    def __init__(self, doc_type, name, brief="", description=None, source_file="", line_num=-1):
        self.doc_type = doc_type # e.g., 'aspect', 'pointcut', 'attribute'
        self.name = name
        self.brief = brief
        self.description = description if description is not None else []
        self.source_file = source_file # Original file name (e.g., core_aspect.ah)
        self.line_num = line_num # Starting line number of the comment

    def to_rst_section(self):
        """Generates a reStructuredText section for this doc entry."""
        rst_content = []

        src_index = self.source_file.find("src/")
        if src_index != -1:
            relative_path = "/" + self.source_file[src_index:]
        else:
            relative_path = self.source_file  # fallback if "src/" not found

        cleaned_path = relative_path.replace(".", "_")

        # Sphinx target for cross-referencing (unique name within the file)
        rst_content.append(f'.. _{cleaned_path}_{self.name}:\n\n')
        rst_content.append(f'{self.name} ({self.doc_type.capitalize()})\n')
        rst_content.append(f'{"-" * (len(self.name) + len(self.doc_type) + 3)}\n\n') # Sub-underline

        if self.brief:
            rst_content.append(f'**Brief Description:** {self.brief}\n\n')

        if self.description:
            rst_content.append('**Detailed Description:**\n\n')
            for line in self.description:
                if line.strip():
                    rst_content.append(f'    {line}\n')
            rst_content.append('\n')

        rst_content.append('\n') # Add a newline for separation between entries

        return "".join(rst_content)


def parse_comment_block(comment_lines_raw):
    """
    Parses a list of raw comment lines and extracts keywords and description.
    Handles both /** ... */ and /// styles.
    Returns a dictionary of parsed info.
    """
    doc_info = {
        'doc_type': 'Undocumented', # Default type
        'name': 'Unknown',          # Default name
        'brief': '',
        'description': [],
        'file_tag': '' # For \file
    }

    # Clean lines from comment markers first
    cleaned_lines = []
    for line in comment_lines_raw:
        line = line.strip()
        if line.startswith('*') and not line.startswith('*/'):
            cleaned_lines.append(line[1:].strip())
        elif line.startswith('///'):
            cleaned_lines.append(line[3:].strip())
        elif line.startswith('/**') or line.startswith('*/'): # Handle /** and */ lines themselves
            pass
        else:
            cleaned_lines.append(line) # Keep lines that are just part of the comment content (e.g., between stars)

    # Process cleaned lines
    keyword_name_extracted = False
    for line in cleaned_lines:
        if not line: # Skip empty lines
            continue

        # Try to extract the primary \keyword Name from the first relevant line
        if not keyword_name_extracted:
            # Regex to find \keyword Name (e.g., \aspect MyAspect)
            # It should capture the keyword itself and the name
            primary_match = re.match(r'\\([a-zA-Z_]+)\s+([A-Za-z0-9_:-]+)', line)
            if primary_match:
                doc_info['doc_type'] = primary_match.group(1).lower()
                doc_info['name'] = '``' + primary_match.group(2) + '``' # Format as code in RST
                keyword_name_extracted = True
                # The rest of this line could be part of the description or a brief if no \brief tag
                remaining_line = line[primary_match.end():].strip()
                if remaining_line and not remaining_line.startswith('\\'):
                     doc_info['description'].append(remaining_line)
                continue # Move to next line after extracting primary info

        # Process other Doxygen tags or general description
        match = re.match(r'\\([a-zA-Z_]+)\s*(.*)', line)
        if match:
            keyword = match.group(1).lower()
            value = match.group(2).strip()
            if keyword == 'brief':
                doc_info['brief'] = value
            elif keyword == 'file':
                doc_info['file_tag'] = value
            # Add more specific keyword handling if needed, otherwise it's just general description
        else:
            doc_info['description'].append(line)

    return doc_info

def extract_all_doc_entries_from_file(filepath):
    """
    Scans a single source file for all doc strings and extracts their content.
    Returns a list of DocEntry objects.
    """
    doc_entries = []

    with open(filepath, 'r', encoding='utf-8') as f:
        lines = f.readlines()

    current_comment_lines = []
    in_block_comment = False

    line_num = 0
    while line_num < len(lines):
        line = lines[line_num]
        stripped_line = line.strip()

        if not in_block_comment and stripped_line.startswith('/**'):
            in_block_comment = True
            current_comment_lines = [stripped_line]
            comment_start_line = line_num + 1
        elif in_block_comment and stripped_line.endswith('*/'):
            current_comment_lines.append(stripped_line)
            in_block_comment = False

            # End of block comment, parse it
            parsed_info = parse_comment_block(current_comment_lines)
            if parsed_info['name'] != 'Unknown': # Only add if a specific entity name was found
                doc_entries.append(DocEntry(
                    doc_type=parsed_info['doc_type'],
                    name=parsed_info['name'],
                    brief=parsed_info['brief'],
                    description=parsed_info['description'],
                    source_file=filepath,
                    line_num=comment_start_line
                ))
            current_comment_lines = [] # Reset for next comment
        elif in_block_comment:
            current_comment_lines.append(stripped_line)
        elif stripped_line.startswith('///'):
            # Collect all consecutive /// lines
            temp_line_num = line_num
            temp_comment_lines = []
            comment_start_line = line_num + 1
            while temp_line_num < len(lines) and lines[temp_line_num].strip().startswith('///'):
                temp_comment_lines.append(lines[temp_line_num].strip())
                temp_line_num += 1

            # Parse the collected /// block
            parsed_info = parse_comment_block(temp_comment_lines)
            if parsed_info['name'] != 'Unknown': # Only add if a specific entity name was found
                doc_entries.append(DocEntry(
                    doc_type=parsed_info['doc_type'],
                    name=parsed_info['name'],
                    brief=parsed_info['brief'],
                    description=parsed_info['description'],
                    source_file=filepath,
                    line_num=comment_start_line
                ))
            line_num = temp_line_num - 1 # Adjust line_num to continue after this block

        line_num += 1

    return doc_entries

def process_project_directory(root_dir, output_rst_dir):
    """
    Walks through the project directory, extracts all doc comments from each file,
    and generates a single RST file per source file.
    """
    supported_extensions = ('.ah', '.hh', '.h', '.cpp', '.cxx') # Added .h, .cpp, .cxx for broader support

    print(f"Scanning directory: {root_dir}")
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(supported_extensions):
                filepath = os.path.join(dirpath, filename)
                print(f"Processing file: {filepath}")

                doc_entries_in_file = extract_all_doc_entries_from_file(filepath)

                if doc_entries_in_file:
                    output_filename = os.path.basename(filepath).replace('.', '_') + '.rst'
                    output_filepath = os.path.join(output_rst_dir, output_filename)

                    # Separate aspect entries from other entries
                    aspect_entries = [e for e in doc_entries_in_file if e.doc_type == 'aspect']
                    other_entries = [e for e in doc_entries_in_file if e.doc_type != 'aspect']

                    # Sort entries for consistent output (optional, but good practice)
                    aspect_entries.sort(key=lambda x: x.name)
                    other_entries.sort(key=lambda x: x.name)

                    with open(output_filepath, 'w', encoding='utf-8') as f:
                        if aspect_entries:
                            # Use the first aspect as the main heading
                            main_aspect_entry = aspect_entries[0]
                            f.write(f'{main_aspect_entry.name} ({main_aspect_entry.doc_type.capitalize()})\n')
                            f.write(f'{"=" * (len(main_aspect_entry.name) + len(main_aspect_entry.doc_type) + 3)}\n\n')

                            if main_aspect_entry.brief:
                                f.write(f'**Brief Description:** {main_aspect_entry.brief}\n\n')

                            if main_aspect_entry.description:
                                f.write('**Detailed Description:**\n\n')
                                for line in main_aspect_entry.description:
                                    if line.strip():
                                        f.write(f'    {line}\n')
                                f.write('\n')

                            f.write('\n') # Add a newline for separation

                            # Write other aspect entries as subsections
                            for entry in aspect_entries[1:]: # Skip the first one as it's the main heading
                                f.write(entry.to_rst_section())
                        else:
                            # If no aspect entries, just write a general file heading
                            f.write(f'{os.path.basename(filepath)} Documentation\n')
                            f.write(f'{"=" * (len(os.path.basename(filepath)) + 13)}\n\n')
                            f.write(f'All documented entities found in ``{os.path.basename(filepath)}``:\n\n')

                        # Now write all other entries (pointcuts, attributes, etc.)
                        for entry in other_entries:
                            f.write(entry.to_rst_section())

                    print(f"Generated: {output_filepath} with {len(doc_entries_in_file)} entries.")
                else:
                    print(f"No doc comments found in {filepath}.")

    print("\nDocumentation generation complete.")

if __name__ == '__main__':
    # --- Configuration ---
    # The root directory of your project containing source files (.ah, .hh, etc.)
    PROJECT_ROOT_DIR = '../src' # As requested

    # The directory where the generated RST files will be stored.
    # This should be inside your Sphinx source directory (e.g., docs/source/generated_docs)
    OUTPUT_RST_DIR = 'generated_docs'

    os.makedirs(OUTPUT_RST_DIR, exist_ok=True)

    abs_project_root = os.path.abspath(PROJECT_ROOT_DIR)

    if not os.path.isdir(abs_project_root):
        print(f"Error: Project root directory '{abs_project_root}' not found. Please verify PROJECT_ROOT_DIR.")
    else:
        process_project_directory(abs_project_root, OUTPUT_RST_DIR)
