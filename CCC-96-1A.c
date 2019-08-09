#include <stdio.h>
#include <stdlib.h>

int main() {
    int nextNum;
    int currentSum=0;
    int numNums;
    scanf("%d", &numNums);

    for(int i = 0; i < numNums; i++) {

        scanf(" %d", &nextNum);
        for(int j = 1; j <= nextNum/2+1; j++) {
            if(nextNum%j == 0) {
                currentSum += j;
            }
        }

        if(currentSum < nextNum) {
            printf("%d is a deficient number.\n", nextNum);
        } else if(currentSum == nextNum) {
            printf("%d is a perfect number.\n", nextNum);
        } else {
            printf("%d is an abundant number.\n", nextNum);
        }

        currentSum = 0;
    }

    return 0;
}
