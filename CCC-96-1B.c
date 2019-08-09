#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int* subtract(int* num, int num2) {
    
}

int main() {
    int numNums;
    scanf("%d", &numNums);
    char numStr[55];
    int num[55];
    int unitDigit=0;

    for(int i = 0; i < numNums; i++) {
        scanf(" %s", &numStr);
        printf("%s\n", numStr);
        for(int j = 0; j < strlen(&numStr); j++) {
            num[j] = ((int)(numStr[j]))-48;
        }
        for(int j = strlen(&numStr); j > 1; j++) {
            unitDigit = num[j];
            numStr[j] = '\0';
            
        }
    }

    return 0;
}
