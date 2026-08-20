def day_of_week(day):
    match day:
        case 1:
            return "Its Monday"
        case 2:
            return "Its Tuesday"
        case 3:
            return "Its Wednesday"
        case 4:
            return "Its Thursday"
        case 5:
            return "Its Friday"
        case 6:
            return "Its Saturday"
        case 7:
            return "Its Sunday"
        case _:
            return "Not a valid day"

def is_weekend(day):
    match day:
        case "Saturday" | "Sunday":
            return True
        case "Monday" | "Tuesday" | "Wednesday" | "Thursday" | "Friday":
            return False
        case _:
            return "Not a valid day"

print(day_of_week("pizza"))

print(is_weekend("Monday"))