import sys
import re

empty = re.compile(r"^-+$")
top = re.compile(r"^-+((?:\*-)+)")
both = re.compile(r"^-*\*-+\*-*$")
single = re.compile(r"^-*\*-*$")

countleft = re.compile(r"^(-*)\*")
countright = re.compile(r"\*(-*)$")

def getn(n):
    print(n)
    if top.match(n[0]):
        if both.match(n[1]):
            if both.match(n[-2]):
                i = 2
                while empty.match(n[i]) is None:
                    i += 1
                    if (i >= len(n)):
                        return 8
                if empty.match(n[i]) is not None:
                    return 0
                else:
                    return 8
            else:
                return 9
        elif single.match(n[1]):
            if top.match(n[-1]):
                if both.match(n[-2]):
                    return 6
                else:
                    lu = countleft.match(n[1])
                    ru = countright.match(n[1])
                    ll = countleft.match(n[-2])
                    rl = countright.match(n[-2])
                    # print(lu, ru, ll, rl)
                    if ru is None:
                        if rl is None:
                            return 3
                        else:
                            return 2
                    if rl is None:
                        return 5
                        # if lu is not None:
                        #     if ll is None and rl is not None:
                        #         return 2
                        #     elif ll is not None and rl is None:
                        #         return 3
                        #     else:
                        #         return "B"
                        # else:
                        #     return "C"
                    lu = len(lu.group(1))
                    ru = len(ru.group(1))
                    ll = len(ll.group(1))
                    rl = len(rl.group(1))
                    if lu > ru and ll > rl:
                        return 3
                    elif lu > ru and rl > ll:
                        return 2
                    elif ru > lu and ll > rl:
                        return 5
                    else:
                        return "A"
            else:
                return 7
        else:
            return "B"
    else:
        if both.match(n[0]):
            return 4
        elif single.match(n[0]):
            return 1
        else:
            return "C"
    # print(n)
    return "D"


t = int(sys.stdin.readline())

for _ in range(t):
    n = int(sys.stdin.readline())
    for _a in range(n):
        h, w = map(int, sys.stdin.readline().rstrip().split(" "))
        num = []
        found = False
        nempty = 0
        for row in range(h):
            line = sys.stdin.readline().rstrip()
            if not found:
                # print("notfound")
                if empty.match(line) is None:
                    # print("found")
                    found = True
                    num.append(line)
            else:
                # print("finding")
                num.append(line)
                if empty.match(line) is not None:
                    nempty += 1
                    if nempty > 1:
                        found = False
                else:
                    nempty = 0
        for asdf in range(nempty):
            num.pop()
        print(getn(num), end="")
    print("")
