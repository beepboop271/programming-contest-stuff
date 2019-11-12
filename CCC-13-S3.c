#include <stdio.h>
#include <stdlib.h>

int teams[5];
int games[4][5];
int gamePairsLeft[6][2];
int gamesLeft;
int wins;
int t;

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

void copy(int * source, int * dest, int len) {
    for(int i = 0; i < len; ++i) {
        dest[i] = source[i];
    }
}

void asdfasdfasg(int game, int * scores) {
    if(game == gamesLeft) {
        for(int i = 0; i < 5; ++i) {
            if(i != t && scores[i] >= scores[t]) {
                return;
            }
        }
        ++wins;
    } else {
        int newScore1[5];
        copy(scores, newScore1, 5);
        newScore1[gamePairsLeft[game][0]] += 3;
        asdfasdfasg(game+1, &newScore1[0]);

        int newScore2[5];
        copy(scores, newScore2, 5);
        newScore2[gamePairsLeft[game][1]] += 3;
        asdfasdfasg(game+1, &newScore2[0]);

        int newScore3[5];
        copy(scores, newScore3, 5);
        newScore3[gamePairsLeft[game][0]] += 1;
        newScore3[gamePairsLeft[game][1]] += 1;
        asdfasdfasg(game+1, &newScore3[0]);
    }
}

int main() {
    wins = 0;
    fill(&teams[0], 6, 0);
    fill(&games[0][0], 4*5, 0);

    // l o l   h i g h   q u a l i t y   c o d e
    games[1][2] = 1;
    games[1][3] = 1;
    games[1][4] = 1;
    games[2][3] = 1;
    games[2][4] = 1;
    games[3][4] = 1;

    // input scores
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

    gamesLeft = 0;
    for(int i = 0; i < 4; ++i) {
        for(int j = 0; j < 5; ++j) {
            if(games[i][j] == 1) {
                gamePairsLeft[gamesLeft][0] = i;
                gamePairsLeft[gamesLeft][1] = j;
                ++gamesLeft;
            }
            // printf("%d ", games[i][j]);
        }
        // printf("\n");
    }

    asdfasdfasg(0, &teams[0]);
    printf("%d\n", wins);

    // for(int i = 0; i < gamesLeft; ++i) {
    //     printf("[%d, %d]\n", gamePairsLeft[i][0], gamePairsLeft[i][1]);
    // }

    return 0;
}