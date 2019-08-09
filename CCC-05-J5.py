import sys


def read():
    return sys.stdin.readline().strip()


def isMWord(s, b):
    result = isAWord(s, b)
    if result:
        if len(s) > result[1]:
            if s[result[1]] == "N":
                response = isMWord(s[result[1]+1:], b)
                if response:
                    response = list(response)
                    response[1] += result[1]+1
                return response
            elif s[result[1]] == "S":
                return True, result[1]+1
        else:
            if (not (len(s) > result[1]
                     and (s[result[1]] == "A"
                          or s[result[1]] == "B"))
                    and len(b) == 0):
                return True, result[1]
            else:
                return False
    else:
        return False


def aisMWord(s, b):
    result = isAWord(s, b)
    if result and len(result) > 1:
        if len(s) > result[1] and s[result[1]] == "N":
            response = isMWord(s[result[1]+1:], b)
            if response:
                response = list(response)
                response[1] += result[1]+1  # 2
            return response
        elif len(s) > result[1] and s[result[1]] == "S":
            return True, result[1]+1
        else:
            if (not (len(s) > result[1]
                     and (s[result[1]] == "A"
                          or s[result[1]] == "B"))
                    and len(b) == 0):
                return True, result[1]
            else:
                return False
    else:
        return result


def isAWord(s, b):
    if s[0] == "A":
        return True, 1
    elif s[0] == "B":
        b.append(1)
        result = isMWord(s[1:], b)
        if (result
                and len(s) > result[1]
                and s[result[1]] == "S"
                and len(b) > 0):
            b.pop()
            return True, result[1]+1
    return False


s = read()
while s != "X":
    if s[0] != "A" and s[0] != "B" or s[-1] != "A" and s[-1] != "S":
        print "NO"
    else:
        b = []
        if isMWord(s, b):
            print "YES"
        else:
            print "NO"
    s = read()
