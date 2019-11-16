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

int main() {
  double w, h;
  scanf(" %lf %lf", &w, &h);
  double bmi = (w)/(h*h);
  if(bmi > 25) {
    printf("Overweight\n");
  } else if(bmi < 18.5) {
    printf("Underweight\n");
  } else {
    printf("Normal weight\n");
  }
  return 0;
}
