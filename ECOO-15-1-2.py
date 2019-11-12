def splitParagraph(maxWidth, paragraph):
    lines = []
    while len(paragraph) > maxWidth:
        nextLine = paragraph[:maxWidth]
        # print list(nextLine)
        if nextLine.find(" ") == -1 or paragraph[maxWidth] == " ":
            lines.append(nextLine.strip())
            paragraph = paragraph[len(nextLine):].strip()
        else:
            while(nextLine[-1] != " "):
                nextLine = nextLine[:-1]
            paragraph = paragraph[len(nextLine):].strip()
            lines.append(nextLine[:-1].strip())
    lines.append(paragraph.strip())
    for i in range(len(lines)-1, -1, -1):
        if lines[i] == "":
            lines.pop(i)
    return lines


for test in range(10):
    maxChars = input()
    string = raw_input()
    # print splitParagraph(maxChars, string)
    for line in splitParagraph(maxChars, string):
        print line
    print "====="
