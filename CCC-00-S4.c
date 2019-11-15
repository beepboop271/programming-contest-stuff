#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <math.h>
#define ll long long
#define byte unsigned char
#define printi(a) printf("%d\n",a)
#define printii(a,b) printf("%d %d\n",a,b)
#define scani(a) scanf(" %d",&a)
#define scanii(a,b) scanf(" %d %d",&a,&b)
#define scanNewi(a) int a;scanf(" %d",&a)
#define scanNewii(a,b) int a,b;scanf(" %d %d",&a,&b)
#define fi(var, initial, max) for(int var=initial;var<max;++var)
#define fd(var, initial, least) for(int var=initial;var>least;--var)
#define fill(arr, size, val) for(int _i=0;_i<size;++_i) arr[_i]=val

int nclubs;
int * best;
int clubs[32];

int findmina(int distleft, int movesmade) {
  if(distleft < 0) {
    return INT_MAX;
  } else if(distleft == 0) {
    return movesmade;
  } else if(best[distleft] > 0 && best[distleft] <= movesmade) {
    return INT_MAX;
  } else {
    best[distleft] = movesmade;
    int min = INT_MAX;
    int res;
    fi(i, 0, nclubs) {
      res = findmina(distleft-clubs[i], movesmade+1);
      if(res < min) {
        min = res;
      }
    }
    return min;
  }
}
int findminb(int distleft, int movesmade) {
  if(distleft < 0) {
    return INT_MAX;
  } else if(distleft == 0) {
    return movesmade;
  } else {
    int min = INT_MAX;
    int res;
    fi(i, 0, nclubs) {
      res = findminb(distleft-clubs[i], movesmade+1);
      if(res < min) {
        min = res;
      }
    }
    return min;
  }
}

int main() {

  scanNewi(dist);
  scani(nclubs);
  fi(i, 0, nclubs) {
    scani(clubs[i]);
  }
  
  int minmoves;
  if(nclubs > 20) {
    best = calloc(5300, sizeof(int));
    minmoves = findmina(dist, 0);
    free(best);
  } else {
    // slightly faster without the calloc and stuff
    // for small test cases
    minmoves = findminb(dist, 0);
  }
  
  if(minmoves != INT_MAX) {
    printf("Roberta wins in %d strokes.\n", minmoves);
  } else {
    printf("Roberta acknowledges defeat.\n");
  }

  return 0;
}