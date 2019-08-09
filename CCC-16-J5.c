#include <stdio.h>
#include <stdlib.h>

int compReverse(const void *elem1, const void *elem2) {
    int *num1 = *((int*)elem1);
    int *num2 = *((int*)elem2);
    if(num1 < num2) return 1;
    if(num1 > num2) return -1;
    return 0;
}

int comp(const void *elem1, const void *elem2) {
    int *num1 = *((int*)elem1);
    int *num2 = *((int*)elem2);
    if(num1 < num2) return -1;
    if(num1 > num2) return 1;
    return 0;
}

int main() {
    int question, numPairs;
    scanf(" %i %i", &question, &numPairs);
    int *dmojCitizens = calloc(numPairs, sizeof(int));
    for(int i = 0; i < numPairs; i++) {
        scanf(" %i", &dmojCitizens[i]);
    }
    int *pegCitizens = calloc(numPairs, sizeof(int));
    for(int i = 0; i < numPairs; i++) {
        scanf(" %i", &pegCitizens[i]);
    }

    if(question == 1) {
        qsort(dmojCitizens, numPairs, sizeof(int), comp);
        qsort(pegCitizens, numPairs, sizeof(int), comp);
        int totalSpeed = 0;
        for(int i = 0; i < numPairs; i++) {
            if(dmojCitizens[i] > pegCitizens[i]) {
                totalSpeed += dmojCitizens[i];
            } else {
                totalSpeed += pegCitizens[i];
            }
        }
        printf("%d\n", totalSpeed);
    } else {
        qsort(dmojCitizens, numPairs, sizeof(int), compReverse);
        qsort(pegCitizens, numPairs, sizeof(int), compReverse);
        int dmoj=0, peg=0;
        int totalSpeed = 0;
        for(int i = 0; i < numPairs; i++) {
            if(dmoj < numPairs && (dmojCitizens[dmoj] > pegCitizens[peg] || peg >= numPairs)) {
                totalSpeed += dmojCitizens[dmoj];
                dmoj++;
            } else {
                totalSpeed += pegCitizens[peg];
                peg++;
            }
        }
        printf("%d\n", totalSpeed);
    }
    

    free(dmojCitizens);
    free(pegCitizens);

    return 0;
}