# Python banking program


def show_balance(current_balance):
    print(f"Your current balance is: {current_balance:.2f}€")

def deposit():
    money = float(input("How much would you like to deposit (€): "))

    if money > 0:
        return money
    else:
        print("That is not a valid input.")
        return 0

def withdraw(balance):
    amount = float(input("How much would you like to withdraw (€): "))

    if amount > balance:
        print("Insufficient funds")
        return 0
    elif amount < 0:
        print("Amount must be greater than 0")
        return 0
    else:
        return amount

def main():
    balance = 0
    is_running = True

    while is_running:
        print("Banking Program")
        print("1. Show Balance")
        print("2. Deposit")
        print("3. Withdraw")
        print("4. Exit")

        choice = int(input("Enter your choice (1-4): "))

        if choice == 1:
            show_balance(balance)
        elif choice == 2:
            balance += deposit(balance)
        elif choice == 3:
            balance -= withdraw(balance)
        elif choice == 4:
            is_running = False
        else:
            print("That is not a valid choice.")

    print("Goodbye, we hope to see you again")

if __name__ == '__main__':
    main()