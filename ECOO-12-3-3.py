import re
pattern = re.compile(r"\(([\+\-*qr]) (-{0,1}[0-9]+) (-{0,1}[0-9]+)\)")


def get(match):
    op = match.group(1)
    if op == 'q':
        op = '/'
    elif op == 'r':
        op = '%'
    return eval('('+match.group(2)+')'+op+'('+match.group(3)+')')


for case in range(10):
    s = raw_input().strip()
    match = re.search(pattern, s)
    while match is not None:
        s = s.replace(match.group(), str(get(match)))
        match = re.search(pattern, s)
    print s
