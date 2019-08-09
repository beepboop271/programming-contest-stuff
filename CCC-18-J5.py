import string

numPages = input()
pages = [[]]*(numPages+1)
pageNumbers = []
for i in xrange(2, numPages+1):
    pageNumbers.append(i)

for i in xrange(1, numPages+1):
    pageOptions = raw_input()
    pageOptions = string.split(pageOptions)
    for j in xrange(int(pageOptions[0])+1):
        pageOptions[j] = int(pageOptions[j])
        if j != 0 and pageOptions[j] in pageNumbers:
            pageNumbers.remove(pageOptions[j])
    pages[i] = list(pageOptions)

possiblePaths = []
for i in xrange(len(pages[1])-1):
    possiblePaths.append([pages[1][i+1], 1])

fastestPaths = [[-1, 10001], [1, 0]]
for i in xrange(2, numPages+1):
    fastestPaths.append([-1, 10001])

# possible paths [destPage, sourcePage]
# fastest paths [sourcePage, distance]

exploredNodes = [1]

while len(possiblePaths) != 0:
    for i in xrange(len(possiblePaths)-1, -1, -1):
        if fastestPaths[possiblePaths[i][1]][1]+1 < fastestPaths[possiblePaths[i][0]][1]:
            fastestPaths[possiblePaths[i][0]][0] = possiblePaths[i][1]
            fastestPaths[possiblePaths[i][0]][1] = fastestPaths[possiblePaths[i][1]][1]+1
        for j in xrange(len(pages[possiblePaths[i][0]])):
            if pages[possiblePaths[i][0]][0] == 0:
                possiblePaths.append([0, possiblePaths[i][0]])
            elif j < len(pages[possiblePaths[i][0]])-1 and possiblePaths[i][0] not in exploredNodes:
                possiblePaths.append([pages[possiblePaths[i][0]][j+1], possiblePaths[i][0]])
        if possiblePaths[i][0] not in exploredNodes:
            exploredNodes.append(possiblePaths[i][0])
        possiblePaths.pop(i)

if len(exploredNodes) >= numPages+1:
    print "Y"
else:
    print "N"
print fastestPaths[0][1]