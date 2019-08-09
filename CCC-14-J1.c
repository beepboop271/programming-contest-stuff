#include <stdio.h>
#include <stdlib.h>

int main() {
    int angle1, angle2, angle3;
    scanf("%d %d %d", &angle1, &angle2, &angle3);

    if(angle1+angle2+angle3 != 180) {
        printf("Error\n");
    } else if(angle1==60 && angle2==60 && angle3==60) {
        printf("Equilateral\n");
    } else if(angle1==angle2 || angle1==angle3 || angle2==angle3) {
        printf("Isosceles\n");
    } else {
        printf("Scalene\n");
    }

    return 0;
}