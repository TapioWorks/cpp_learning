age = int(input("Enter age: "))

if age >= 18:
    print("You are of age")
elif age < 0:
    print("Please insert proper age")
elif age >= 110:
    print("You are too old for this")
else:
    print("You are underaged")