
import json

employee = {
    "name": "Spongebob",
    "age": 30,
    "job": "cook"
}

file_path = "output.json"
try:
    with open(file_path, "w") as file:
        json.dump(employee, file, indent=4)
        print(f"Json file {file_path} was created")
except FileExistsError:
    print("This file already exists")