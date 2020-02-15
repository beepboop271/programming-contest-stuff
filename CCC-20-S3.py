import sys
import itertools

needle = sys.stdin.readline().strip()
haystack = sys.stdin.readline().strip()

perms = set(itertools.permutations(needle))

count = 0

for st in perms:
    if ("".join(st) in haystack):
        count += 1

print(count)
