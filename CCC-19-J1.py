apple3 = input()
apple2 = input()
apple1 = input()
banana3 = input()
banana2 = input()
banana1 = input()

banana = 3*banana3 + 2*banana2 + banana1
apple = 3*apple3 + 2*apple2 + apple1

if banana > apple:
    print "B"
elif apple > banana:
    print "A"
else:
    print "T"
