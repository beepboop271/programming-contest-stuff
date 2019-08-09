#include <stdio.h>
#include <stdlib.h>

int main() {
    int high1=0, high2=0;
    int c1, c2;
    int num[4];
    for(int i = 0; i < 4; i++) {
        scanf(" %d", &num[i]);
        if(num[i] > high1 && num[i] > high2) {
            //printf("%d %d\n", high1, num[i]);
            high2 = high1;
            c2 = c1;
            high1 = num[i];
            c1 = i;
        } else if(num[i] > high2) {
            //printf("%d %d\n", high2, num[i]);
            high2 = num[i];
            c2 = i;
        }
    }
    //printf("%d %d %d %d\n", c1, c2, high1, high2);
    if((c1+c2)%2 == 0) {
        printf("trans\n");
    } else {
        printf("cis\n");
    }
}