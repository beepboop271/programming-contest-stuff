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
#define min(a, b) (a<b?a:b)
#define max(a, b) (a>b?a:b)

#define pii std::pair<int, int>
#define umcp std::unordered_map<char, pii>

int main() {
  umcp gps;
  gps['A'] = pii(0, 0);
  gps['B'] = pii(1, 0);
  gps['C'] = pii(2, 0);
  gps['D'] = pii(3, 0);
  gps['E'] = pii(4, 0);
  gps['F'] = pii(5, 0);
  gps['G'] = pii(0, 1);
  gps['H'] = pii(1, 1);
  gps['I'] = pii(2, 1);
  gps['J'] = pii(3, 1);
  gps['K'] = pii(4, 1);
  gps['L'] = pii(5, 1);
  gps['M'] = pii(0, 2);
  gps['N'] = pii(1, 2);
  gps['O'] = pii(2, 2);
  gps['P'] = pii(3, 2);
  gps['Q'] = pii(4, 2);
  gps['R'] = pii(5, 2);
  gps['S'] = pii(0, 3);
  gps['T'] = pii(1, 3);
  gps['U'] = pii(2, 3);
  gps['V'] = pii(3, 3);
  gps['W'] = pii(4, 3);
  gps['X'] = pii(5, 3);
  gps['Y'] = pii(0, 4);
  gps['Z'] = pii(1, 4);
  gps[' '] = pii(2, 4);
  gps['-'] = pii(3, 4);
  gps['.'] = pii(4, 4);
  gps['+'] = pii(5, 4);

  std::string s;
  std::getline(std::cin, s);
  s += '+';

  int x = 0;
  int y = 0;
  int press = 0;
  pii next;
  fi(i, 0, s.length()) {
    next = gps[s[i]];
    press += abs(next.first-x)+abs(next.second-y);
    x = next.first;
    y = next.second;
  }

  printi(press);

  return 0;
}
