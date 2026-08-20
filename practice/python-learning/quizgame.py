# Python quiz game

questions = ("How many champions are there in league of legends?: ",
             "What is the subtitle of the character Jhin: ",
             "What is chemical symbol for gold in the periodic table of elemets: ",
             "How many moons does venus have?: ",
             "What is objectively the best food?: ")

options = (("A. 116", "B. 152", "C. 164", "D. 142",),
           ("A. The virtuoso", "B. The artist", "C. The deadly flourish", "D. The mage killer"),
           ("A. C", "B. H", "C. AU", "D. BE"),
           ("A. None", "B. 3", "C. 7", "D. 8"),
           ("A. Pizza", "B. Hamburger", "C. Pasta", "D. Candy"))

answers = ("B", "A", "C", "C", "A")

guesses = []
score = 0
question_num = 0

for question in questions:
    print("----------------------")
    print(question)
    for option in options[question_num]:
        print(option)
    guess = input("Enter (A, B, C or D): ").upper()
    if guess == answers[question_num]:
        score += 1
        print("CORRECT")
    else:
        print("INCORRECT")
        print(f"The correct answer was {answers[question_num]}")
    question_num += 1

print("----------------------")
print(        "RESULT        ")
print("----------------------")

print("Answers : ", end="")

for answer in answers:
    print(answer, end=" ")
print()

print("Guesses : ", end="")

for guess in guesses:
    print(guess, end=" ")
print()