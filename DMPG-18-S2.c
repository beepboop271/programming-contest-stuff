#include <stdio.h>
#include <stdlib.h>
#define ll long long

int main() {
    ll N;
    scanf("%lli", &N);
    ll arr[N+10];
    for(ll i = 0; i < N; i++) {
        scanf("%lli", &arr[i]);
    }

    ll pastResponses[(N+10)/2];
    ll ptr = 0;

    ll kuteness = 0;
    ll max;
    if(N%2 == 0) {
        max = N/2;
    } else {
        max = N/2+1;
    }

    for(ll k = 1; k <= max; k++) {
        // for(ll i = 0; i <= N-k; i++) {
        //     for(ll n = 0; n < k; n++) {
        //         kuteness += arr[i+n];
        //     }
        // }
        for(ll i = k-1; i < N-k+1; i++) {
            kuteness += arr[i];
        }

        pastResponses[ptr++] = kuteness;
        //ptr++;
        printf("%lli\n", kuteness);
    }

    if(N%2 == 1) ptr--;

    while(ptr > 0) {
        //ptr--;
        printf("%lli\n", pastResponses[--ptr]);
    }
}
