operator = input("Please select and operator to use (+, -, * or /): ")

if operator not in ('+', '-', '*', '/'):
    print(f"{operator} is an invalid operator")

first_number = float(input("Please give a number: "))
second_number = float(input("Please give a second number: "))

if operator == "+":
    print(first_number + second_number)
elif operator == "-":
    print(first_number - second_number)
elif operator == "*":
    print(first_number * second_number)
elif operator == "/":
    print(first_number / second_number)
else:
    print("Something must have gone very wrong")