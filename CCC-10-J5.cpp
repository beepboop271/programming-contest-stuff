#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define pii std::pair<int, int>
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b);
#define scani(vara) scanf(" %d",&vara)
#define scanii(vara,varb) scanf(" %d%d",&vara,&varb)
#define scanNewi(vara) int vara; scanf(" %d",&vara)
#define scanNewii(vara,varb) int vara,varb; scanf(" %d %d",&vara,&varb)
#define fi(var, initial, max) for(int var=initial; var<max; ++var)
#define fd(var, initial, least) for(int var=initial; var>least; --var)

bool in(int x, int y) {
  return x > 0 && x < 9 && y > 0 && y < 9;
}

int dirs[8][2] = {{2, 1}, {1, 2}, {-1, 2}, {-2, 1},
                  {-2, -1}, {-1, -2}, {1, -2}, {2, -1}};

int main() {
  scanNewii(sx, sy);
  scanNewii(ex, ey);
  std::pair<pii, int> start = std::make_pair(std::make_pair(sx, sy), 0);
  std::queue<std::pair<pii, int>> bfs;
  bfs.push(start);

  std::pair<pii, int> next;
  int cx, cy, nx, ny;
  bool visited[9][9];
  memset(visited, false, sizeof(bool)*9*9);
  while(!bfs.empty()) {
    next = bfs.front();
    cx = next.first.first;
    cy = next.first.second;
    bfs.pop();

    if(cx == ex && cy == ey) {
      printi(next.second);
      break;
    } else {
      fi(i, 0, 8) {
        nx = cx+dirs[i][0];
        ny = cy+dirs[i][1];
        if(in(nx, ny) && !visited[ny][nx]) {
          visited[ny][nx] = true;
          bfs.push(std::make_pair(std::make_pair(cx+dirs[i][0], cy+dirs[i][1]), next.second+1));
        }
      }
    }
  }

  return 0;
}
