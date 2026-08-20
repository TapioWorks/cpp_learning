import math

radius = float(input("Give a radius of a circle in cm: "))

circumference = 2 * math.pi * radius
area = math.pi * pow(radius, 2)

print(f"The circumference is: {round(circumference, 3)}cm")
print(f"The area is: {round(area, 3)}cm^2")

side_a = float(input("Give triangles side length: "))
side_b = float(input("Give another side length: "))

result = math.sqrt(pow(side_a, 2) + pow(side_b, 2))

print(f"Side C == {round(result, 3)}")