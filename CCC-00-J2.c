#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int rangeStart, rangeEnd, numLength, total, isValid;
    total = 0;
    scanf("%d\n%d", &rangeStart, &rangeEnd);
    for(int i = rangeStart; i <= rangeEnd; i++) {
        char numString[6];
        sprintf(numString, "%d", i);
        if(strchr(numString, '2') != NULL
           || strchr(numString, '3') != NULL
           || strchr(numString, '4') != NULL
           || strchr(numString, '5') != NULL
           || strchr(numString, '7') != NULL) {
               continue;
        } else {
            numLength = strlen(numString);
            if(numLength == 1) {
                if(numString[0] == '0'
                   || numString[0] == '1'
                   || numString[0] == '8') {
                       total++;
                }
                continue;
            }
            isValid = 1;
            for(int j = 0; j < numLength/2; j++) {
                if(numString[j] == '6' && numString[numLength-1-j] == '9') {
                    continue;
                } else if(numString[j] == '9' && numString[numLength-1-j] == '6') {
                    continue;
                } else if(numString[j] == '0' && numString[numLength-1-j] == '0') {
                    continue;
                } else if(numString[j] == '1' && numString[numLength-1-j] == '1') {
                    continue;
                } else if(numString[j] == '8' && numString[numLength-1-j] == '8') {
                    continue;
                } else {
                    isValid = 0;
                }
            }
            if(numLength%2 == 1) {
                if(numString[numLength/2] == '6' || numString[numLength/2] == '9') {
                    isValid = 0;
                }
            }
            if(isValid == 1) {
                total++;
            }
        }
    }
    printf("%d\n", total);
    return 0;
}