#include <stdio.h>
#include <stdlib.h>

int main() {
    int numBoards;
    scanf("%i", &numBoards);

    int *boards = calloc(2001, sizeof(int));
    for(int i = 0, n; i < numBoards; i++) {
        scanf("%i", n);
        boards[n]++;
    }


    return 0;
}