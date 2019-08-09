import sys

numMessages = input()

for i in range(numMessages):
    line = sys.stdin.readline().strip()
    #print line
    matchingChar = line[0]
    charCount = 0
    for char in line:
        #print char
        if char == matchingChar:
            charCount += 1
        else:
            print charCount, matchingChar,
            matchingChar = char
            charCount = 1
    print charCount, matchingChar
