adj = input()
noun = input()
adjs = []
nouns = []
for i in range(adj):
    adjs.append(raw_input().strip())
for i in range(noun):
    nouns.append(raw_input().strip())

for i in range(adj):
    for j in range(noun):
        print adjs[i], "as", nouns[j]
