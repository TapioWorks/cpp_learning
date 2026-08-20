weight = float(input("Enter your weight: "))
unit = input("Kilograms or pounds? (kg or lbs)")

if unit == "kg":
    weight = weight * 2.205
    unit = "Lbs"
    print(f"Your weight is {round(weight, 2)}{unit}")
elif unit == "lbs":
    weight == weight / 2.205
    unit = "Kg"
    print(f"Your weight is {round(weight, 2)}{unit}")
else:
    print(f"{unit} is not a valid operator")
