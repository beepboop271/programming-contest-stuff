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

int burgers[4] = {461, 431, 420, 0};
int drinks[4] = {130, 160, 118, 0};
int sides[4] = {100, 57, 70, 0};
int desserts[4] = {167, 266, 75, 0};

int main() {
  scanNewii(b, s);
  scanNewii(d, de);
  printf("Your total Calorie count is %d.\n", burgers[b-1]+drinks[d-1]+sides[s-1]+desserts[de-1]);
  return 0;
}
