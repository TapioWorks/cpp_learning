# *args == allows you to pass multiple non-key arguments
# **kwargs == allows you to pass multiple keyword-arguments
# * this is an unpacking operator

def add(*args):
    total = 0
    for arg in args:
        total += arg
    return total


def display_name(*args):
    for arg in args:
        print(arg, end=" ")

def print_adress(**kwargs):
    for value, key in kwargs.items():
        print(f"{value}: {key}")

def shipping_label(*args, **kwargs):
    for arg in args:
        print(arg, end=" ")
    print()
    print(f"{kwargs.get('street')}, {kwargs.get('appartment')}")
    print(f"{kwargs.get('city')}, {kwargs.get('zip')}")

#display_name("Spongebob", "Squarepants", "King", "of")

#print(add(1))

#print_adress(street="123 fake street", city="oklahoma", state="MI", zip="54321")

shipping_label("Dr.", "Spongebob", "Squarepants", "III",
               street="123 bikini bottom",
               poboc="pobox #100",
               city="Detroit",
               state="LA",
               zip="54321")