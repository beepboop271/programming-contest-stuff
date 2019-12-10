#include <bits/stdc++.h>
#define ll long long
#define byte unsigned char
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b)
#define printiii(a,b,c) printf("%d %d %d\n",a,b,c)
#define scani(a) scanf(" %d",&a)
#define scanii(a,b) scanf(" %d %d",&a,&b)
#define scaniii(a,b,c) scanf(" %d %d %d",&a,&b,&c)
#define scannewi(a) int a;scanf(" %d",&a)
#define scannewii(a,b) int a,b;scanf(" %d %d",&a,&b)
#define scannewiii(a,b,c) int a,b,c;scanf(" %d %d %d",&a,&b,&c)
#define fi(var,initial,max) for(int var=initial;var<max;++var)
#define fd(var,initial,min) for(int var=initial;var>min;--var)
#define minimum(a,b) (a<b?a:b)
#define maximum(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

#define t std::tuple<int, int, int>
#define qt std::queue<t>
#define get(i,a) std::get<i,int>(a);
#define ok(x,y,s) (allowed[y][x] && (dist[y][x] == 0 || s < dist[y][x]))

char map[105][105];
bool allowed[105][105];
int dist[105][105];

int main() {
  scannewii(h, w);
  int sx, sy;
  fi(i, 0, h) {
    fi(j, 0, w) {
      scanf(" %c", &map[i][j]);
      if(map[i][j] != 'W' && map[i][j] != 'C') {
        allowed[i][j] = true;
        if(map[i][j] == 'S') {
          sx = j;
          sy = i;
          map[i][j] = 'S';
        }
      }
    }
  }

  int x, y;
  fi(i, 0, h) {
    fi(j, 0, w) {
      if(map[i][j] == 'C') {
        x = j;
        y = i;
        while(--x > 0) {
          if(map[y][x] == '.' || map[y][x] == 'S') {
            allowed[y][x] = false;
          } else if(map[y][x] == 'W') {
            break;
          }
        }
        x = j;
        while(++x < w) {
          if(map[y][x] == '.' || map[y][x] == 'S') {
            allowed[y][x] = false;
          } else if(map[y][x] == 'W') {
            break;
          }
        }
        x = j;
        while(--y > 0) {
          if(map[y][x] == '.' || map[y][x] == 'S') {
            allowed[y][x] = false;
          } else if(map[y][x] == 'W') {
            break;
          }
        }
        y = i;
        while(++y < h) {
          if(map[y][x] == '.' || map[y][x] == 'S') {
            allowed[y][x] = false;
          } else if(map[y][x] == 'W') {
            break;
          }
        }
      }
    }
  }

  qt bfs {};
  int step;
  t next;

  bfs.push(std::make_tuple(sx, sy, 0));
  if(!allowed[sy][sx]) {
    goto done;
  }
  allowed[sy][sx] = false;
  while(!bfs.empty()) {
    next = bfs.front();
    bfs.pop();

    x = get(0, next);
    y = get(1, next);
    step = get(2, next);
    // printiii(x, y, step);

    if(map[y][x] == 'S') {
      ++step;
    }
    if(map[y][x] == 'L' && ok(x-1, y, step)) {
      // printf("cl");
      bfs.push(std::make_tuple(x-1, y, step));
      dist[y][x-1] = step;
    } else if(map[y][x] == 'R' && ok(x+1, y, step)) {
      // printf("cr");
      bfs.push(std::make_tuple(x+1, y, step));
      dist[y][x+1] = step;
    } else if(map[y][x] == 'U' && ok(x, y-1, step)) {
      // printf("cu");
      bfs.push(std::make_tuple(x, y-1, step));
      dist[y-1][x] = step;
    } else if(map[y][x] == 'D' && ok(x, y+1, step)) {
      // printf("cd");
      bfs.push(std::make_tuple(x, y+1, step));
      dist[y+1][x] = step;
    } else if(map[y][x] == '.' || map[y][x] == 'S') {
      if(map[y][x] != 'S') {
        ++step;
      }
      if(ok(x-1, y, step)) {
        // printf("l");
        bfs.push(std::make_tuple(x-1, y, step));
        dist[y][x-1] = step;
      }
      if(ok(x+1, y, step)) {
        // printf("r");
        bfs.push(std::make_tuple(x+1, y, step));   
        dist[y][x+1] = step;       
      }
      if(ok(x, y-1, step)) {
        // printf("u");
        bfs.push(std::make_tuple(x, y-1, step));
        dist[y-1][x] = step;
      }
      if(ok(x, y+1, step)) {
        // printf("d");
        bfs.push(std::make_tuple(x, y+1, step));
        dist[y+1][x] = step;
      }
    }
  }
  
  done:
  fi(i, 0, h) {
    fi(j, 0, w) {
      if(map[i][j] == '.') {
        if(dist[i][j] > 0) {
          printi(dist[i][j]);
        } else if(dist[i][j] == 0) {
          printi(-1);
        }
      }
    }
  }
  return 0;
}
