#include <stdio.h>
#include <stdlib.h>

int main() {
    int x, y;
    scanf("%i\n%i", &x, &y);
    if(x > 0 && y > 0) {
        printf("1\n");
    } else if(x < 0 && y > 0) {
        printf("2\n");
    } else if(x < 0 && y < 0) {
        printf("3\n");
    } else if(x > 0 && y < 0) {
        printf("4\n");
    }
    return 0;
}