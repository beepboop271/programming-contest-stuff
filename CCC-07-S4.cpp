#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define vi std::vector<int>
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b)
#define scani(a) scanf(" %d",&a)
#define scanii(a,b) scanf(" %d %d",&a,&b)
#define scanNewi(a) int a; scanf(" %d",&a)
#define scanNewii(a,b) int a,b; scanf(" %d %d",&a,&b)
#define fi(var, initial, max) for(int var=initial; var<max; ++var)
#define fd(var, initial, least) for(int var=initial; var>least; --var)

vi points[10010];
int paths[10010];

int main() {
  memset(paths, 0, sizeof(int)*10010);
  scanNewi(n);
  scanNewii(x, y);
  while(x != 0) {
    points[x].push_back(y);
    scanii(x, y);
  }
  
  fd(i, n-1, 0) {
    fi(j, 0, points[i].size()) {
      if(points[i][j] == n) {
        ++paths[i];
      } else {
        paths[i] += paths[points[i][j]];
      }
    }
  }

  printi(paths[1]);
  return 0;
}
