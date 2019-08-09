#include <stdio.h>
#include <stdlib.h>

int main() {
    int n;
    scanf("%d", &n);
    int count = 0;
    for(int i = n; i > 0; i--) {
        if(i <= 5 && ((i > n/2 && n % 2 == 1) || (i >= n/2 && n % 2 == 0))) {
            count++;
        }
    }
    printf("%d\n", count);

    return 0;
}