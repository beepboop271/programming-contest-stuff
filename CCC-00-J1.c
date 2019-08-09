#include <stdlib.h>
#include <stdio.h>

int main() {
    int startDay, numDays, currentDay;
    scanf("%d %d", &startDay, &numDays);
    printf("%s\n", "Sun Mon Tue Wed Thr Fri Sat");
    currentDay = -startDay+2;
    while(currentDay <= numDays) {
        for(int day = 0; day < 7; day++) {
            if(currentDay > numDays) {
                break;
            } else if(currentDay < 1) {
                printf("   ");
                if(day < 6 && currentDay != numDays) {
                    printf(" ");
                }
            } else if(currentDay < 10) {
                printf("  %d", currentDay);
                if(day < 6 && currentDay != numDays) {
                    printf(" ");
                }
            } else if(currentDay <= numDays) {
                printf(" %d", currentDay);
                if(day < 6 && currentDay != numDays) {
                    printf(" ");
                }
            }
            currentDay++;
        }
        printf("\n");
    }
    return 0;
}