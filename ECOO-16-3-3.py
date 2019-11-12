import sys

words = []
visit = {}
visitSet = set([])


def recur(s, n):
    # print "whoaaa", s, len(s), list(s)
    if len(s) == 0:
        # print "omg", s, n
        return n
    elif s in visitSet:
        return visit.get(s)
    else:
        minWords = 100000
        for word in words:
            if s[:len(word)] == word:
                # print "hi", s[len(word):]
                res = recur(s[len(word):], n+1)
                minWords = min(res, minWords)
                # print "min", minWords
        visitSet.add(s)
        visit.update([[s, minWords-n]])
        return minWords


for i in range(input()):
    words.append(sys.stdin.readline().strip())
for test in range(10):
    s = sys.stdin.readline().strip()
    print recur(s, 0)-1
    # print visitSet
    # print visit
