#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define pii std::pair<int, int>
#define vi std::vector<int>
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b)
#define scani(a) scanf(" %d",&a)
#define scanii(a,b) scanf(" %d %d",&a,&b)
#define scanNewi(a) int a; scanf(" %d",&a)
#define scanNewii(a,b) int a,b; scanf(" %d %d",&a,&b)
#define fi(var, initial, max) for(int var=initial; var<max; ++var)
#define fd(var, initial, least) for(int var=initial; var>least; --var)

#define ve std::vector<edge>

typedef struct {
  int dest;
  int time;
  int hullWear;
} edge;

typedef struct {
  int pos;
  int time;
  int hullLeft;
} state;

ve islands[2010];

int main() {
  scanNewii(k, n);
  scanNewi(m);

  fi(i, 1, n) {
    islands[i] = ve();
  }
  int a, b, t, h;
  fi(i, 0, m) {
    scanii(a, b);
    scanii(t, h);
    edge ab = {b, t, h};
    edge ba = {a, t, h};
    islands[a].push_back(ab);
    islands[b].push_back(ba);
  }

  scanNewii(source, dest);
  state nextState = {source, 0, k};
  std::queue<state> bfs;
  bfs.push(nextState);

  state current;
  edge nextEdge;
  int minTime = INT_MAX;
  while(!bfs.empty()) {
    current = bfs.front();
    bfs.pop();
    // printf("at %d t%d h%d\n", current.pos, current.time, current.hullLeft);
    if(current.pos == dest) {
      if(current.time < minTime) {
        minTime = current.time;
      }
    } else {
      fi(i, 0, islands[current.pos].size()) {
        nextEdge = islands[current.pos][i];
        if(nextEdge.hullWear < current.hullLeft) {
          state nextState = {nextEdge.dest, current.time+nextEdge.time, current.hullLeft-nextEdge.hullWear};
          bfs.push(nextState);
        }
      }
    }
  }
  if(minTime < INT_MAX) {
    printi(minTime);
  } else {
    printi(-1);
  }
  return 0;
}
