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
  scanNewi(p);
  int n, min, mini, minn;
  while(p != 0) {
    min = INT_MAX;
    fd(i, sqrt(p), 0) {
      if(p%i == 0) {
        n = p/i;
        if(i+i+n+n < min) {
          min = i+i+n+n;
          mini = i;
          minn = n;
        }
      }
    }
    printf("Minimum perimeter is %d with dimensions %d x %d\n", min, mini, minn);
    scani(p);
  }
  return 0;
}
