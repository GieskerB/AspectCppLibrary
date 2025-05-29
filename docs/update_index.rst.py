import os

# Definiere den Ordnerpfad
folder_path = 'generated_docs/'

# Pfad zur index.rst Datei
index_file = 'index.rst'

# Lade die aktuelle Liste der Dateien, die bereits in index.rst eingetragen sind
def load_existing_entries():
    if os.path.exists(index_file):
        with open(index_file, 'r') as f:
            # Entferne führende und nachfolgende Leerzeichen (inklusive Tabulatoren)
            return [line.strip() for line in f.readlines()]
    return []

# Füge neue Dateinamen hinzu, wenn sie noch nicht existieren
def update_index_file():
    # Lade die bereits eingetragenen Dateien (inklusive Tabs)
    existing_entries = load_existing_entries()

    # Sammle alle .rst Dateien im Ordner
    new_files = [f for f in os.listdir(folder_path) if f.endswith('.rst')]

    # Füge nur neue, noch nicht eingetragene Dateien hinzu
    new_entries = [os.path.join(folder_path, f) for f in new_files if os.path.join(folder_path, f) not in existing_entries]

    if new_entries:
        with open(index_file, 'a') as f:
            for entry in new_entries:
                # Füge vor jeder Zeile einen Tabulator hinzu
                f.write('    ' + entry + '\n')
        print(f"{len(new_entries)} neue Datei(en) wurden zu index.rst hinzugefügt.")
    else:
        print("Keine neuen Dateien zu index.rst hinzuzufügen.")

# Skript ausführen
update_index_file()
