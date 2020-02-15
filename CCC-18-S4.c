#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
#define ll long long
#define byte unsigned char
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b)
#define printiii(a,b,c) printf("%d %d %d\n",a,b,c)
#define scani(a) scanf(" %d",&a)
#define scanii(a,b) scanf(" %d %d",&a,&b)
#define scaniii(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scannewi(a) int a;scanf(" %d",&a)
#define scannewii(a,b) int a,b;scanf(" %d %d",&a,&b)
#define scannewiii(a,b,c) int a,b,c;scanf(" %d %d %d",&a,&b,&c)
#define fi(var,initial,max) for(int var=initial;var<max;++var)
#define fd(var,initial,min) for(int var=initial;var>min;--var)
#define test scannewi(t);fi(test,0,t)
#define testn(t) fi(test,0,t)
#define minimum(a,b) (a<b?a:b)
#define maximum(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

ll dp[500010] = {0};

ll find(int w) {
  if (w <= 2) return 1;
  else if (w == 3) return 2;
  else if (w <= 500000 && dp[w] != 0) return dp[w];
  else {
    ll lmao = ceil(w/2.0);
    for (int i = 2; i <= w/2.0; ++i) {
      lmao += find(w/i);
    }
    if (w <= 500000) {
      dp[w] = lmao;
    }
    return lmao;
  }
}

int main() {
  scannewi(w);
  printf("%lld\n", find(w));

  return 0;
}
