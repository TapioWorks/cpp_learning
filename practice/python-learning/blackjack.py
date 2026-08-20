import random


cards = ["2", "3", "4", "5", "6", "7", "8", "9", "10", "J", "Q", "K", "A",]
suites = ["♠️", "♦️", "♥️", "♣️"]
is_running = True


def create_deck(suits, cards):
    deck = []
    for suit in suites:
        for card in cards:
            complete_card = suit + card
            deck.append(complete_card)
    return deck

def hit_card(deck, hand):
    new_card = deck.pop()
    hand.append(new_card)
    return new_card

def calculate_hand_value(hand):
    total = 0

    for card in hand:
        for suit in suites:
            card = card.replace(suit, "")

        if card in ["J", "Q", "K"]:
            total += 10
        elif card == "A":
            total += 11
        else:
            total += int(card)

    return total

def stand():
    pass

def deal_hand(deck):
    hand = []
    for x in range(2):
        card = deck.pop()
        hand.append(card)
    return hand


def welcome_text_and_rules():
    print("=" * 50)
    print("         WELCOME TO BLACKJACK")
    print("=" * 50)
    print("\nRules:")
    print("- The goal is to get as close to 21 as possible without going over.")
    print("- Number cards (2-10) are worth their face value.")
    print("- J, Q, and K are each worth 10 points.")
    print("- An Ace (A) is worth either 11 or 1, whichever is better for your hand.")
    print("- You and the dealer each start with two cards.")
    print("- One of the dealer's cards is hidden until your turn ends.")
    print("- On your turn you can:")
    print("    H - Hit (take another card)")
    print("    S - Stand (keep your current hand)")
    print("- If your total goes over 21, you bust and lose immediately.")
    print("- After you stand, the dealer reveals their hidden card.")
    print("- The dealer must keep drawing cards until they have at least 17.")
    print("- Whoever is closest to 21 without busting wins.")
    print("- If both hands have the same value, the game is a tie (Push).")
    print("=" * 50)

def main():

    welcome_text_and_rules()
    deck = create_deck(suites, cards)
    random.shuffle(deck)
    players_hand = deal_hand(deck)
    dealers_hand = deal_hand(deck)

    while is_running:
        player_hand_value = calculate_hand_value(players_hand)
        dealer_hand_value = calculate_hand_value(dealers_hand)
        print(f"Your hand: {players_hand} ({player_hand_value})")
        print(f"Dealer: {dealers_hand} ({dealer_hand_value})")
        choice = input("Would you like to hit (H) or stand (S): ").upper()

        if len(choice) != 1 or not choice.isalpha():
            print("Invalid input")
            continue

        if choice == "H":
            hit_card(deck, players_hand)
            if calculate_hand_value(players_hand) > 21:
                print(f"Your final hand total was: {player_hand_value}")
                print("BUST YOU LOSE")
        else:
            while dealer_hand_value < 17:
                hit_card(deck, dealers_hand)
                dealer_hand_value = calculate_hand_value(dealers_hand)

        if dealer_hand_value > 21:
            print("DEALER BUSTED")
        elif dealer_hand_value > player_hand_value:
            print("DEALDER WINS")
        else:
            print("PLAYER WINS")

        play_again = input("Would you like to play again? (Y/N): ").upper()

        if play_again == "N":
            break
        else:
            players_hand.clear()
            dealers_hand.clear()


if __name__ == "__main__":
    main()