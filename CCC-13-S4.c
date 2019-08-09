#include <stdio.h>
#include <stdlib.h>

int main() {
    int numPeople, numComparisons;
    scanf("%d %d", &numPeople, &numComparisons);
    int *(*comparisons)[] = calloc(numComparisons, sizeof(int*));


    for(int i = 0; i < numComparisons; i++) {
        free(comparisons[i]);
    }
    free(comparisons);
    return 0;
}
