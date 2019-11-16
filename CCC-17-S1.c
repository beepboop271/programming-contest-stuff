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
#define getmin(a,b) (a<b?a:b)
#define getmax(a,b) (a>b?a:b)

byte swifts[100010];
byte sems[100010];

int main() {
  scannewi(n);
  fi(i, 0, n) {
    scanf(" %hhu", &swifts[i]);
  }
  int swsum = 0;
  int sesum = 0;
  int max = 0;
  fi(i, 0, n) {
    scanf(" %hhu", &sems[i]);
    swsum += swifts[i];
    sesum += sems[i];
    if(swsum == sesum) {
      max = i+1;
    }
  }
  printi(max);

  return 0;
}
