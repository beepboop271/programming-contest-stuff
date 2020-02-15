#include <bits/stdc++.h>

#define maximum(a,b) (a>b?a:b)

#define pii std::pair<int, int>
#define q std::queue<pii>

int main() {
  int m, n;
  scanf(" %d %d", &m, &n);
  // printf("%d %d\n", m, n);
  int map[m+1][n+1] {0};

  for (int row = 1; row <= m; ++row) {
    for (int col = 1; col <= n; ++col) {
      scanf(" %d", &map[row][col]);
    }
  }

  bool visited[m+1][n+1] {false};

  q bfs;
  bfs.push(pii(1, 1));

  pii next;
  int nextm, nextn, val;
  int p1, p2;
  while (!bfs.empty()) {
    next = bfs.front();
    bfs.pop();
    nextm = next.first;
    nextn = next.second;
    // printf("%d %d\n", nextm, nextn);
    val = map[nextm][nextn];

    if (nextm == m && nextn == n) {
      printf("yes\n");
      return 0;
    } else {
      // printf("%d\n", val/maximum(m, n));
      for (int i = maximum(1, val/maximum(m, n)); i <= sqrt(val); ++i) {
        if (val%i == 0) {
          p1 = val/i;
          p2 = val/p1;
          // printf("%d %d\n", p1, p2);
          if (p1 <= m && p2 <= n && !visited[p1][p2]) {
            // printf("add %d %d\n", p1, p2);
            visited[p1][p2] = true;
            bfs.push(pii(p1, p2));
          }
          // printf("%d %d\n", m, n);
          if (p2 <= m && p1 <= n && !visited[p2][p1]) {
            // printf("add %d %d\n", p2, p1);
            visited[p2][p1] = true;
            bfs.push(pii(p2, p1));
          }
        }
      }
    }
  }

  printf("no\n");

  return 0;
}