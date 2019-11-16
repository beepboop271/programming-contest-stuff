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

int cmp(const void * a, const void * b) {
  return *(int*)a - *(int*)b;
}

int main() {
  int vals[110];
  scannewi(n);
  fi(i, 0, n) {
    scani(vals[i]);
  }
  qsort(vals, n, sizeof(int), cmp);

  if(n%2 == 0) {
    for(int i = (n/2)-1, j = (n/2); i > -1; --i, ++j) {
      printf("%d %d ", vals[i], vals[j]);
    }
  } else {
    printf("%d ", vals[n/2]);
    for(int i = (n/2)-1, j = (n/2)+1; i > -1; --i, ++j) {
      printf("%d %d ", vals[j], vals[i]);
    }
  }
  printf("\n");
  return 0;
}
