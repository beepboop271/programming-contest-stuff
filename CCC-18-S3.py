import string
import sys


def read():
    return sys.stdin.readline().strip()


gridSize = map(int, read().split())
gridHeight = gridSize[0]
gridWidth = gridSize[1]
grid = []
distances = []

robotPos = []

for y in xrange(gridHeight):
    row = read()
    if "S" in row:
        robotPos = [string.index(row, "S"), y]
    if row[-1] != "W":
        row = row[:-1]
    grid.append(list(row))
    distances.append([-1]*gridWidth)


def markCamera(x, y):
    currentX, currentY = x, y
    # scan left:
    currentX -= 1
    while currentX >= 0 and grid[y][currentX] != "W":
        if grid[y][currentX] == ".":
            grid[y][currentX] = "V"
        elif grid[y][currentX] == "S":
            grid[y][currentX] = "X"
        currentX -= 1
    # scan right:
    currentX, currentY = x, y
    currentX += 1
    while currentX < gridWidth and grid[y][currentX] != "W":
        if grid[y][currentX] == ".":
            grid[y][currentX] = "V"
        elif grid[y][currentX] == "S":
            grid[y][currentX] = "X"
        currentX += 1
    # scan up:
    currentX, currentY = x, y
    currentY -= 1
    while currentY >= 0 and grid[currentY][x] != "W":
        if grid[currentY][x] == ".":
            grid[currentY][x] = "V"
        elif grid[currentY][x] == "S":
            grid[currentY][x] = "X"
        currentY -= 1
    # scan down:
    currentX, currentY = x, y
    currentY += 1
    while currentY < gridHeight and grid[currentY][x] != "W":
        if grid[currentY][x] == ".":
            grid[currentY][x] = "V"
        elif grid[currentY][x] == "S":
            grid[currentY][x] = "X"
        currentY += 1


for y in xrange(gridHeight):
    for x in xrange(gridWidth):
        if grid[y][x] == "C":
            markCamera(x, y)


def findPath(x, y, depth):
    if distances[y][x] > -1 and distances[y][x] <= depth:
        return
    if grid[y][x] == "W" or grid[y][x] == "V" or grid[y][x] == "C" or grid[y][x] == "X":
        return
    elif grid[y][x] == "S" and depth > 0:
        return
    elif grid[y][x] == ".":
        if distances[y][x] == -1 or depth < distances[y][x]:
            distances[y][x] = depth
        else:
            return
    if grid[y][x] == "L":
        findPath(x-1, y, depth)
    elif grid[y][x] == "R":
        findPath(x+1, y, depth)
    elif grid[y][x] == "U":
        findPath(x, y-1, depth)
    elif grid[y][x] == "D":
        findPath(x, y+1, depth)
    else:
        findPath(x, y-1, depth+1)
        findPath(x, y+1, depth+1)
        findPath(x-1, y, depth+1)
        findPath(x+1, y, depth+1)
    return


# for y in xrange(gridHeight):
#     for x in xrange(gridWidth):
#         print grid[y][x],
#     print ""


findPath(robotPos[0], robotPos[1], 0)
for y in xrange(gridHeight):
    for x in xrange(gridWidth):
        if grid[y][x] == "." or grid[y][x] == "V":
            print distances[y][x]
