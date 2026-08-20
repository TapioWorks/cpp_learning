temp = 21
is_raining = False

if temp > 35 or temp < 0 or is_raining:
    print("The event has been canceled")
else:
    print("The outdoor even will be held")

is_sunny = False

if temp >= 28 and is_sunny:
    print("It will be a hot day")
else:
    print("Just a normal day and its sunny")

if temp < 22 and not is_sunny:
    print("Kinda mid day")
else:
    print("Yes")