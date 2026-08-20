import json

file_path = "C:/Users/Teemu/Desktop/input.txt"
file_path_2 = "output.json"

try:
    with open(file_path_2, "r") as file:
        content = json.load(file)
        print(content)
except FileNotFoundError:
    print("That file was not found")