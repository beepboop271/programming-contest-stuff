#include <stdio.h>
#include <stdlib.h>

int main() {
    int grid[2][2] = {1, 2, 3, 4};
    char nextCommand;
    int buffer;
    scanf("%c", &nextCommand);
    while(nextCommand == 'H' || nextCommand == 'V') {
        if(nextCommand == 'H') {
            buffer = grid[1][0];
            grid[1][0] = grid[0][0];
            grid[0][0] = buffer;

            buffer = grid[1][1];
            grid[1][1] = grid[0][1];
            grid[0][1] = buffer;
        } else if(nextCommand == 'V') {
            buffer = grid[0][1];
            grid[0][1] = grid[0][0];
            grid[0][0] = buffer;

            buffer = grid[1][1];
            grid[1][1] = grid[1][0];
            grid[1][0] = buffer;
        }

        scanf("%c", &nextCommand);
    }

    printf("%d %d\n%d %d\n", grid[0][0], grid[0][1], grid[1][0], grid[1][1]);

    return 0;
}
