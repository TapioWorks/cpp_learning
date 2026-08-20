
class Dog:
    def __init__(self, name, age):
        self.name = name
        self.age = age

    def bark(self):
        print(f"Woof! My name is {self.name}")

    def introduce(self):
        print(f"Hi! I'm {self.name} and I'm {self.age} years old.")

dog = Dog("Buddy", 3)



class BankAccount:

    def __init__(self, owner):
        self.owner = owner
        self.balance = 0

    def deposit(self, amount):
        self.balance += amount

    def withdraw(self, amount):
        if self.balance < amount:
            print("Insufficient funds.")
        else:
            self.balance -= amount

    def display_balance(self):
        print(f"{self.owner} balance is {self.balance}")


#account1 = BankAccount("Alicia")
#account1.deposit(150)
#account1.withdraw(30)
#account1.display_balance()

