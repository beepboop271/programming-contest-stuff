h = input()
out = []
for i in range(h):
    out.append(list([' ']*(2*h)))

size = 0
c = 0
row = h/2
for col in range(h-1, -1, -1):
    revcol = 2*h-1-col
    out[row][col] = '*'
    out[row][revcol] = '*'
    for i in range(size):
        out[row-i-1][col] = '*'
        out[row+i+1][col] = '*'
        out[row-i-1][revcol] = '*'
        out[row+i+1][revcol] = '*'
    c += 1
    if(c == 2):
        c = 0
        size += 1

for line in out:
    print ''.join(line)
