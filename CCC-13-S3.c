#include <stdio.h>
#include <stdlib.h>
int teams[6];

int games[4][5];
// 0 0 0 0 0
// 0 0 1 1 1
// 0 0 0 1 1
// 0 0 0 0 1
// 1: 2, 3, 4
// 2: 3, 4
// 3: 4

void fill(int * start, int len, int n) {
    for(int i = 0; i < len; i++) {
        start[i] = n;
    }
}

int main() {
    for(int i = 0; i < 6; ++i) {
        teams[i] = 0;
    }
    // lol
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 5; ++j) {
            games[i][j] = 0;
        }
    }
    // l o l   h i g h   q u a l i t y   c o d e
    games[1][2] = 1;
    games[1][3] = 1;
    games[1][4] = 1;
    games[2][3] = 1;
    games[2][4] = 1;
    games[3][4] = 1;

    // input scores
    int t;
    scanf(" %d", &t);
    int g;
    scanf(" %d", &g);
    int a, b, sa, sb;
    for(int i = 0; i < g; i++) {
        scanf(" %d%d%d%d", &a, &b, &sa, &sb);
        games[a][b] = 0;
        if(sa > sb) {
            teams[a] += 3;
        } else if(sb > sa) {
            teams[b] += 3;
        } else {
            ++teams[a];
            ++teams[b];
        }
    }

    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 5; ++j) {
            printf("%d ", games[i][j]);
        }
        printf("\n");
    }


    return 0;
}