#include <stdio.h>
#include <stdlib.h>

int main() {
    int numFriends;
    scanf("%d", &numFriends);
    int friends[numFriends+1];

    friends[0] = -1;
    for(int i = 1; i < numFriends+1; i++) {
        friends[i] = 1;
    }

    int rounds;
    scanf("%d", &rounds);

    int num, count;
    for(int i = 0; i < rounds; i++) {
        scanf("%d", &num);
        count = 1;
        for(int j = 1; j < numFriends+1; j++) {
            //printf("%d %d %d\n", count, friends[j], j);
            if(friends[j] == 1 && count%num == 0) {
                friends[j] = -1;
                count = 1;
            }
            if(friends[j] == 1) {
                count += 1;
            }
            //printf("%d %d %d\n", count, friends[j], j);
        }
    }

    for(int i = 0; i < numFriends+1; i++) {
        if(friends[i] == 1) {
            printf("%d\n", i);
        }
    }

    return 0;
}