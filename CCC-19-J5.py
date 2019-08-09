import collections
import sys

substitutions = [None]*3
for i in range(3):
    substitutions[i] = sys.stdin.readline().strip().split()

lastLine = sys.stdin.readline().strip().split()
numMoves = int(lastLine[0])
startString = lastLine[1]
targetString = lastLine[2]
#alreadyMade = []


def substituteSubstrings(string, source):
    # [  [index1, result], [index2, result] ... [indexn, result]  ]
    if source not in string:
        return []
    start = -1
    result = collections.deque()
    while True:
        start = string.find(source, start+1)
        if start != -1:
            result.append(start+1)
        else:
            return result


def matchSubstring(movesMade, chain):
    #print chain, movesMade
    string = chain[-1][2]
    if movesMade == numMoves:
        if string == targetString:
            return True
        else:
            chain.pop()
            return False
    else:
        for i in range(len(substitutions)):
            subs = substituteSubstrings(string, substitutions[i][0])
            for s in subs:
                newString = string[:s-1]+string[s-1:].replace(substitutions[i][0], substitutions[i][1], 1)
                chain.append([i+1, s, newString])
                if matchSubstring(movesMade+1, chain):
                    return True
    chain.pop()
    return False


chain = collections.deque()
chain.append([0, 0, startString])
matchSubstring(0, chain)
chain.popleft()
for i in range(len(chain)):
    for component in chain.popleft():
        print component,
    print ""
