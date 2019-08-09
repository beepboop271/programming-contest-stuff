#include <stdio.h>
#include <stdlib.h>

int main() {
    int count = 0;
    int high = 0;

    char next;
    scanf("%c", &next);
    do {
        if(next == 'S') {
            ++count;
        } else if(next == 'R'){
            if(count > high) {
                high = count;
            }
            count = 0;
        }
        scanf("%c", &next);
    } while(next == 'S' || next == 'R');
    if(count > high) {
        high = count;
        count = 0;
    }

    int max;
    scanf(" %d", &max);
    if(high < max) {
        printf("All good\n");
    } else {
        printf("Spamming\n");
    }
}