import sys


def read():
    return map(int, sys.stdin.readline().strip().split(" "))


n, k = read()
costs = read()

friends = []
for i in range(n):
    friend = read()
    if 0 not in friend:
        print -1
        exit()
    friends.append(list(friend))
friend = 0

lowestCost = 1000001
possible = [i for i in range(k)]
for friend in friends:
    for i in range(len(friend)):
        if friend[i] > 0:
            possible.remove(i)
