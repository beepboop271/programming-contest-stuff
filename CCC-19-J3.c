#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main() {
    int numMessages;
    scanf("%d", &numMessages);
    char matchingChar;
    char nextInputChar;
    int charCount = 0;

    for(int i = 0; i < numMessages; i++) {
        scanf(" %c", &nextInputChar);
        matchingChar = nextInputChar;
        charCount = 0;
        while(nextInputChar != '\n') {
            //printf("%c\n", nextInputChar);
            if(matchingChar == nextInputChar) {
                charCount++;
            } else {
                printf("%d %c ", charCount, matchingChar);
                matchingChar = nextInputChar;
                charCount = 1;
            }
            scanf(" %c", &nextInputChar);
        }
        printf("\n");
    }
}

// int main() {
//     int numMessages;
//     scanf("%d", &numMessages);

//     char matchingChar;
//     char line[100];
//     int charCount;
//     for(int i = 0; i < numMessages; i++) {
//         scanf(" %s", &line);
//         matchingChar = line[0];
//         charCount = 0;
//         for(int j = 0; j <= strlen(line); j++) {
//             //printf("matching: %d %c\n", charCount, matchingChar);
//             if(line[j] == matchingChar) {
//                 charCount++;
//             } else {
//                 printf("%d %c ", charCount, matchingChar);
//                 matchingChar = line[j];
//                 charCount = 1;
//             }
//         }
//         printf("\n");
//     }

//     return 0;
// }
