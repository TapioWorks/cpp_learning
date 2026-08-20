
userpassword = input("Please give a password to check that if is strong or weak: ")

if len(userpassword) <= 8:
    print("This makes a password weak")

uppercase = 0
lowercase = 0
digit = 0

for character in userpassword:
    if character.isupper():
        uppercase += 1
    elif character.islower():
        lowercase += 1
    elif character.isdigit():
        digit += 1
    else:
        print("Ok something went wrong")

print(f"your password had {uppercase} letter(s)")
print(f"your password had {lowercase} letter(s)")
print(f"your password had {digit} digits(s)")