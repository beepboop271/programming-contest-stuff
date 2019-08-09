#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct {
    int score;
    char name[25];
} computer;

int cmp(const void *e1, const void *e2) {
    computer *computer1 = (computer*)(e1);
    computer *computer2 = (computer*)(e2);
    //printf("%d %d ", computer1->score, computer2->score);
    if(computer1->score < computer2->score) {
        //printf("-1\n");
        return 1;
    } else if(computer1->score == computer2->score) {
        //printf("0\n");
        return strcmp(computer1->name, computer2->name);
        //return 0;
    } else {
        //printf("-1\n");
        return -1;
    }
}

int main() {
    int numComputers;
    scanf("%d", &numComputers);

    computer *computers = malloc(numComputers*sizeof(computer));

    int ram, speed, space;
    char id[25];
    for(int i = 0; i < numComputers; i++) {
        //computer *currentComputer = &computers[i];
        scanf(" %s %d %d %d", &id, &ram, &speed, &space);
        //printf("a\n");
        strcpy(computers[i].name, id);
        computers[i].score = (2*ram)+(3*speed)+space;
    }

    if(numComputers == 1) {
        printf("%s\n", &computers[0].name);
        free(computers);
        return 0;
    } else if(numComputers == 0) {
        free(computers);
        return 0;
    }

    qsort(computers, numComputers, sizeof(computer), cmp);

    printf("%s\n%s\n", &computers[0].name, &computers[1].name);
    free(computers);
    return 0;
}