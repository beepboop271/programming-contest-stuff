#include <stdio.h>
#include <stdlib.h>

int main() {
    int startX, startY, endX, endY, charge;
    scanf("%i %i\n%i %i\n%i", &startX, &startY, &endX, &endY, &charge);
    int distance;
    distance = abs(endX-startX) + abs(endY-startY);
    if(charge < distance) {
        printf("N\n");
    } else if (charge == distance) {
        printf("Y\n");
    } else if ((charge-distance)%2 == 0) {
        printf("Y\n");
    } else {
        printf("N\n");
    }

    return 0;
}