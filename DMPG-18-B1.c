#include <stdio.h>
#include <stdlib.h>

int main() {
    int p, c, v;
    scanf("%d%d%d", &p, &c, &v);

    if(p%3 == 0) p = p/3;
    else p = p/3+1;

    if(c%3 == 0) c = c/3;
    else c = c/3+1;

    if(v%3 == 0) v = v/3;
    else v = v/3+1;

    printf("%d\n", p+c+v);

    return 0;
}
