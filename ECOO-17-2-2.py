import sys
import collections

ROW = 0
COL = 1
KS = 2
TS = 3

for test in range(10):
    visited = set([])
    m = []
    start = [0, 0]
    n = input()
    for i in range(n):
        line = sys.stdin.readline().strip()
        if line.find("S") != -1:
            start = [i, line.find("S")]
        m.append(list(line))
    left = collections.deque([(start[0], start[1], 0, 0)])
    maxt = 0
    while len(left) > 0:
        state = left.popleft()
        if state[ROW] > -1 and state[ROW] < n and state[COL] > -1 and state[COL] < n and state not in visited:
            visited.add(state)
            # print state
            cur = m[state[ROW]][state[COL]]
            if cur != "#" or (ord(cur) >= 49 and ord(cur) <= 57 and int(cur) <= state[KS]):
                k = state[KS]
                t = state[TS]
                if cur == "K":
                    m[state[ROW]][state[COL]] = "."
                    k += 1
                elif cur == "T":
                    m[state[ROW]][state[COL]] = "."
                    t += 1
                    maxt = max(maxt, t)
                left.append((state[ROW]+1, state[COL], k, t))
                left.append((state[ROW], state[COL]+1, k, t))
                left.append((state[ROW]-1, state[COL], k, t))
                left.append((state[ROW], state[COL]-1, k, t))
    print maxt
