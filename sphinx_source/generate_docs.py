import os
import re

class DocEntry:
    def __init__(self, doc_type, name, brief="", description=None, source_file="", see_also=None, file_tag="", params = [], returns = []):
        self.doc_type = doc_type
        self.name = name
        self.brief = brief
        self.description = description or []
        self.source_file = source_file
        self.see_also = see_also or []
        self.params = params
        self.returns = returns
        self.file_tag = file_tag

    def _format_see_link(self, see_item_text):
        if re.match(r'^:ref:`.*?<.*?>`$', see_item_text.strip()):
            return see_item_text.strip()
        return f'``{see_item_text.strip()}``'

    def to_rst_section(self):
        cleaned_name = re.sub(r'[^a-zA-Z0-9_.-]', '', self.name.strip('`'))
        rst_content = [
            f'.. _{os.path.basename(self.source_file).replace(".", "_")}_{cleaned_name}:\n\n',
            f'{self.name} ({self.doc_type.capitalize()})\n',
            f'{"-" * (len(self.name) + len(self.doc_type) + 3)}\n\n'
        ]

        if self.brief:
            rst_content.append(f'**Brief Description:** {self.brief}\n\n')

        if self.description and any(line.strip() for line in self.description):
            rst_content.extend(['**Detailed Description:**\n\n'] + [f'    {line}\n' for line in self.description if line.strip()])
            rst_content.append('\n')

        if self.params:
            rst_content.extend(['**Parameters:**\n\n'] + [f'    * ``{name}``: {desc}\n' for name, desc in self.params])
            rst_content.append('\n')

        if self.returns:
            rst_content.extend(['**Returns:**\n\n'] + [f'    * {rl}\n' for rl in self.returns])
            rst_content.append('\n')

        if self.file_tag:
            rst_content.append(f'*In file* ``{self.file_tag}``\n')

        if self.see_also:
            formatted_links = [self._format_see_link(item) for item in self.see_also]
            rst_content.append(f'\n*See:* {", ".join(formatted_links)}\n')

        rst_content.append('\n')
        return "".join(rst_content)

def parse_comment_block(comment_lines_raw):
    doc_info = {
        'doc_type': 'undocumented', 'name': 'Unknown', 'brief': '', 'description': [],
        'file_tag': '', 'see_also': [], 'params': [], 'returns': []
    }

    cleaned_lines = [line[1:].strip() for line in comment_lines_raw if line.strip() and not line.strip().startswith(('/**', '*/'))]

    keyword_name_extracted = False
    for line in cleaned_lines:
        if not keyword_name_extracted:
            primary_match = re.match(r'\\([a-zA-Z_]+)\s+([A-Za-z0-9_:\[\]\-.]+)', line)
            if primary_match:
                doc_info['doc_type'] = primary_match.group(1).lower()
                doc_info['name'] = f'``{primary_match.group(2)}``'
                keyword_name_extracted = True
                remaining_line = line[primary_match.end():].strip()
                if remaining_line and not remaining_line.startswith('\\'):
                     doc_info['description'].append(remaining_line)
                continue

        match = re.match(r'\\([a-zA-Z_]+)\s*(.*)', line)
        if match:
            keyword, value = match.group(1).lower(), match.group(2).strip()
            if keyword == 'brief': doc_info['brief'] = value
            elif keyword == 'file': doc_info['file_tag'] = value
            elif keyword == 'see': doc_info['see_also'].append(value)
            elif keyword == 'param':
                param_match = re.match(r'(\S+)\s*(.*)', value)
                if param_match: doc_info['params'].append((param_match.group(1), param_match.group(2).strip()))
            elif keyword == 'return': doc_info['returns'].append(value)
        else:
            doc_info['description'].append(line)

    return doc_info

def extract_all_doc_entries_from_file(filepath):
    doc_entries, in_block_comment, current_comment_lines = [], False, []
    with open(filepath, 'r', encoding='utf-8') as f:
        for line in f.readlines():
            stripped_line = line.strip()
            if not in_block_comment and stripped_line.startswith('/**'):
                in_block_comment = True
                current_comment_lines = [stripped_line]
            elif in_block_comment and stripped_line.endswith('*/'):
                current_comment_lines.append(stripped_line)
                in_block_comment = False
                parsed_info = parse_comment_block(current_comment_lines)
                if parsed_info['name'] != 'Unknown':
                    doc_entries.append(DocEntry(source_file=filepath, **parsed_info))
                current_comment_lines = []
            elif in_block_comment:
                current_comment_lines.append(stripped_line)
    return doc_entries

def process_project_directory(root_dir, output_rst_dir):
    supported_extensions = ('.ah', '.hh', '.cc', '.h', '.cpp', '.cxx')
    print(f"Scanning directory: {root_dir}")
    for dirpath, _, filenames in os.walk(root_dir):
        for filename in filenames:
            if filename.endswith(supported_extensions):
                filepath = os.path.join(dirpath, filename)
                print(f"Processing file: {filepath}")
                doc_entries = extract_all_doc_entries_from_file(filepath)

                if doc_entries:
                    output_basename = os.path.basename(filepath).replace('.', '_')
                    output_doc_path = os.path.join(output_rst_dir, f'{output_basename}.rst')
                    output_src_path = os.path.join(output_rst_dir, f'{output_basename}_src.rst')

                    main_entities = sorted([e for e in doc_entries if e.doc_type in ['aspect', 'class', 'interface', 'exception','collection']], key=lambda x: x.name)
                    other_entries = sorted([e for e in doc_entries if e not in main_entities], key=lambda x: x.name)

                    with open(output_doc_path, 'w', encoding='utf-8') as f:
                        if main_entities:
                            main_heading_entity = main_entities[0]
                            f.write(f'{main_heading_entity.name}\n')
                            f.write(f'{"=" * (len(main_heading_entity.name) + len(main_heading_entity.doc_type) + 3)}\n')
                            f.write(f'..\n\t({main_heading_entity.doc_type.capitalize()})\n\n')
                            f.write(f':doc:`Click here to see the source code <{output_basename}_src>`\n\n')
                            if main_heading_entity.brief:
                                f.write(f'**Brief Description:** {main_heading_entity.brief}\n\n')
                            if main_heading_entity.description and any(line.strip() for line in main_heading_entity.description):
                                f.write('**Detailed Description:**\n\n' + ''.join([f'    {line}\n' for line in main_heading_entity.description if line.strip()]))
                                f.write('\n')
                            if main_heading_entity.params:
                                f.write('**Parameters:**\n\n' + ''.join([f'    * ``{name}``: {desc}\n' for name, desc in main_heading_entity.params]))
                                f.write('\n')
                            if main_heading_entity.returns:
                                f.write('**Returns:**\n\n' + ''.join([f'    * {line}\n' for line in main_heading_entity.returns]))
                                f.write('\n')
                            if main_heading_entity.file_tag:
                                f.write(f'*In file* ``{main_heading_entity.file_tag}``\n')
                            if main_heading_entity.see_also:
                                formatted_links = [main_heading_entity._format_see_link(item) for item in main_heading_entity.see_also]
                                f.write(f'\n*See:* {", ".join(formatted_links)}\n')
                            f.write('\n')
                            for entry in main_entities[1:]:
                                f.write(entry.to_rst_section())
                        else:
                            f.write(f'{os.path.basename(filepath)} Documentation\n')
                            f.write(f'{"=" * (len(os.path.basename(filepath)) + 13)}\n\n')
                            f.write(f'All documented entities found in ``{os.path.basename(filepath)}``:\n\n')
                            f.write(f':doc:`Click here to see the source code <{output_basename}_src>`\n\n')

                        for entry in other_entries:
                            f.write(entry.to_rst_section())
                    print(f"Generated: {output_doc_path} with {len(doc_entries)} entries.")

                    language = {'ah': 'cpp', 'hh': 'cpp', 'cc': 'cpp'}.get(os.path.splitext(filepath)[1][1:], 'text')
                    with open(output_src_path, 'w', encoding='utf-8') as f:
                        f.write(f'{os.path.basename(filepath)} source code\n')
                        f.write(f'{"-" * (len(os.path.basename(filepath)) + 12)}\n\n')
                        f.write(f'.. literalinclude:: {os.path.relpath(filepath, output_rst_dir)}\n')
                        f.write(f'   :language: {language}\n   :linenos:\n')
                    print(f"Generated source file: {output_src_path}")
                else:
                    print(f"No doc comments found in {filepath}.")
    print("\nDocumentation generation complete.")

if __name__ == '__main__':
    PROJECT_ROOT_DIR = '../src'
    OUTPUT_RST_DIR = 'generated_docs'
    os.makedirs(OUTPUT_RST_DIR, exist_ok=True)
    abs_project_root = os.path.abspath(PROJECT_ROOT_DIR)
    if not os.path.isdir(abs_project_root):
        print(f"Error: Project root directory '{abs_project_root}' not found. Please verify PROJECT_ROOT_DIR.")
    else:
        process_project_directory(abs_project_root, OUTPUT_RST_DIR)
