ids = [0,0,0,1,1,1,2,2,2,3,3,3,4,4,4,5,5,5,5,6,6,6,7,7,7,7]
press = [1,2,3,4,1,2,3,1,2,3,4]
a = ord("a")


def gettime(char):
    if ord(char) < ord("p"):
        return ((ord(char)-a)%3)+1
    else:
        return press[ord(char)-ord("p")]


word = raw_input().strip()
while word != "halt":
    time = 0
    for i in range(len(word)):
        time += gettime(word[i])
        # print time, word[i]
        if i+1 < len(word):
            if ids[ord(word[i+1])-a] == ids[ord(word[i])-a]:
                time += 2
    print time
    word = raw_input().strip()
