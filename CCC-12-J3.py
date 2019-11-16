icon = [['*', 'x', '*'],
        [' ', 'x', 'x'],
        ['*', ' ', '*']]
k = input()

for i in range(3):
    for j in range(3):
        icon[i][j] *= k
    for j in range(k):
        print "".join(icon[i])
