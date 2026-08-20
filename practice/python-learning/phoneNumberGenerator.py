def get_phone(county, area, first, last):
    return f"{county}-{area}-{first}-{last}"


phone_num = get_phone(county=1, area=123, first=456, last=7890)
print(phone_num)