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
#define fi(var, initial, max) for(int var=initial; var<max; ++var)
#define fd(var, initial, least) for(int var=initial; var>least; --var)

int isRSA(int n) {
  int numdivs = 2;
  int sr = (int)sqrt(n);
  int max;
  if(sr*sr == n) {
    max = sr;
    numdivs = 3;
  } else {
    max = sr+1;
  }

  fi(i, 2, max) {
    if(n%i == 0) {
      numdivs += 2;
      if(numdivs > 4) {
        return 0;
      }
    }
  }
  if(numdivs == 4) {
    return 1;
  }
  return 0;
}

int main() {
  scanNewii(a, b);

  int count = 0;
  fi(i, a, b+1) {
    if(isRSA(i)) {
      ++count;
    }
  }

  printf("The number of RSA numbers between %d and %d is %d\n", a, b, count);
  return 0;
}
