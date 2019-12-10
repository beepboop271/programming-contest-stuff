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
#define minimum(a,b) (a<b?a:b)
#define maximum(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

int main() {
  scannewi(t);
  int n, sumdivs;
  double sr;
  fi(test, 0, t) {
    scani(n);

    sumdivs = 1;
    sr = sqrt(n);
    for(int i = 2; i <= sr; ++i) {
      if(n%i == 0) {
        if(i == sr) {
          sumdivs += i;
        } else {
          sumdivs += i;
          sumdivs += n/i;
        }
      }
    }

    if(sumdivs == n) {
      printf("%d is a perfect number.\n", n);
    } else if(sumdivs < n) {
      printf("%d is a deficient number.\n", n);
    } else {
      printf("%d is an abundant number.\n", n);
    }
  }

  return 0;
}
