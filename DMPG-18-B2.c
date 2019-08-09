#include <stdio.h>
#include <stdlib.h>

int main() {
    int n, m;
    scanf("%d%d", &n, &m);

    if(n >= m) printf("%d\n", m-1);
    else printf("%d\n", n);

    return 0;
}
