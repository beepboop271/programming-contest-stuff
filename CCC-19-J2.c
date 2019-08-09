#include <stdio.h>
#include <stdlib.h>

int main() {
    int numMessages;
    scanf("%d", &numMessages);

    int numRepetitions;
    char character;
    for(int i = 0; i < numMessages; i++) {
        scanf(" %d %c", &numRepetitions, &character);
        for(int j = 0; j < numRepetitions; j++) {
            printf("%c", character);
        }
        printf("\n");
    }

    return 0;
}
