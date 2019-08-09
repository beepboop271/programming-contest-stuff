numStudents = input()
row1 = raw_input()
row2 = raw_input()

row1 = row1.split()
row2 = row2.split()


def checkValid(row1, row2):
    paired = []
    pairs = []
    for i in range(len(row1)):
        #print paired, pairs
        if row1[i] == row2[i]:
            print "bad"
            return
        if row1[i] not in paired and row2[i] not in paired:
            paired.append(row1[i])
            paired.append(row2[i])
            pairs.append([row1[i], row2[i]])
        elif row1[i] in paired and row2[i] not in paired:
            print "bad"
            return
        elif row1[i] in paired and row2[i] in paired:
            for pair in pairs:
                if pair[0] == row1[i]:
                    if pair[1] != row2[i]:
                        print "bad"
                        return
                elif pair[0] == row2[i]:
                    if pair[1] != row1[i]:
                        print "bad"
                        return
                elif pair[1] == row1[i]:
                    if pair[0] != row2[i]:
                        print "bad"
                        return
                elif pair[1] == row2[i]:
                    if pair[0] != row1[i]:
                        print "bad"
                        return
    print "good"


checkValid(row1, row2)
