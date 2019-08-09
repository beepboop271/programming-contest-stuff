import sys
import collections


def readInts():
    return map(int, sys.stdin.readline().strip().split(" "))


def cmp(x, y):
    #print x, y
    if x[1] > y[1]:
        return -1
    elif x[1] == y[1]:
        return 0
    else:
        return 1


def findResistance(exclude):
    notVisited = [i for i in range(n+1)]
    notVisited.remove(exclude)

    resistance = 1
    queue = collections.deque()

    disjoint = 1
    x = 0
    y = 1
    while len(notVisited) > 1:
        #print "Loop"
        queue.clear()
        queue.append(notVisited.pop())
        #print queue, notVisited
        while len(queue) > 0:
            curr = queue.popleft()
            for v in verts[curr]:
                if v in notVisited and v != exclude:
                    queue.append(v)
                    notVisited.remove(v)
                    y += 1
        #print n, len(notVisited), x, y, n-len(notVisited)-x
        
        if n-len(notVisited)-x > 0:
            disjoint += 1
            resistance = max(resistance, n-len(notVisited)-x)
        x += y
    #print "end"
    if disjoint >= 3:
        return resistance
    else:
        return -1


n, m = readInts()
verts = [[]]
vertCounts = [[]]
for i in range(1, n+1):
    verts.append([])
    vertCounts.append([i, 0])

for i in range(m):
    a, b = readInts()
    verts[a].append(b)
    vertCounts[a][1] += 1
    verts[b].append(a)
    vertCounts[b][1] += 1

vertCounts = sorted(vertCounts[1:], cmp)
#print vertCounts
current = 0
possible = [-1]*(n+1)

while True:
    r = findResistance(vertCounts[current][0])
    possible[vertCounts[current][0]] = r
    #print r
    if r != -1 and vertCounts[current][0] != vertCounts[current+1][0]:
        #print vertCounts[current][0], r
        maxr = max(possible)
        if possible.count(maxr) > 1:
            possible.reverse()
            print n+1-possible.index(r), r
        else:
            print possible.index(r), r
        break
    current += 1
    if current >= len(vertCounts):
        print -1, -1
        break
