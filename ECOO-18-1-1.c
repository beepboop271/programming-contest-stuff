#include <stdio.h.>
#include <stdlib.h>

int main() {
    int playDuration;
    int numDays;

    scanf("%d %d", &playDuration, &numDays);

    int queuedBoxes;
    int currentBox;
    int timeLeft;
    char dayResult;
    for(int i = 0; i < numDays; i++) {
        scanf(" %c", &dayResult);
        if(dayResult == 'B') {
            if(currentBox == 1) {
                queuedBoxes++;
            } else {
                currentBox = 1;
                timeLeft = playDuration;
            }
        }
        if(currentBox == 1) {
            timeLeft--;
        } else {
            if(queuedBoxes > 0) {
                queuedBoxes--;
                currentBox = 1;
                timeLeft = playDuration-1;
            }
        }
        if(timeLeft <= 0) {
            currentBox = 0;
        }
    }
    timeLeft += playDuration*queuedBoxes;
    printf("%d\n", timeLeft);

    return 0;
}
