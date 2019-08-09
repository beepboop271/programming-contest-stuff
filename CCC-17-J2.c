#include <stdio.h>
#include <math.h>
#include <stdlib.h>

int main() {
    int num, numShifts;
    scanf("%d\n%d", &num, &numShifts);
    long sum = num;
    for(int i = 1; i <= numShifts; i++) {
        sum += num*pow(10, i);
    }
    printf("%li\n", sum);
    return 0;
}