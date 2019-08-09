#include <stdio.h>
#include <stdlib.h>

int main() {
    long duration;
    scanf("%ld", &duration);
    int hours = 12;
    int minutes = -1;

    int count = 0;
    count = 31*(duration/720);
    duration = duration%720;
    for(long i = 0; i <= duration; i++) {
        minutes++;
        if(minutes == 60) {
            minutes = 0;
            hours++;
            if(hours == 13) {
                hours = 1;
            }
        }
        if(minutes < 10 || hours == 10) {
            continue;
        } else if(hours < 10 && minutes%10-minutes/10 == minutes/10-hours%10) {
            count++;
        } else if(hours > 10 && minutes%10-minutes/10 == minutes/10-hours%10 && minutes/10-hours%10 == hours%10-hours/10) {
            count++;
        }
    }

    printf("%i\n", count);

    return 0;
}