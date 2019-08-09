#include <stdio.h>
#include <stdlib.h>

int main() {
    int a, b, c, d, s;
    scanf("%d%d%d%d%d", &a, &b, &c, &d, &s);

    int nikkyNet, nikkyTotal, byronNet, byronTotal;
    nikkyNet = a-b;
    nikkyTotal = a+b;
    byronNet = c-d;
    byronTotal = c+d;

    int nikky, byron;
    nikky = ((s/nikkyTotal)*nikkyNet);
    byron = ((s/byronTotal)*byronNet);
    if(s%nikkyTotal > a) {
        nikky += a;
        nikky -= (s%nikkyTotal)-a;
    } else {
        nikky += s%nikkyTotal;
    }
    if(s%byronTotal > c) {
        byron += c;
        byron -= (s%byronTotal)-c;
    } else {
        byron += s%byronTotal;
    }

    if(nikky > byron) {
        printf("Nikky\n");
    } else if (nikky == byron) {
        printf("Tied\n");
    } else {
        printf("Byron\n");
    }

    return 0;
}