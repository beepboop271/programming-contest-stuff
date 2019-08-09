import sys
import collections

maxWeight = int(sys.stdin.readline().strip())
numTrains = int(sys.stdin.readline().strip())
trains = collections.deque()
for i in range(numTrains):
    trains.append(int(sys.stdin.readline().strip()))
bridge = collections.deque()
movedTrains = 0
done = False
while not done:
    bridge.append(trains.popleft())
    if len(bridge) > 4:
        bridge.popleft()
        movedTrains += 1

    currentWeight = 0
    for train in bridge:
        currentWeight += train
    if currentWeight > maxWeight:
        done = True
        bridge.pop()
        break

movedTrains += len(bridge)

print movedTrains
