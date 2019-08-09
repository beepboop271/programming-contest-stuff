import sys

n, x, y, z = map(int, sys.stdin.readline().strip().split(" "))
codes = []
for i in range(n):
    codes.append(list(sys.stdin.readline().strip()))

for i in range(n):
    for j in range(len(codes[i])):
        if int(codes[i][j]) == 0:
            codes[i][j] = str(z)
        elif int(codes[i][j]) % 2 == 0:
            codes[i][j] = str(int(codes[i][j]) + x)
        elif int(codes[i][j]) % 2 == 1:
            codes[i][j] = str(max(0, int(codes[i][j]) - y))

answers = []
sys.stdin.readline()
for i in range(n):
    answers.append(list(sys.stdin.readline().strip()))

wrong = []
for i in range(n):
    for j in range(len(codes[i])):
        if codes[i][j] != answers[i][j]:
            wrong.append(i+1)
            break

if len(wrong) == 0:
    print "MATCH"
else:
    print "FAIL:",
    for wrongAnswer in wrong:
        print str(wrongAnswer)+",",
