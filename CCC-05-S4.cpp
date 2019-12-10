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

#define uset std::unordered_set<std::string>

int main() {
  int n;
  char buf[30];
  test {
    scani(n);
    
    std::string msgs[n] {};
    fd(i, n-1, -1) {
      scanf(" %s", buf);
      std::string name {buf};
      msgs[i] = name;
    }
    
    uset s {};
    s.insert(msgs[0]);
    int depth = 0;
    int maxdepth = INT_MIN;
    fi(i, 1, n) {
      if(s.count(msgs[i]) == 0) {
        s.insert(msgs[i]);
        ++depth;
        maxdepth = maximum(maxdepth, depth);
      } else {
        --depth;
      }
    }

    printi(10*(n-maxdepth*2));
  }
  return 0;
}
