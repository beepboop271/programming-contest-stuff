#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#define ll long long
#define byte unsigned char
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b)
#define scani(a) scanf(" %d",&a)
#define scanii(a,b) scanf(" %d %d",&a,&b)
#define scanNewi(a) int a; scanf(" %d",&a)
#define scanNewii(a,b) int a,b; scanf(" %d %d",&a,&b)
#define fi(a, b, c) for(int a=b; a<c; ++a)
#define fd(a, b, c) for(int a=b; a>c; --a)

#define M 200010

int a[M];
int stored[450][M];

int main() {
    fi(i, 0, 450) {
        fi(j, 0, M) {
            stored[i][j] = 0;
        }
    }

    scanNewii(n, q);
    int chunkSize = sqrt(n);
    int query, l, r, x, u, v;
    int count;
    if(chunkSize < 5) {
        for(int i = 1; i <= n; ++i) {
            scani(a[i]);
        }
        fi(i, 0, q) {
            scani(query);
            if(query == 1) {
                scanf(" %d%d%d", &l, &r, &x);
                count = 0;
                for(int j = l; j <= r; ++j) {
                    if(a[j]%x == 0) {
                        ++count;
                    }
                }
                printi(count);
            } else {
                scanii(u, v);
                a[u] = v;
            }
        }
    } else {
        int death;
        int c = 0;
        for(int i = 1; i <= n; ++i) {
            if(i%chunkSize == 0) {
                ++c;
            }
            scani(a[i]);
            death = sqrt(a[i]);

            if(death*death == a[i]) {
                ++stored[c][death];
                fi(j, 1, death) {
                    if(a[i]%j == 0) {
                        ++stored[c][j];
                        ++stored[c][a[i]/j];
                    }
                }
            } else {
                fi(j, 1, death+1) {
                    if(a[i]%j == 0) {
                        ++stored[c][j];
                        ++stored[c][a[i]/j];
                    }
                }
            }
        }

        int killme1, killme2;
        fi(i, 0, q) {
            scani(query);
            if(query == 1) {
                count = 0;
                scanf(" %d%d%d", &l, &r, &x);
                while(l <= r) {
                    if(l%chunkSize == 0 && l+chunkSize-1 <= r) {
                        count += stored[l/chunkSize][x];
                        l += chunkSize;
                        // printf("found chunk %d at %d, %d, %d\n", (l-chunkSize)/chunkSize, l-chunkSize, stored[l/chunkSize][x], count);
                    } else {
                        if(a[l]%x == 0) {
                            ++count;
                            // printf("found one at %d, %d\n", l, count);
                        }
                        ++l;
                    }
                }
                printi(count);
            } else {
                scanii(u, v);
                c = u/chunkSize;
                killme1 = sqrt(a[u]);
                killme2 = sqrt(v);

                if(killme1*killme1 == a[u]) {
                    --stored[c][killme1];
                    fi(j, 1, killme1) {
                        if(a[u]%j == 0) {
                            --stored[c][j];
                            --stored[c][a[u]/j];
                        }
                    }
                } else {
                    fi(j, 1, killme1+1) {
                        if(a[u]%j == 0) {
                            --stored[c][j];
                            --stored[c][a[u]/j];
                        }
                    }
                }

                if(killme2*killme2 == v) {
                    ++stored[c][killme2];
                    fi(j, 1, killme2) {
                        if(v%j == 0) {
                            ++stored[c][j];
                            ++stored[c][v/j];
                        }
                    }
                } else {
                    fi(j, 1, killme2+1) {
                        if(v%j == 0) {
                            ++stored[c][j];
                            ++stored[c][v/j];
                        }
                    }
                }

                a[u] = v;
            }
        }
    }

    return 0;
}
