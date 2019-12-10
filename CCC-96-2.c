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
#define minimum(a,b) (a<b?a:b)
#define maximum(a,b) (a>b?a:b)
#define in(val,minval,maxval) (val>=minval&&val<=maxval)

void subtract(byte * num, int len, int amount) {
  if(num[len-1] < amount) {
    num[len-1] += 10-amount;
    subtract(num, len-1, 1);
  } else {
    num[len-1] -= amount;
    return;
  }
}

int main() {
  scannewi(t);
  char buf[55];
  byte num[55];
  int len;
  int digit;
  int n;
  fi(test, 0, t) {
    if(test > 0) printf("\n");

    scanf(" %s", buf);
    len = strlen(buf);

    fi(i, 0, len) {
      num[i] = (int)(buf[i]-'0');
    }

    while(len > 2) {
      while(num[0] == 0) {
        memmove(&num[0], &num[1], len--);
      }
      if(len <= 2) break;  //literally cancer

      fi(i, 0, len) {
        printf("%d", num[i]);
      }
      printf("\n");

      digit = num[(len--)-1];
      subtract(num, len, digit);
    }

    while(num[0] == 0) {
      memmove(&num[0], &num[1], len--);
    }

    if(len == 1) {
      n = num[0];
    } else {
      n = num[0]*10 + num[1];
    }
    printf("%d\n", n);

    if(n%11 == 0) {
      printf("The number %s is divisible by 11.\n", buf);
    } else {
      printf("The number %s is not divisible by 11.\n", buf);
    }
  }
  return 0;
}
