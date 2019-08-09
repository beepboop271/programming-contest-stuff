numSpaces = input()

parkingYesterday = raw_input()
parkingToday = raw_input()
count = 0

for i in xrange(numSpaces):
    if parkingYesterday[i] == "C" and parkingYesterday[i] == parkingToday[i]:
        count = count+1

print count
