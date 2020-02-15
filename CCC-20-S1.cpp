#include <bits/stdc++.h>

int cmp(const void * a, const void * b) {
  return (*((int*)a) - *((int*)b));
}

int main() {
  int n;
  scanf(" %d", &n);

  int records[n][2];

  for (int i = 0; i < n; ++i) {
    scanf(" %d %d", &records[i][0], &records[i][1]);
  }

  qsort(records, n, sizeof(int)*2, cmp);

  double maxSpeed = -1;
  double speed;
  for (int i = 0; i < n-1; ++i) {
    speed = abs(records[i][1]-records[i+1][1])/((double)(records[i+1][0]-records[i][0]));
    if (speed > maxSpeed) {
      maxSpeed = speed;
    }
  }

  // printf("%llf\n", maxSpeed);
  std::cout << maxSpeed;

  return 0;
}
