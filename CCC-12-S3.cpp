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

int counts[1010];

int main() {
  vi maxv = vi();
  vi secondv = vi();
  scanNewi(n);
  int r;
  int max = 0;
  fi(i, 0, n) {
    scani(r);
    ++counts[r];
    if(counts[r] >= max) {
      max = counts[r];
    }
  }
  
  int second = 0;
  fi(i, 1, 1001) {
    if(counts[i] == max) {
      maxv.push_back(i);
    } else if(counts[i] >= second) {
      second = counts[i];
    }
  }

  fi(i, 1, 1001) {
    if(counts[i] == second) {
      secondv.push_back(i);
    }
  }

  int maxdiff = 0;
  int a;
  fi(i, 0, maxv.size()) {
    fi(j, 0, secondv.size()) {
      a = abs(secondv[j]-maxv[i]);
      if(a > maxdiff) {
        maxdiff = a;
      }
    }
  }
  printi(maxdiff);
  return 0;
}
