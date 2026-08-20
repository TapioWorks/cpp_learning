name = input("Enter your name: ")

while name == "":
    print("You did not enter your name")
    name = input("Enter your name: ")
else:
    print(f"Hello {name}")


age = int(input("Enter your age: "))

while age < 0:
    print("Age cannot be a negative number")
    age = int(input("Enter your age: "))

print(f"you are {age} years old")

food = input("Enter a food you like (q to quit): ")

while not food == "q":
    print(f"You like {food}")
    food = input("Enter another food you like (q to quit): ")

print("Bye")


num = int(input("Enter a number between 1 - 10: "))

while num < 1 or num > 10:
    print(f"{num} is not valid")
    num = int(input("Enter a number between 1 - 10: "))

print(f"{num} is valid")
