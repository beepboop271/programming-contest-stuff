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
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

int main() {
  scannewi(tests);
  int * x;
  int * y;
  int n;
  
  fi(test, 0, tests) {
    scani(n);
    x = calloc(n, sizeof(int));
    y = calloc(n, sizeof(int));
    fi(i, 0, n) {
      scani(x[i]);
    }
    fi(i, 0, n) {
      scani(y[i]);
    }

    int i = 0;
    int j = n-1;
    int highest = 0;
    while(i < n) {
      j = n-1;
      while(j >= i) {
        if(y[j] >= x[i] && j-i > highest) {
          highest = j-i;
          break;
        }
        --j;
      }
      ++i;
    }

    printf("The maximum distance is %d\n", highest);

    free(x);
    free(y);
  }
  return 0;
}
