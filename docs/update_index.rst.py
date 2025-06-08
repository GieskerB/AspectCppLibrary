import os
import re

# Define folder paths
GENERATED_DOCS_PATH = 'generated_docs/'
SPHINX_SOURCE_PATH = '.' # Assuming this script runs in the same directory as index

# Define category files and their headings
CATEGORY_FILES = {
    'aspect': {'filename': 'aspects.rst', 'title': 'Aspects'},
    'class': {'filename': 'classes.rst', 'title': 'Classes'},
    'interface': {'filename': 'interfaces.rst', 'title': 'Interfaces'},
    'exception': {'filename': 'exceptions.rst', 'title': 'Exceptions'},
    # Add other categories if needed, e.g., 'enum', 'struct', 'function'
    'other': {'filename': 'others.rst', 'title': 'Other Entities'} # Catch-all for anything not explicitly categorized
}

def categorize_rst_file(filepath):
    """
    Reads the content of a generated RST file to determine its primary type
    (Aspect, Class, Interface, Exception).
    """
    try:
        with open(filepath, 'r', encoding='utf-8') as f:
            # Read first few lines to find the main heading
            for i, line in enumerate(f):
                if i > 5: # Don't read too many lines, heading should be near the top
                    break
                # Look for patterns like "Name (Type)"
                match = re.search(r'\((Aspect|Class|Interface|Exception|Enum|Struct|Function)\)', line, re.IGNORECASE)
                if match:
                    # Return the lowercased type
                    return match.group(1).lower()
    except Exception as e:
        print(f"Error reading {filepath}: {e}")
    return 'other' # Default if type cannot be identified

def update_category_rst_files():
    """
    Scans generated_docs, categorizes files, and updates category-specific RST files.
    """
    print(f"Scanning {GENERATED_DOCS_PATH} for generated documentation files...")

    # Dictionary to hold lists of files per category
    categorized_files = {category: [] for category in CATEGORY_FILES.keys()}

    # Collect all .rst files from generated_docs
    generated_rst_files = [
        f for f in os.listdir(GENERATED_DOCS_PATH)
        if f.endswith('.rst')
    ]

    if not generated_rst_files:
        print(f"No .rst files found in {GENERATED_DOCS_PATH}. Nothing to categorize.")
        return

    for filename in generated_rst_files:
        filepath = os.path.join(GENERATED_DOCS_PATH, filename)
        category = categorize_rst_file(filepath)
        if category in categorized_files:
            categorized_files[category].append(filepath)
        else:
            categorized_files['other'].append(filepath) # Fallback to 'other' if new category is found

    print("Updating category RST files...")
    for category_name, category_info in CATEGORY_FILES.items():
        output_filename = category_info['filename']
        output_title = category_info['title']
        files_for_category = sorted(categorized_files.get(category_name, [])) # Sort for consistent order

        full_output_path = os.path.join(SPHINX_SOURCE_PATH, output_filename)

        with open(full_output_path, 'w', encoding='utf-8') as f:
            f.write(f'{output_title}\n')
            f.write(f'{"=" * len(output_title)}\n\n') # Underline for section title
            f.write('.. toctree::\n')
            f.write('   :maxdepth: 2\n\n')

            if files_for_category:
                for filepath_in_category in files_for_category:
                    # Path must be relative to the category .rst file, which is in SPHINX_SOURCE_PATH
                    # So, if file is generated_docs/my_aspect.rst, just write that directly.
                    f.write(f'   {filepath_in_category}\n')
                print(f"  - Wrote {len(files_for_category)} entries to {output_filename}")
            else:
                f.write('   *No entries found for this category.*\n')
                print(f"  - No entries for {category_name}, {output_filename} created empty.")

    print("\nCategory RST files updated. Remember to include them in your index toctree.")

# --- Main execution ---
if __name__ == '__main__':
    # Ensure generated_docs directory exists
    if not os.path.isdir(GENERATED_DOCS_PATH):
        print(f"Error: Directory '{GENERATED_DOCS_PATH}' not found. Please run your documentation generator first.")
    else:
        update_category_rst_files()

    # # --- Instructions for index ---
    # print("\n--- Next Steps ---")
    # print(f"1. Open '{os.path.join(SPHINX_SOURCE_PATH, 'index')}'")
    # print("2. Remove all direct inclusions of files from 'generated_docs/'.")
    # print("3. Add the following lines to your main 'toctree' in index:")
    # for category_info in CATEGORY_FILES.values():
    #     print(f"   {category_info['filename']}")
    # print("\nExample index structure:")
    # print("```rst")
    # print("Welcome to My Docs!")
    # print("===================\n")
    # print(".. toctree::")
    # print("   :maxdepth: 2")
    # print("   :caption: Contents:\n")
    # print("   # Your other top-level files like introduction.rst")
    # for category_info in CATEGORY_FILES.values():
    #     print(f"   {category_info['filename']}")
    # print("```")
