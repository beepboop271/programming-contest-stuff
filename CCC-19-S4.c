// i really hope nobody looks at this garbage...
// unless of course it works well lmao

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define ll long long

ll maxScore = 0;

ll getScore(int minDays, int plan[], int * scores) {
    printf("check ");
    for(int lol = 0; lol < minDays; ++lol) {
        printf("%d ", plan[lol]);
    }
    printf("\n");
    int indexOffset = 0;
    ll score = 0;
    ll day;
    for(int i = 0; i < minDays; ++i) {
        day = 0;
        for(int j = indexOffset; j < indexOffset+plan[i]; ++j) {
            if(scores[j] > day) {
                day = scores[j];
            }
        }
        score += day;
        indexOffset += plan[i];
    }
    return score;
}

void solveDay(int k, int counts[], int * maxVisitValues, int minDays, int day, int n, int visited, int plan[], int * scores) {
    for(int i = 1; i < k; ++i) {
        for(int lol = 0; lol < minDays; ++lol) {
            if(lol == day) {
                printf("%d ", i);
            } else {
                printf("%d ", plan[lol]);
            }
        }
        printf("\n");
        if(counts[i]+1 <= maxVisitValues[i] && (minDays-day-1)*k >= n-visited-i) {
            ++counts[i];
            visited += i;
            plan[day] = i;
            solveDay(k, counts, maxVisitValues, minDays, day+1, n, visited, plan, scores);
            --counts[i];
            visited -= i;
            plan[day] = 0;
        }
    }
    if(day == 0) {
        return;
    } else if((minDays-day)*k == n-visited) {
        int last = plan[day-1];
        if(counts[last] == 1 && plan[0] == k) {
            return;
        }
        for(int i = day; i < minDays; ++i) {
            plan[i] = k;
        }
        ll score = getScore(minDays, plan, scores);
        if(score > maxScore) {
            maxScore = score;
        }
        for(int i = day; i < minDays; ++i) {
            plan[i] = last;
            plan[i-1] = k;
            score = getScore(minDays, plan, scores);
            if(score > maxScore) {
                maxScore = score;
            }
        }

        plan[day-1] = last;
        for(int i = day; i < minDays; ++i) {
            plan[i] = 0;
        }
        
        // for(int lol = 0; lol < minDays; ++lol) {
        //     printf("%d ", plan[lol]);
        // }
        // printf("\n");
    }
}

int main() {
    int n, k;
    scanf(" %d %d", &n, &k);

    int * scores = malloc(sizeof(int) * n);
    for(int i = 0; i < n; ++i) {
        scanf(" %d", &scores[i]);
    }

    int minDays = ceil(((double) n)/ k);
    int c = (-k*minDays) + n;
    int * maxVisitValues = malloc((sizeof(int) * k) + 1);
    for(int i = 1; i < k; ++i) {
        maxVisitValues[i] = c/(i-k);
    }

    int counts[k+1];
    for(int i = 0; i < k+1; ++i) {
        counts[i] = 0;
    }
    int plan[minDays];
    for(int i = 0; i < minDays; ++i) {
        plan[i] = 0;
    }

    solveDay(k, counts, maxVisitValues, minDays, 0, n, 0, plan, scores);
    // printf("oof\n");
    for(int i = 0; i < minDays-2; ++i) {
        for(int j = 0; j < k+1; ++j) {
            counts[j] = 0;
        }
        for(int j = 0; j < minDays; ++j) {
            if(j <= i) {
                plan[j] = k;
            } else {
                plan[j] = 0;
            }
        }
        
        // for(int lol = 0; lol < minDays; ++lol) {
        //     printf("%d ", plan[lol]);
        // }
        // printf("\n");
        solveDay(k, counts, maxVisitValues, minDays, i+1, n, k*(i+1), plan, scores);
    }

    printf("%lld\n", maxScore);

    free(scores);
    free(maxVisitValues);
    return 0;
}