#include <stdio.h>
#include <stdlib.h>

int main() {
    int hours, minutes;
    scanf("%02d:%02d", &hours, &minutes);
    int currentTime;
    int distanceTravelled = 0;
    currentTime = hours*60+minutes;
    // rush hour: 420 to 600 and 900 to 1140

    while(1) {
        if((currentTime >= 420 && currentTime <= 600) || (currentTime >= 900 && currentTime <= 1140)) {
            distanceTravelled += 1;
        } else {
            distanceTravelled += 2;
        }
        if(distanceTravelled > 240) {
            break;
        }
        currentTime = (currentTime+1) % 1440;
    }

    hours = currentTime/60;
    minutes = currentTime%60;

    printf("%02i:%02i\n", hours, minutes);

    return 0;
}