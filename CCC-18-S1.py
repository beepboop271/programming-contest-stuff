import string

numVillages = input()
villages = []
for i in range(numVillages):
    villages.append(input())

villages.sort()

shortestDistance = 10000000000
for i in range(len(villages)):
    if i == 0 or i == len(villages)-1:
        next
    else:
        distanceL = (villages[i]-villages[i-1])/2.0
        distanceR = (villages[i+1]-villages[i])/2.0
        distance = distanceL+distanceR
        if distance < shortestDistance:
            shortestDistance = distance
print round(shortestDistance, 1)
#print str(shortestDistance)[:string.index(str(float(shortestDistance)), ".")+2]
