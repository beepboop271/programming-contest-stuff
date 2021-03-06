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
#define test scannewi(t);fi(test,0,t)
#define testn(t) fi(test,0,t)
#define minimum(a,b) (a<b?a:b)
#define maximum(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

#define bst std::set<int>

int main() {
  scannewii(g, p);
  bst gates {};
  fi(i, 0, g) {
    gates.insert(i+1);
  }

  int gi;
  bst::iterator lb;
  fi(i, 0, p) {
    scani(gi);
    if(gates.empty()) {
      printi(i);
      return 0;
    }

    lb = gates.lower_bound(gi);
    if(lb == gates.end()) {
      gates.erase(*gates.rbegin());
    } else if(*lb == gi) {
      gates.erase(gi);
    } else if(lb == gates.begin()) {
      printi(i);
      return 0;
    } else {
      --lb;
      gates.erase(*lb);
    }
  }
  printi(p);

  return 0;
}
