n = input()
count = 0
for i in range(n, 0, -1):
    if(i <= 5 and ((i > n/2 and n % 2 == 1) or (i >= n/2 and n % 2 == 0))):
        count += 1
print count
