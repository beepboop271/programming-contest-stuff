#include <stdio.h>
#include <stdlib.h>

int main() {
    int votes;
    scanf("%d", &votes);
    char voteChars[votes];
    int a=0, b=0;
    for(int i = 0; i < votes; i++) {
        scanf(" %c", &voteChars[i]);
        if (voteChars[i] == 'A') {
            a++;
        } else {
            b++;
        }
    }
    if(a > b) {
        printf("A\n");
    } else if (b > a) {
        printf("B\n");
    } else {
        printf("Tie\n");
    }

    return 0;
}