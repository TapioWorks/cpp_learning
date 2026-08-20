# collection = a single varibale use to store multiple values
# List = [] ordered and changeable, duplicates are OK
# Set = {} unordered and immutable, but can add/remove but no duplicates
# Tuple = () ordered and unchangeable, duplicates OK and faster

fruits = ["Apple", "Orange", "Banana", "Coconut"]
#print(dir(fruits))

#print("Pineapple" in fruits)

fruits.append("Pineapple")


#fruits[0] = "Pineapple"

#print(fruits[::-1])

for fruit in fruits:
    print(fruit)