#include <stdio.h>
#include <stdlib.h>

int main() {
    int maxWeight;
    scanf("%d", &maxWeight);
    int numTrains;
    scanf("%d", &numTrains);
    int *trains = malloc(sizeof(int)*numTrains);
    int currentTrain = 0;
    for(int i = 0; i < numTrains; i++) {
        scanf("%d", trains[i]);
    }
    int bridge[4];
    bridge[0] = -1;
    bridge[1] = -1;
    bridge[2] = -1;
    bridge[3] = -1;

    int movedTrains = 0;
    int done = 0;
    while(done == 0) {
        if(bridge[0] == -1) {
            bridge[0] = trains[currentTrain];
            currentTrain++;
        } else {
            
        }
    }

    free(trains);
    return 0;
}
