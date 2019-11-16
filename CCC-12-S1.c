#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
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

int main() {
  scannewi(j);
  if(j < 4) {
    printf("0\n");
  } else {
    // nCr  j-1 choose 3
    // n! / r!(n-r)!
    // n! / 6(n-3)!
    // (n)(n-1)(n-2) / 6
    printf("%d\n", ((j-1)*(j-2)*(j-3))/6);
  }

  return 0;
}
