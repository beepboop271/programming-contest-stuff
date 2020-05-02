import sys

notes = ["C", "C#", "D", "D#", "E", "F", "F#", "G", "G#", "A", "A#", "B"]

t = int(sys.stdin.readline())
for _ in range(t):
    c = sys.stdin.readline().rstrip().split(" ")
    gap = []
    for i in range(3):
        g = notes.index(c[i+1]) - notes.index(c[i])
        if g < 0:
            g = len(notes)-notes.index(c[i]) + notes.index(c[i+1])
        gap.append(g)
    # print(gap)
    if gap == [4, 3, 3]:
        print("root")
    elif gap == [3, 3, 2]:
        print("first")
    elif gap == [3, 2, 4]:
        print("second")
    elif gap == [2, 4, 3]:
        print("third")
    else:
        print("invalid")
