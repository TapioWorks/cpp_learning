# dictionary is a collection of key value pairs

captials = {"USA": "Washington D.C. ",
            "Inida": "New Delhi",
            "China": "Beijing",
            "Russia": "Moscow"}

#print(dir(captials))
#print(captials.get("USA"))

#for key in captials.keys():
#    print(key)

items  = captials.items()

print(items)

for key, value in captials.items():
    print(f"{key}, {value}")