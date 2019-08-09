#include <stdio.h>
#include <stdlib.h>

int main() {
    int distances[4];
    int index;
    int direction;
    int distance;
    scanf("%d %d %d %d", &distances[0], &distances[1], &distances[2], &distances[3]);

    for(int startCity = 0; startCity < 5; startCity++) {
        for(int endCity = 0; endCity < 5; endCity++) {
            distance = 0;
            direction = 1;
            if(endCity-startCity < 0) direction = -1;
            index = startCity;
            while(index != endCity) {
                if(direction == -1) {
                    distance += distances[index-1];
                } else {
                    distance += distances[index];
                }
                index += direction;
            }
            printf("%d ", distance);
        }
        printf("\n");
    }

    return 0;
}