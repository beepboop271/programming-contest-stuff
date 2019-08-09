file = open("C:\\Users\\Kevin\\Downloads\\ECOO2018\\Round 1\\DATA\\DATA11.txt")
for test in range(10):
    playLength, numDays = map(int, file.readline().strip().split())
    queuedBoxes, currentBox = 0, 0
    timeLeft = 0

    for i in range(numDays):
        if file.readline().strip() == "B":
            if currentBox == 0:
                currentBox = 1
                timeLeft = playLength-1
            else:
                timeLeft -= 1
                queuedBoxes += 1
        else:
            if currentBox == 1:
                timeLeft -= 1
        if timeLeft < 0:
            if queuedBoxes > 0:
                queuedBoxes -= 1
                timeLeft = playLength-1
            else:
                currentBox = 0
                timeLeft = 0
    timeLeft += queuedBoxes*playLength
    print timeLeft
