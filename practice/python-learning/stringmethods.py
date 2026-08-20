name = input("Enter you full name: ")

phone_number = input("Please give me you phonenumner: ")

whitespaces = name.find(" ")
result = len(name)
new_name = name.capitalize()
upper_name = name.upper()

print(result)
print(whitespaces)
print(new_name)


has_dashes = phone_number.count("-")
print(has_dashes)

has_only_numbers = phone_number.isdigit()
print(has_only_numbers)

no_dashes = phone_number.replace("-", "")
print(no_dashes)