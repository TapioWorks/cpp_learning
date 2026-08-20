# Solitaire build with python
import random


def create_deck(card_suit, card_rank):
    deck = []
    for suit in card_suit:
        for rank in card_rank:
            card = rank + suit
            deck.append(card)
    return deck

def shuffle_deck(deck_to_shuffle):
    random.shuffle(deck_to_shuffle)
    return deck_to_shuffle

def draw_card(current_deck):
    if len(current_deck) > 0:
        drawn_card = current_deck.pop()
        return drawn_card
    else:
        print("Deck is empty and needs to be shuffled")
        return None

def create_tableau(raw_deck):
    tableau = [[], [], [], [], [], [], []]

    for i in range(7):
        for j in range(i + 1):
            card = raw_deck.pop(0)
            tableau[i].append(card)

    return tableau

def create_foundation():
    new_foundation = [[], [], [], []]
    return new_foundation


def move_card_to_pile(destination_pile, waste):
    card = waste.pop()
    destination_pile.append(card)

def move_pile_to_pile():
    print("STUB")

def move_card_to_foundation():
    print("STUB")

def move_foundation_to_pile():
    print("STUB")

def show_board(tableau, waste, stock, foundation):
    print("\n" + "-" * 30)

    if waste:
        print(f"Waste: {waste[-1]}")
    else:
        print("Waste: Empty")

    print(f"Stock: {len(stock)} card(s)")
    print()

    for i, pile in enumerate(tableau, start=1):
        if pile:
            print(f"Pile {i}: {pile[-1]} ({len(pile)} cards)")
        else:
            print(f"Pile {i}: Empty")
    print("-" * 30)
    for j, foundation_pile in enumerate(foundation, start=1):
        if foundation_pile:
            print(f"foundation {j}: {foundation_pile[-1]} ({len(foundation_pile)} cards)")
        else:
            print(f"foundation {j}: Empty")

    print("-" * 30)

ranks = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A"]
suits = ["♠", "♥", "♦", "♣"]

new_deck = (create_deck(suits, ranks))
shuffle_deck(new_deck)

tableau = create_tableau(new_deck)
foundation = create_foundation()
stock = new_deck

waste = []

print("Welcome to solitaire!")
while True:

    show_board(tableau, waste, stock, foundation)
    user_choice = input("What would you like to do?\n" \
    "Options: draw, move, quit (q): ")

    if user_choice == "q":
        break

    if user_choice == "draw":
        drawn_card = draw_card(stock)
        if drawn_card:
            waste.append(drawn_card)
    
    if user_choice == "move":
        move_choice = int(input("Where would you like to move?\n"
        "1) Waste to pile.\n"
        "2) Waste to foundation.\n"
        "3) Pile to pile.\n"
        "4) Pile to foundation.\n"
        "5) Foundation to pile.\n"
        "6) Cancel.\n"
        ": "))
        if move_choice == 1:
            if waste:
                pile_to_place = int(input("Select what pile you would like to move card: "))
                move_card_to_pile(tableau[pile_to_place - 1], waste)
            else:
                print("Nothing to move")
        elif move_choice == 2:
            print("stub")
        elif move_choice == 3:
            print("stub")
        elif move_choice == 4:
            print("stub")
        elif move_choice == 5:
            print("stub")
        else:
            print("stub quit")
            break
