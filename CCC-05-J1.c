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

int max(int a, int b) {
  if(a >= b) {
    return a;
  }
  return b;
}

int main() {
  scanNewii(daytime, evening);
  scanNewi(weekend);

  double a = (max(0, daytime-100)*0.25)+(0.15*evening)+(0.2*weekend);
  double b = (max(0, daytime-250)*0.45)+(0.35*evening)+(0.25*weekend);

  printf("Plan A costs %.2f\n", a);
  printf("Plan B costs %.2f\n", b);
  if(a < b) {
    printf("Plan A is cheapest.\n");
  } else if(a == b) {
    printf("Plan A and B are the same price.\n");
  } else {
    printf("Plan B is cheapest.\n");
  }

  return 0;
}
