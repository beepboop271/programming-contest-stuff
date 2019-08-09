month = input()
day = input()

if month < 2:
    output = "Before"
elif month > 2:
    output = "After"
else:
    if day < 18:
        output = "Before"
    elif day > 18:
        output = "After"
    else:
        output = "Special"

print output
