words = ["ook", "ookook", "oog",
         "ooga", "ug", "mook",
         "mookmook", "oogam",
         "oogum", "ugug"]
visit = {}
visitSet = set([])


def recur(s):
    # print "whoaaa", s, len(s), list(s)
    if len(s) == 0:
        # print "omg"
        return 1
    elif s in visitSet:
        return visit.get(s)
    else:
        total = 0
        for word in words:
            if s[:len(word)] == word:
                # print "hi", s[len(word):]
                total += recur(s[len(word):])
        visitSet.add(s)
        visit.update([[s, total]])
        return total


for test in range(10):
    s = raw_input().strip()
    print recur(s)
    # print visitSet
    # print visit
