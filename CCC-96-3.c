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
#define test scannewi(t);fi(test,0,t)
#define testn(t) fi(test,0,t)
#define minimum(a,b) (a<b?a:b)
#define maximum(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

void frickthis(int n, int k, byte * hell, int currentk, int pos) {
  if(currentk == k) {
    fi(i, 0, n) {
      printf("%d", hell[i]);
    }
    printf("\n");
  } else if (pos >= n) {
    return;
  } else {
    byte morehell[n];
    memcpy(morehell, hell, n);
    morehell[pos] = 1;
    frickthis(n, k, morehell, currentk+1, pos+1);
    byte hellagain[n];
    memcpy(hellagain, hell, n);
    frickthis(n, k, hellagain, currentk, pos+1);
  }
}

int main() {
  int n, k;
  test {
    scanii(n, k);
    printf("The bit patterns are\n");
    if(k == 0) {
      fi(i, 0, n) {
        printf("0");
      }
      printf("\n");
    } else if(k == n) {
      fi(i, 0, n) {
        printf("1");
      }
      printf("\n");
    } else {
      byte aaaaaaaa[n];
      memset(aaaaaaaa, 0, n);
      frickthis(n, k, aaaaaaaa, 0, 0);
    }
    printf("\n");
  }
  return 0;
}
