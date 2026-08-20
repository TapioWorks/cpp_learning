contacts = {}
print("Mini Phonebook")

print("1. Add Contact\n" \
"2. Find Contact\n" \
"3. Show all Contacts\n" \
"4. Exit\n")

user_choice = int(input("Give one of the numbers above: "))

while user_choice != 4:
    if user_choice == 1:
        name = input("Give name: ")
        phonenumber = input("Give a phonenumber: ")
        contacts.update({name:phonenumber})

    elif user_choice == 2:
        name_to_look_for = input("Please give name to search for: ")
        asked_name = contacts.get(name_to_look_for)
        print(f"Phone number is: {asked_name}" if name_to_look_for in contacts else "Name not found")

    elif user_choice == 3:
        for thing in contacts:
            print(thing, contacts[thing])
    
    else:
        print("Invalid choice.")

    print("1. Add Contact\n" \
        "2. Find Contact\n" \
        "3. Show all Contacts\n" \
        "4. Exit\n")
    user_choice = int(input("Give one of the numbers above: "))