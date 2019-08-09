#include <stdio.h>
#include <stdlib.h>

int main() {
    char gameOutcome;
    int winCount = 0;
    for(int i = 0; i < 6; i++) {
        scanf(" %c", &gameOutcome);
        if(gameOutcome == 'W') {
            winCount++;
        }
    }
    if(winCount == 5 || winCount == 6) {
        printf("1\n");
    } else if(winCount == 3 || winCount == 4) {
        printf("2\n");
    } else if(winCount == 1 || winCount == 2) {
        printf("3\n");
    } else {
        printf("-1\n");
    }

    return 0;
}