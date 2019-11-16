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

int count1[26];
int count2[26];

int main() {
  char buf1[110];
  char buf2[110];
  scanf(" %s", buf1);
  scanf(" %s", buf2);
  if(strlen(buf1) != strlen(buf1)) {
    printf("N\n");
    return 0;
  } else {
    int idx;
    fi(i, 0, strlen(buf1)) {
      idx = (int)(buf2[i]-'a');
      ++count1[(int)(buf1[i]-'a')];
      if(buf2[i] != '*') {
        ++count2[idx];
      }
    }
    fi(i, 0, strlen(buf1)) {
      idx = (int)(buf2[i]-'a');
      if(count2[idx] > count1[idx]) {
        printf("N\n");
        return 0;
      }
    }
  }
  printf("A\n");
  return 0;
}
