import sys


def read():
    return map(int, sys.stdin.readline().strip().split(" "))


def checkValid(period, diffs):
    chain = diffs[:period]
    # print period, chain, sum(chain), len(diffs)/period
    if p == len(diffs):
        return True
    # if sum(chain) < 1:
    #     return False
    for iteration in range(1, (len(diffs)/period)+1):
        # if diffs[iteration*period] >= diffs[(iteration-1)*period]:
        for i in range(0, period):
            if iteration*period+i >= len(diffs):
                return True
            # print "check", diffs[iteration*period+i], chain[i]
            if diffs[iteration*period+i] != chain[i]:
                return False
        # else:
            # print diffs[iteration*period], diffs[(iteration-1)*period]
            # return False
    return True


temps = read()
while temps != [0]:
    diffs = []
    # diffChain = []
    # checking = False
    for i in range(1, len(temps)-1):
        # if len(diffs) > 0 and diff == diffs[0]:
        #     checking = True
        #     diffChain = list(diffs)
        diffs.append(temps[i+1]-temps[i])
    if len(diffs) == 0:
        print 0
    # print diffs
    for p in range(1, len(diffs)+1):
        # print "p", p, len(diffs)
        if checkValid(p, diffs):
            # print "answer", p
            print p
            break
    temps = read()
