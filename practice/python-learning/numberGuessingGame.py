import random

attempts = 1

print("Welcome to a number guessing game")
difficulty = input("What difficulty would you like?\n" \
"Easy: 1 - 50\n" \
"Medium 1 - 100\n" \
"Hard 1 - 500\n" \
"Select by typing Easy, Medium or Hard: ")

while difficulty not in ('Easy', 'Medium', 'Hard'):
    difficulty = input("Please select by typing Easy, Medium or Hard: ")

if difficulty == "Easy":
    difficulty_number = 50

elif difficulty == "Medium":
    difficulty_number = 100

else:
    difficulty_number = 500

magic_number = random.randint(1, difficulty_number)

user_number = int(input(f"Please give a whole number between 1 - {difficulty_number}: "))

while magic_number != user_number:
    if user_number < magic_number:
        print("Too low")
    else:
        print("Too high")
    print(f"Current attemps {attempts}")
    attempts += 1
    user_number = int(input(f"Please try again by giving a whole number between 1 - {difficulty_number}: "))

print("You made it out!")
print(f"it took you {attempts} attemps to guess right")

if attempts <= 5:
    print("“Insane 🔥")
elif attempts <= 11:
    print("Pretty good 👍")
else:
    print("You got it… eventually 😅")