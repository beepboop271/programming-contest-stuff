#include <stdio.h>
#include <stdlib.h>

void insertOnes(int num, int depth, int numDigits, int numOnes) {
    if(depth > numOnes) {
        return;
    } else {
        
    }
}

int main() {
    int numNums;
    int numDigits, numOnes;
    scanf("%d", &numNums);
    char bits[35];

    for(int i = 0; i < numNums; i++) {
        scanf(" %d %d", &numDigits, &numOnes);
        bits[numDigits] = '\0';
        for(int j = 0; j < numDigits; j++) {
            bits[j] = '0';
        }
        for(int j = 0; j < numDigits; j++) {

            for(int k = j; k < numDigits; k++) {

            }
        }
    }

    return 0;
}
