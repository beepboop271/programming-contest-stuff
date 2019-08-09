#include <stdio.h>
#include <stdlib.h>

int main() {
    int antonia=100, david=100;
    int numRounds;
    scanf("%d", &numRounds);

    int antoniaRoll, davidRoll;
    for(int i = 0; i < numRounds; i++) {
        scanf(" %d %d", &antoniaRoll, &davidRoll);
        if(antoniaRoll < davidRoll) {
            antonia -= davidRoll;
        } else if(davidRoll < antoniaRoll) {
            david -= antoniaRoll;
        }
    }

    printf("%d\n%d\n", antonia, david);

    return 0;
}