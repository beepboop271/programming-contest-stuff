#include <bits/stdc++.h>
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

#define lc std::list<char>

int main() {
  lc playlist;
  for(char c = 'A'; c <= 'E'; ++c) {
    playlist.push_back(c);
  }

  scanNewi(button);
  int reps;
  char tmp;
  while(button != 4) {
    scani(reps);
    if(button == 1) {
      fi(i, 0, reps) {
        playlist.push_back(playlist.front());
        playlist.pop_front();
      }
    } else if(button == 2) {
      fi(i, 0, reps) {
        playlist.push_front(playlist.back());
        playlist.pop_back();
      }
    } else if(button == 3) {
      if(reps%2 != 0) {
        tmp = playlist.front();
        playlist.pop_front();
        playlist.insert(++playlist.begin(), tmp);
      }
    }
    scani(button);
  }

  lc::iterator it = playlist.begin();
  fi(i, 0, 5) {
    printf("%c ", *it);
    it++;
  }
  printf("\n");

  return 0;
}
