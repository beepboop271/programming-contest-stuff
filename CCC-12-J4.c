#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#include <string.h>
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
#define min(a,b) (a<b?a:b)
#define max(a,b) (a>b?a:b)

char shiftBack(char c, int s) {
  c -= s;
  if(c < 'A') {
    c = 'Z'-('A'-c-1);
  }
  return c;
}

int main() {
  scannewi(k);
  char buf[25];
  scanf(" %s", buf);
  int len = strlen(buf);

  fi(i, 1, len+1) {
    printf("%c", shiftBack(buf[i-1], (3*i)+k));
  }
  printf("\n");

  return 0;
}
