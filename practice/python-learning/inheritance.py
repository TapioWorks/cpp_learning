

class Animal:
    def __init__(self, name):
        self.name = name
        self.is_alive = True
    
    def eat(self):
        print(f"{self.name} is eating")
    
    def sleep(self):
        print(f"{self.name} is sleeping")


class Dog(Animal):
    def speak(self):
        print("Woof Woof!")

class Cat(Animal):
    def speak(self):
        print("Meow Meow!")

class Mouse(Animal):
    def speak(self):
        print("SQQUUUUUK!")


dog = Dog("Scooby")

cat = Cat("Garfield")

mouse = Mouse("Mickey")

print(dog.name)
print(dog.is_alive)
mouse.eat()
dog.sleep()


cat.speak()

mouse.speak()