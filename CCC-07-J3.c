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

int vals[11] = {0, 100, 500, 1000, 5000, 10000, 25000, 50000, 100000, 500000, 1000000};

int main() {
  int sum = 1691600;
  int num = 10;
  scanNewi(n);
  int b;
  fi(i, 0, n) {
    scani(b);
    sum -= vals[b];
    --num;
  }

  scani(b);
  if(b > (sum/(double)(num))) printf("deal\n");
  else printf("no deal\n");
  return 0;
}
