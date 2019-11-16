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
  scannewii(lim, seen);
  int over = seen-lim;
  if(over < 1) {
    printf("Congratulations, you are within the speed limit!\n");
  } else if(over >= 1 && over <= 20) {
    printf("You are speeding and your fine is $100.\n");
  } else if(over >= 21 && over <= 30) {
    printf("You are speeding and your fine is $270.\n");
  } else {
    printf("You are speeding and your fine is $500.\n");
  }
  return 0;
}
