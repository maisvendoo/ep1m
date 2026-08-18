import os

directory = "TED/"

files = os.listdir(directory)

for file in files:
    new_file = file.replace(' ', '_')
    print(new_file)
    os.rename(directory + file, directory + new_file)