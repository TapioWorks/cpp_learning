principle = 0
rate = 0
time = 0

while principle <= 0:
    principle = float(input("Please give a principle amount: "))
    if principle <= 0:
        print(f"principle {principle} cannot be less than or equal to zero.")

while rate <= 0:
    rate = float(input("Please give intrest rate: "))
    if rate <= 0:
        print(f"intrest rate {rate} cannot be less than or equal to zero.")

while time <= 0:
    time = int(input("Enter the time in years: "))
    if time <= 0:
        print("Time cannot be less than or equal to zero.")

total = principle * pow((1 + rate / 100), time)

print(f"Balance after {time} years: €{total:.2f}")