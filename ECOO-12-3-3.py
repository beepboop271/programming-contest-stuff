import re
pattern = re.compile(r"\([^\(\)]+\)")


def calc(op):
    op = op[1:-1].split(" ")
    #print op
    if op[0] == "+":
        return int(op[1])+int(op[2])
    elif op[0] == "-":
        return int(op[1])-int(op[2])
    elif op[0] == "*":
        return int(op[1])*int(op[2])
    elif op[0] == "q":
        return int(op[1])/int(op[2])
    elif op[0] == "r":
        return int(op[1])%int(op[2])


def evaluate(s):
    try:
        n = int(s)
        return n
    except(ValueError):
        pass

    matchIter = re.finditer(pattern, s)
    while True:
        try:
            matchObj = matchIter.next()
            found = matchObj.group()
            #print("s", s, type(s))
            #print("f", found, type(found))
            #print("c", calc(found), type(calc(found)))
            s = s.replace(found, str(calc(found)))
            #print("s:", s)
        except(StopIteration):
            n = evaluate(s)
            return n


for case in range(10):
    s = raw_input().strip()
    print evaluate(s)
