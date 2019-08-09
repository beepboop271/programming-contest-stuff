#include <stdio.h>
#include <stdlib.h>

int main() {
    int grid[4][4];
    for(int i = 0; i < 4; i++) {
        for(int j = 0; j < 4; j++) {
            scanf(" %i", &grid[i][j]);
        }
    }
    int total;
    total = grid[0][0]+grid[0][1]+grid[0][2]+grid[0][3];

    int rowSum, columnSum;
    for(int i = 0; i < 4; i++) {
        rowSum = 0;
        columnSum = 0;
        for(int j = 0; j < 4; j++) {
            rowSum += grid[i][j];
            columnSum += grid[j][i];
        }
        if(rowSum != total || columnSum != total) {
            printf("not magic\n");
            return 0;
        }
    }
    printf("magic\n");
    return 0;
}