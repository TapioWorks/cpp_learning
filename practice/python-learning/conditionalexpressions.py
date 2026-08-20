num = 67
a = 6
b = 7
age = 25
temp = 25
user_role = "Admin"

print("Positive" if num > 0 else "Negative")

result = "EVEN" if num % 2 == 0 else "ODD"

print(result)

max_num = a if a > b else b
min_num = a if a < b else b
print(max_num)
print(min_num)

status = "Adult" if age >= 18 else "Minor"
print(status)

weather = "Hot" if temp >= 24 else "Cold"
print(weather)

access_level = "AllRights" if user_role == "Admin" else "BasicRights"
print(access_level)