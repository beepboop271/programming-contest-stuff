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

// stores people that are shorter
vi people[1000010];

int main() {
  scanNewii(n, m);
  for(int i = 1; i <= n; ++i) {
    people[i] = vi();
  }

  int x, y;
  fi(i, 0, m) {
    scanii(x, y);
    people[x].push_back(y);
  }

  scanNewii(p, q);

  std::queue<int> bfs;
  bfs.push(p);

  int next;
  while(!bfs.empty()) {
    next = bfs.front();
    bfs.pop();

    if(next == q) {
      printf("yes\n");
      return 0;
    } else {
      fi(i, 0, people[next].size()) {
        bfs.push(people[next][i]);
      }
    }
  }


  std::queue<int> bfs2;
  bfs2.push(q);

  while(!bfs2.empty()) {
    next = bfs2.front();
    bfs2.pop();

    if(next == p) {
      printf("no\n");
      return 0;
    } else {
      fi(i, 0, people[next].size()) {
        bfs2.push(people[next][i]);
      }
    }
  }

  printf("unknown\n");
  return 0;
}
