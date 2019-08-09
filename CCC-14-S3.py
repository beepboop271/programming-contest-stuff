import sys


def findPath(mountain, branch, numTrains):
    target = 1
    lake = 0
    while lake < numTrains:
        #print mountain, branch, lake
        if target in mountain:
            while mountain[-1] != target:
                branch.append(mountain.pop(-1))
            mountain.pop(-1)
            lake += 1
            target += 1
        elif target in branch:
            if target != branch[-1]:
                return False
            else:
                branch.pop(-1)
                lake += 1
                target += 1
    return True


numTests = input()

for i in range(numTests):
    numTrains = input()
    mountain = []
    for i in range(numTrains):
        mountain.append(int(sys.stdin.readline().strip()))
    branch = []
    lake = []
    possible = findPath(mountain, branch, numTrains)
    if possible:
        print "Y"
    else:
        print "N"
