#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, c, total=0;
    scanf(" %d", &n);
    for(int i = 0; i < n; i++) {
        scanf(" %d", &c);
        total += c;
    }
    if(total > 200) {
        printf("Over maximum capacity!\n");
    } else {
        printf("%d\n", 200-total);
    }
}