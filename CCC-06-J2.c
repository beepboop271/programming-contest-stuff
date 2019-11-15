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

int min(int a, int b) {
  if(a <= b) {
    return a;
  }
  return b;
}

int main() {
  scanNewii(m, n);
  int count = 0;
  fi(i, 1, min(10, m+1)) {
    fi(j, 1, min(10, n+1)) {
      if(i+j == 10) {
        ++count;
      }
    }
  }
  if(count == 1) {
    printf("There is 1 way to get the sum 10.\n");
  } else {
    printf("There are %d ways to get the sum 10.\n", count);
  }
  return 0;
}
