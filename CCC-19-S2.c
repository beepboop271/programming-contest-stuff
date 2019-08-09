#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int isPrime(int n) {
    for(int i = 2; i <= sqrt(n); ++i) {
        if(n % i == 0) {
            return 0;
        }
    }
    return 1;
}

void findPair(int n) {
    for(int a = 2; a <= n; ++a) {
        if(isPrime(a) && isPrime(n+(n-a))) {
            printf("%d %d\n", a, n+(n-a));
            return;
        }
    }
}

int main() {
    int t, n;
    scanf(" %d", &t);
    for(int test = 0; test < t; ++test) {
        scanf(" %d", &n);
        findPair(n);
    }
    return 0;
}
