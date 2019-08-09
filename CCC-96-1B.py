numNums = input()

for i in range(numNums):
    num = input()
    originalNum = num
    print num
    while num > 99:
        temp = num % 10
        num /= 10
        num -= temp
        print num
    if num % 11 == 0:
        print "The number", originalNum, "is divisible by 11."
