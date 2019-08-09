import sys


def read():
    return int(sys.stdin.readline().strip())


streams = []

line = read()
for i in range(line):
    streams.append(read())

while(1):
    print streams
    line = read()

    if line == 99:
        index = read()-1
        amount = read()
        original = streams[index]
        streams[index] = original*(100-amount)*0.01
        streams.insert(index, original-streams[index])
    elif line == 88:
        index = read()-1
        streams[index] += streams[index+1]
        streams.pop(index+1)
    elif line == 77:
        break

for flow in streams:
    print int(flow),
