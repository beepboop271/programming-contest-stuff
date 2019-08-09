import re

number = ""
for i in range(4):
    number = number+str(input())

if re.search("(8|9)[0-9][0-9](8|9)", number) is not None:
    if number[1] == number[2]:
        print "ignore"
    else:
        print "answer"
else:
    print "answer"
