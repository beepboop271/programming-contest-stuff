year = input()
valid = False
while not valid:
    year += 1
    yearList = list(str(year))
    valid = True
    for letter in yearList:
        if yearList.count(letter) > 1:
            valid = False

print year
