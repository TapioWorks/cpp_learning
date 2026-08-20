from script1 import favorite_food

def favorite_drink(drink):
    print(f"Your favorite drink is {drink}")

def main():
    print("This is script 2")
    favorite_food("Sushi")
    favorite_drink("Coffee")
    print("Goodbyw")

if __name__ == '__main__':
    main()