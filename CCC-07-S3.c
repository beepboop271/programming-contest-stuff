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
  int * people = calloc(10010, sizeof(int));
  scanNewi(n);
  int x, y;
  fi(i, 0, n) {
    scanii(x, y);
    people[x] = y;
  }

  scanii(x, y);
  int cur;
  int sep;
  int found;
  while(!(x == 0 && y == 0)) {
    cur = x;
    sep = -1;
    found = 0;
    while((cur != x && cur != 0) || (cur == x && sep == -1)) {
      if(cur == y) {
        found = 1;
      }
      cur = people[cur];
      if(!found) {
        ++sep;
      }
    }
    if(found && cur == x) {
      printf("Yes %d\n", sep);
    } else {
      printf("No\n");
    }
    scanii(x, y);
  }
  
  free(people);
  return 0;
}
