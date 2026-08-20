import random

options = ("Rock", "Paper", "Scissors")
computer = random.choice(options)
running = True

while running:

    player = input("Enter you choice (Rock, Paper, Scissors): ")

    while player not in options:
        print(f"Option: {player} was not in the listed options.")
        player = input("Please select (Rock, Paper, Scissors): ")

    print(f"Player: {player}")
    print(f"Computer: {computer}")

    if player == computer:
        print("Its a tie")
    elif player == "Rock" and computer == "Scissors":
        print("Player wins!")
    elif player == "Paper" and computer == "Rock":
        print("Player wins!")
    elif player == "Scissors" and computer == "Paper":
        print("Player wins!")
    else:
        print("You Lose")

    if not input("Play again? (y/n)").lower() == "y":
        running = False

print("Thanks for playing")