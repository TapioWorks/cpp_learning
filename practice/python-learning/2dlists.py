objests =   ["table", "chair", "sofa"]
foods =     ["pizza", "risotto", "hamburger"]
fruits =    ["banana", "strawberry", "apple"]

random_stuff = [objests, foods, fruits]

print(random_stuff[2])

num_pad = ((1, 2, 3),
           (3, 4, 5),
           (6, 7, 8),
           ("*", 9, "#"),)

for row in num_pad:
    for num in row:
        print(num, end=" ")
    print()
