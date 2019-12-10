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

char * tostr(int n) {
  if(n == 1000) {
    return "M";
  }
  char * buf = calloc(15, sizeof(char));
  int ones = n%10;
  int tens = (n/10)%10;
  int hundreds = (n/100);
  
  if(hundreds == 1) {
    strcat(buf, "C");
  } else if(hundreds == 2) {
    strcat(buf, "CC");
  } else if(hundreds == 3) {
    strcat(buf, "CCC");
  } else if(hundreds == 4) {
    strcat(buf, "CD");
  } else if(hundreds == 5) {
    strcat(buf, "D");
  } else if(hundreds == 6) {
    strcat(buf, "DC");
  } else if(hundreds == 7) {
    strcat(buf, "DCC");
  } else if(hundreds == 8) {
    strcat(buf, "DCCC");
  } else if(hundreds == 9) {
    strcat(buf, "CM");
  }

  if(tens == 1) {
    strcat(buf, "X");
  } else if(tens == 2) {
    strcat(buf, "XX");
  } else if(tens == 3) {
    strcat(buf, "XXX");
  } else if(tens == 4) {
    strcat(buf, "XL");
  } else if(tens == 5) {
    strcat(buf, "L");
  } else if(tens == 6) {
    strcat(buf, "LX");
  } else if(tens == 7) {
    strcat(buf, "LXX");
  } else if(tens == 8) {
    strcat(buf, "LXXX");
  } else if(tens == 9) {
    strcat(buf, "XC");
  }

  if(ones == 1) {
    strcat(buf, "I");
  } else if(ones == 2) {
    strcat(buf, "II");
  } else if(ones == 3) {
    strcat(buf, "III");
  } else if(ones == 4) {
    strcat(buf, "IV");
  } else if(ones == 5) {
    strcat(buf, "V");
  } else if(ones == 6) {
    strcat(buf, "VI");
  } else if(ones == 7) {
    strcat(buf, "VII");
  } else if(ones == 8) {
    strcat(buf, "VIII");
  } else if(ones == 9) {
    strcat(buf, "IX");
  }

  return buf;
}

int main() {
  char buf[30];
  int nums[2][15];
  int lens[2];
  int realnums[2];
  int num;
  int a;
  test {
    scanf(" %s", buf);
    num = 0;
    lens[0] = -1;
    fi(i, 0, strlen(buf)) {
      if(buf[i] == 'I') {
        nums[num][i-lens[0]-1] = 1;
      } else if(buf[i] == 'V') {
        nums[num][i-lens[0]-1] = 5;
      } else if(buf[i] == 'X') {
        nums[num][i-lens[0]-1] = 10;
      } else if(buf[i] == 'L') {
        nums[num][i-lens[0]-1] = 50;
      } else if(buf[i] == 'C') {
        nums[num][i-lens[0]-1] = 100;
      } else if(buf[i] == 'D') {
        nums[num][i-lens[0]-1] = 500;
      } else if(buf[i] == 'M') {
        nums[num][i-lens[0]-1] = 1000;
      } else if(buf[i] == '+') {
        lens[0] = i;
        num = 1;
      } else if(buf[i] == '=') {
        lens[1]= i-lens[0]-1;
      }
    }
    
    realnums[0] = 0;
    realnums[1] = 0;
    fi(n, 0, 2) {
      a = 0;
      while(a < lens[n]-1) {
        if(nums[n][a] == 1 && (nums[n][a+1] == 5 || nums[n][a+1] == 10)) {
          realnums[n] += nums[n][a+1]-1;
          a += 2;
        } else if(nums[n][a] == 10 && (nums[n][a+1] == 50 || nums[n][a+1] == 100)) {
          realnums[n] += nums[n][a+1]-10;
          a += 2;
        } else if(nums[n][a] == 100 && (nums[n][a+1] == 500 || nums[n][a+1] == 1000)) {
          realnums[n] += nums[n][a+1]-100;
          a += 2;
        } else {
          realnums[n] += nums[n][a];
          ++a;
        }
      }
      if(a == lens[n]-1) {
        realnums[n] += nums[n][a];
      }
    }

    if(realnums[0]+realnums[1] > 1000) {
      printf("%sCONCORDIA CUM VERITATE\n", buf);
    } else {
      char * hell = tostr(realnums[0]+realnums[1]);
      printf("%s%s\n", buf, hell);
      free(hell);
    }

  }
  return 0;
}
