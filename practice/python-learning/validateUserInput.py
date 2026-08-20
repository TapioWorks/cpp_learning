username = input("Please give a username\n" \
"Username cannot be more than 12 characters\n" \
"Username cannot contain spaces\n" \
"Username must not contain digits\n")

if len(username) > 12:
    print("User name must not contain more than 12 characters")
elif not username.find(" ") == -1:
    print("Username cannot contain any spaces")
elif not username.isalpha:
    print("Username cannot contain any digits")
else:
    print(f"Welcome {username}")