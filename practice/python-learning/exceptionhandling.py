
try:
    number = int(input("Enter a number: "))
    print(1 / number)
except ZeroDivisionError:
    print("You cannot divede by zero")
except ValueError:
    print("Enter only numbers please")
finally:
    print("Do some cleanup here!")