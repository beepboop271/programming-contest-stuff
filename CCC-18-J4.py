import string

numPlants = input()
table = []
for i in xrange(numPlants):
    row = raw_input()
    row = string.split(row)
    for j in xrange(numPlants):
        row[j] = int(row[j])
    table.append(row)

# holy crap everything after this is trash

def leftAscending():
    for i in xrange(numPlants-1):
        if table[i][0] > table[i+1][0]:
            return False
    return True
def leftDescending():
    for i in xrange(numPlants-1):
        if table[i][0] < table[i+1][0]:
            return False
    return True
def topAscending():
    for i in xrange(numPlants-1):
        if table[0][i] > table[0][i+1]:
            return False
    return True
def topDescending():
    for i in xrange(numPlants-1):
        if table[0][i] < table[0][i+1]:
            return False
    return True

def rightDescending():
    for i in xrange(numPlants-1):
        if table[i][-1] < table[i+1][-1]:
            return False
    return True
def bottomAscending():
    for i in xrange(numPlants-1):
        if table[-1][i] > table[-1][i+1]:
            return False
    return True

# 90 cw: top descending, left ascending
# 180 cw: top descending, right ascending
# 270 cw: bottom ascending, left descending
# 0/360 cw: top ascending, left ascending

def rotate90(table):
    newRow = []
    newTable = []
    for i in xrange(numPlants):
        for j in xrange(numPlants-1, -1, -1):
            newRow.append(table[j][i])
        newTable.append(list(newRow))
        newRow = []
    return newTable

def printTable():
    for row in table:
        for element in row:
            print element,
        print ""

if topDescending():
    if leftAscending():
        table = rotate90(table)
        table = rotate90(table)
        table = rotate90(table)
        printTable()
    elif rightDescending():
        table = rotate90(table)
        table = rotate90(table)
        printTable()
elif bottomAscending() and leftDescending():
    table = rotate90(table)
    printTable()
elif topAscending() and leftAscending():
    printTable()