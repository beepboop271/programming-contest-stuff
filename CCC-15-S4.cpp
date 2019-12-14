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
#define pq std::priority_queue<state,std::vector<state>,compareState>

typedef struct {
  int dest;
  int time;
  int hullWear;
} edge;

typedef struct {
  int island;
  int time;
  int hullLeft;
} state;

class compareState {
  public:
    compareState() {
    }
  bool operator() (const state & lhs, const state & rhs) const {
    return (lhs.time<rhs.time);
  }
};

ve islands[2010];

int dist[2010][210];

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
    islands[a].push_back({b, t, h});
    islands[b].push_back({a, t, h});
  }

  scanNewii(source, dest);

  fi(i, 0, 2010) {
    fi(j, 0, 210) {
      dist[i][j] = INT_MAX;
    }
  }

  pq q {};
  q.push({source, 0, k});

  // dist[0][k] = 0;
  fi(i, 0, k) {
    dist[1][i] = 0;
  }

  int best = INT_MAX;
  state next;
  edge nextEdge;
  int wear;
  int time;

  while(!q.empty()) {
    next = q.top();
    q.pop();
    // printf("%d %d %d\n", next.island, next.time, next.hullLeft);

    if(next.time < best) {
      if(next.island == dest) {
        dist[dest][next.hullLeft] = next.time;
        best = next.time;
      } else {
        fi(i, 0, islands[next.island].size()) {
          nextEdge = islands[next.island][i];
          wear = next.hullLeft-nextEdge.hullWear;
          time = next.time+nextEdge.time;
          if(wear > 0) {
            if(time < dist[nextEdge.dest][wear]) {
              // printf("help %d %d %d\n", nextEdge.dest, time, dist[nextEdge.dest][wear]);
              // dist[nextEdge.dest][wear] = time;
              fd(j, wear, -1) {
                dist[nextEdge.dest][j] = time;
              }
              q.push({nextEdge.dest, time, wear});
            }
          }
        }
      }
    }
  }

  if(best == INT_MAX) {
    printf("-1\n");
  } else {
    printf("%d\n", best);
  }

  return 0;
}
