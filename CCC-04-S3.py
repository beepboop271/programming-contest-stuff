import sys
c = {"A": 0,
     "B": 1,
     "C": 2,
     "D": 3,
     "E": 4,
     "F": 5,
     "G": 6,
     "H": 7,
     "I": 8,
     "J": 9}


def read():
    return sys.stdin.readline().strip().split(" ")


def convert(term):
    return c.get(term[0]), int(term[1])-1


def get(l, coords):
    return l[coords[0]][coords[1]]


sheet = []
for i in range(10):
    sheet.append(read())

for y in range(10):
    for x in range(9):
        try:
            sheet[y][x] = int(sheet[y][x])
        except(ValueError):
            sheet[y][x] = sheet[y][x].split("+")
            # print sheet[y][x]
            for i in range(len(sheet[y][x])):
                term = get(sheet, convert(sheet[y][x][i]))
                # print term, convert(sheet[y][x][i]), type(term)
                if type(term) == int:
                    # print "asdfadsfsdkd"
                    sheet[y][x][i] = term

# print sheet

for i in range(1000):
    done = True
    for y in range(10):
        for x in range(9):
            if type(sheet[y][x]) == list:
                done = False
                try:
                    sheet[y][x] = sum(sheet[y][x])
                except(TypeError):
                    for i in range(len(sheet[y][x])):
                        if type(sheet[y][x][i]) == str:
                            term = get(sheet, convert(sheet[y][x][i]))
                            # print term, convert(sheet[y][x][i]), type(term)
                            if type(term) == int:
                                # print "asdfadsfsdkd"
                                sheet[y][x][i] = term
    if done:
        break

for y in range(10):
    for x in range(9):
        if type(sheet[y][x]) != int:
            sheet[y][x] = "*"

for row in sheet:
    for col in row:
        print col,
    print ""
