#include <stdbool.h>
#include <stdio.h>

int Distance(int x1, int y1, int x2, int y2) {
  return (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
}

int main() {
  bool first = true;
  int xa, ya, xb, yb, xc, yc, xd, yd;
  while (scanf("%d%d%d%d%d%d%d%d", &xa, &ya, &xb, &yb, &xc, &yc, &xd, &yd) !=
         EOF) {
    int distance_ad = Distance(xa, ya, xd, yd);
    int distance_bd = Distance(xb, yb, xd, yd);
    int distance_cd = Distance(xc, yc, xd, yd);

    int answer;
    if (distance_ad == distance_bd && distance_bd == distance_cd) {
      answer = 0;
    } else if (distance_ad < distance_bd && distance_ad < distance_cd) {
      answer = 1;
    } else if (distance_bd < distance_ad && distance_bd < distance_cd) {
      answer = 2;
    } else if (distance_cd < distance_ad && distance_cd < distance_bd) {
      answer = 3;
    } else if (distance_ad == distance_bd) {
      answer = 4;
    } else if (distance_ad == distance_cd) {
      answer = 5;
    } else {
      answer = 6;
    }

    if (first) {
      first = false;
    } else {
      printf(" ");
    }
    printf("%d", answer);
  }

  printf("\n");
  return 0;
}
