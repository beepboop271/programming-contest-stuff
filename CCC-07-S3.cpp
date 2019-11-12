#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define pii std::pair<int, int>
#define vi std::vector<int>
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b);
#define scani(vara) scanf(" %d",&vara)
#define scanii(vara,varb) scanf(" %d%d",&vara,&varb)
#define scanNewi(vara) int vara; scanf(" %d",&vara)
#define scanNewii(vara,varb) int vara,varb; scanf(" %d %d",&vara,&varb)
#define fi(var, initial, max) for(int var=initial; var<max; ++var)
#define fd(var, initial, least) for(int var=initial; var>least; --var)

int people[10010];

int main() {
  memset(people, -1, sizeof(int)*10010);
  scanNewi(n);
  int x, y;
  fi(i, 0, n) {
    scanii(x, y);
    people[x] = y;
  }

  scanii(x, y);
  int cur;
  int sep;
  bool found;
  while(!(x == 0 && y == 0)) {
    cur = x;
    sep = -1;
    found = false;
    while((cur != x && cur != -1) || (cur == x && sep == -1)) {
      // printii(cur, x);
      // printi(sep);
      if(cur == y) {
        found = true;
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

  return 0;
}
