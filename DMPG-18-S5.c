#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, q;
    scanf("%d%d", &n, &q);
    int a[n+2];
    for(int i = 0; i < n; i++) {
        scanf("%d", &a[i]);
    }

    int query, u, v, l, r, x, count;
    for(int i = 0; i < q; i++) {
        scanf("%d", &query);
        if(query == 1) {
            scanf("%d%d%d", &l, &r, &x);
            count = 0;
            for(int k = l-1; k <= r-1; k++) {
                if(a[k]%x == 0) {
                    //printf("%d %d\n", a[k], x);
                    count++;
                }
            }
            printf("%d\n", count);
        } else {
            scanf("%d%d", &u, &v);
            a[u-1] = v;
        }
    }
}
