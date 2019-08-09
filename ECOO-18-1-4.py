x, y = map(int, raw_input().split(" "))
corners = [[1, 0]]

computeX, computeY = 1, 0
direction = [-1, -1]
lastFib = 0
tempFib = 0
fib = 1
found = [False, False]
index = True

def f(x):
    return x*-1

while not found[0] and not found[1]:
    found = [False, False]

    computeX += direction[0]*fib
    computeY += direction[1]*fib
    corners.append([computeX, computeY])

    tempFib = lastFib
    lastFib = fib
    fib = fib+tempFib

    direction[int(index)] *= -1
    index = not index
    if fib > 100:
        found = True

    if len(corners) > 1:
        if corners[-1][0] > corners[-2][0]:
            if corners[-2][0] <= x and x <= corners[-1][0]:
                found[0] = True
        else:
            if corners[-1][0] <= x and x <= corners[-2][0]:
                found[0] = True
        if corners[-1][1] > corners[-2][1]:
            if corners[-2][1] <= y and y <= corners[-1][1]:
                found[1] = True
        else:
            if corners[-1][1] <= y and y <= corners[-2][1]:
                found[0] = True
print fib
