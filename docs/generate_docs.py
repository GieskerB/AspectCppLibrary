import os
import re

class DocEntry:
    """Represents a single documented item (e.g., aspect, pointcut, attribute)."""
    def __init__(self, doc_type, name, brief="", description=None, source_file="", line_num=-1, see_also=None, file_tag="", params = [], returns = []):
        self.doc_type = doc_type
        self.name = name
        self.brief = brief
        self.description = description if description is not None else []
        self.source_file = source_file # Original file name (e.g., core_aspect.ah)
        self.line_num = line_num # Starting line number of the comment
        self.see_also = see_also if see_also is not None else [] # For \see, can be multiple entries
        self.params = params
        self.returns = returns
        self.file_tag = file_tag

    def _format_see_link(self, see_item_text):
        """
        Formats a \see item. If it looks like a Sphinx :ref: syntax,
        it passes it through. Otherwise, it treats it as plain text.
        """
        # Regex to check if the string already looks like a Sphinx :ref: role
        # Example: :ref:`Target Text <target_name>`
        if re.match(r'^:ref:`.*?<.*?>`$', see_item_text.strip()):
            return see_item_text.strip()
        else:
            # If it's not a :ref: role, just return it as plain text.
            # You might want to format it further, e.g., using ` `code`` markup
            # if you expect plain function names.
            return f'``{see_item_text.strip()}``'


    def to_rst_section(self):
        """Generates a reStructuredText section for this doc entry."""
        rst_content = []

        # Sphinx target for cross-referencing (unique name within the file)
        # Ensure name doesn't contain problematic characters for Sphinx targets
        cleaned_name_for_target = re.sub(r'[^a-zA-Z0-9_.-]', '', self.name.strip('`'))
        rst_content.append(f'.. _{os.path.basename(self.source_file).replace(".", "_")}_{cleaned_name_for_target}:\n\n')

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

        # Add \param information
        if self.params:
            rst_content.append('**Parameters:**\n\n')
            for param_name, param_desc in self.params:
                rst_content.append(f'    * ``{param_name}``: {param_desc}\n')
            rst_content.append('\n')

        # Add \return information
        if self.returns:
            rst_content.append('**Returns:**\n\n')
            for return_desc in self.returns:
                # If the description spans multiple lines, ensure proper indentation
                return_lines = return_desc.splitlines()
                rst_content.append(f'    * {return_lines[0]}\n')
                for rl in return_lines[1:]: rst_content.append(f'      {rl}\n') # Indent subsequent lines
            rst_content.append('\n')

        # Add \file information if present
        if self.file_tag:
            rst_content.append(f'*In file* ``{self.file_tag}``\n')

        # Add \see information if present
        if self.see_also:
            rst_content.append('\n*See:* ')
            formatted_links = []
            for item in self.see_also:
                formatted_links.append(self._format_see_link(item))
            rst_content.append(', '.join(formatted_links)) # Join with comma for multiple links
            rst_content.append('\n')
        rst_content.append('\n') # Add a newline for separation between entries

        return "".join(rst_content)


def parse_comment_block(comment_lines_raw):
    """
    Parses a list of raw comment lines and extracts keywords and description.
    Handles /** ... */ styles.
    Returns a dictionary of parsed info.
    """
    doc_info = {
        'doc_type': 'Undocumented', # Default type
        'name': 'Unknown',          # Default name
        'brief': '',
        'description': [],
        'file_tag': '', # For \file
        'see_also': [],  # For \see
        'params': [],    # New: For \param
        'returns': []    # New: For \return
    }

    # Clean lines from comment markers first
    cleaned_lines = []
    for line in comment_lines_raw:
        line = line.strip()
        if line.startswith('*') and not line.startswith('*/'): # Only for /** block, remove leading '*'
            cleaned_lines.append(line[1:].strip())
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
            # Updated regex to allow more characters in name (e.g., ::, [], -)
            primary_match = re.match(r'\\([a-zA-Z_]+)\s+([A-Za-z0-9_:\[\]\-.]+)', line)
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
            elif keyword == 'see': # Handle \see keyword
                doc_info['see_also'].append(value)
            elif keyword == 'param': # Handle \param keyword
                param_match = re.match(r'(\S+)\s*(.*)', value)
                if param_match:
                    doc_info['params'].append((param_match.group(1), param_match.group(2).strip()))
            elif keyword == 'return': # Handle \return keyword
                doc_info['returns'].append(value)
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
                    line_num=comment_start_line,
                    see_also=parsed_info['see_also'], # Pass see_also
                    file_tag=parsed_info['file_tag'],  # Pass file_tag
                    params=parsed_info['params'],      # New: Pass params
                    returns=parsed_info['returns']     # New: Pass returns
                ))
            current_comment_lines = [] # Reset for next comment
        elif in_block_comment:
            current_comment_lines.append(stripped_line)

        line_num += 1

    return doc_entries

def process_project_directory(root_dir, output_rst_dir):
    """
    Walks through the project directory, extracts all doc comments from each file,
    and generates a single RST file per source file.
    """
    supported_extensions = ('.ah', '.hh', '.cc', '.h', '.cpp', '.cxx') # Ensure all are supported

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

                    main_entities = [e for e in doc_entries_in_file if e.doc_type in ['aspect', 'class', 'interface', 'exception','collection']]
                    other_entries = [e for e in doc_entries_in_file if e.doc_type not in ['aspect', 'class', 'interface', 'exception','collection']]

                    # Sort entries for consistent output
                    main_entities.sort(key=lambda x: x.name)
                    other_entries.sort(key=lambda x: x.name)

                    with open(output_filepath, 'w', encoding='utf-8') as f:
                        if main_entities:
                            # Use the first main entity (aspect, class, or interface) as the primary heading
                            main_heading_entity = main_entities[0]
                            f.write(f'{main_heading_entity.name}\n')
                            f.write(f'{"=" * (len(main_heading_entity.name) + len(main_heading_entity.doc_type) + 3)}\n')
                            f.write(f'..\n\t({main_heading_entity.doc_type.capitalize()})\n\n')

                            if main_heading_entity.brief:
                                f.write(f'**Brief Description:** {main_heading_entity.brief}\n\n')

                            if main_heading_entity.description:
                                f.write('**Detailed Description:**\n\n')
                                for line in main_heading_entity.description:
                                    if line.strip():
                                        f.write(f'    {line}\n')
                                f.write('\n')

                            # Add \param information for main entity
                            if main_heading_entity.params:
                                f.write('**Parameters:**\n\n')
                                for param_name, param_desc in main_heading_entity.params:
                                    f.write(f'    * ``{param_name}``: {param_desc}\n')
                                f.write('\n')

                            # Add \return information for main entity
                            if main_heading_entity.returns:
                                f.write('**Returns:**\n\n')
                                for return_desc in main_heading_entity.returns:
                                    return_lines = return_desc.splitlines()
                                    f.write(f'    * {return_lines[0]}\n')
                                    for rl in return_lines[1:]: f.write(f'      {rl}\n')
                                f.write('\n')

                            # Source File and Line Number for the main heading entity
                            if main_heading_entity.file_tag:
                                f.write(f'*In file* ``{main_heading_entity.file_tag}``\n')
                            if main_heading_entity.see_also:
                                f.write('\n*See:* ')
                                formatted_links = []
                                for item in main_heading_entity.see_also:
                                    formatted_links.append(main_heading_entity._format_see_link(item))
                                f.write(', '.join(formatted_links))
                                f.write('\n')
                            f.write('\n')

                            # Write other main entities as subsections (e.g., if a file has multiple aspects/classes)
                            for entry in main_entities[1:]:
                                f.write(entry.to_rst_section())
                        else:
                            # If no 'main' entities, use the filename as the primary heading
                            f.write(f'{os.path.basename(filepath)} Documentation\n')
                            f.write(f'{"=" * (len(os.path.basename(filepath)) + 13)}\n\n')
                            f.write(f'All documented entities found in ``{os.path.basename(filepath)}``:\n\n')

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
    OUTPUT_RST_DIR = 'generated_docs' # Changed from 'docs/source/generated_docs' to 'generated_docs'
                                    # assuming this script is run from 'docs/source/' or 'docs/'
                                    # If run from 'docs/', it should be 'docs/source/generated_docs'

    # Make sure the output directory exists
    os.makedirs(OUTPUT_RST_DIR, exist_ok=True)

    abs_project_root = os.path.abspath(PROJECT_ROOT_DIR)

    if not os.path.isdir(abs_project_root):
        print(f"Error: Project root directory '{abs_project_root}' not found. Please verify PROJECT_ROOT_DIR.")
    else:
        process_project_directory(abs_project_root, OUTPUT_RST_DIR)
