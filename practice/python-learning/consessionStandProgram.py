# Consession stand program

menu = {"Hotdog": 3.50,
        "Hämburger": 4.59,
        "Pizza": 1.29,
        "Popcorn": 3.59,
        "Nachos": 1.56,
        "Soda": 2.34,
        "Lemonade": 1.23}

cart = []
total = 0
print("---------- MENU ----------")
for key, value in menu.items():
    print(f"{key:10}: €{value}")
print("--------------------------")

while True:
    food = input("What food would you like to buy (q to quit): ")
    if food == "q":
        break

    if food not in menu:
        print("Item not in menu.")
        continue

    cart.append(food)
    total += menu.get(food)

print("---------- YOUR ORDER -----------")
for item in cart:
    print(item, end=" ")
print()
print(f"Total: €{total:.2f}")