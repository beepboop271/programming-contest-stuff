import re

pattern = re.compile(r"([a-z]{1,}[^aeiou])or$", re.I)

line = raw_input()
while line != "quit!":
    match = re.search(pattern, line.strip())
    if match is None:
        print line
    else:
        print match.group(1)+"our"
    line = raw_input()
