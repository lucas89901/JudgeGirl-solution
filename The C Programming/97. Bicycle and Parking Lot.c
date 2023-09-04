#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

typedef struct ParkingLot {
  int x, y, capacity, stored;
} ParkingLot;

void Swap(int *a, int *b) {
  int tmp = *a;
  *a = *b;
  *b = tmp;
}

int Distance(int x1, int y1, int x2, int y2) {
  return abs(x1 - x2) + abs(y1 - y2);
}

bool LessThan(ParkingLot lhs, ParkingLot rhs, int bicycle_x, int bicycle_y) {
  int lhs_distance = Distance(lhs.x, lhs.y, bicycle_x, bicycle_y);
  int rhs_distance = Distance(rhs.x, rhs.y, bicycle_x, bicycle_y);
  if (lhs_distance == rhs_distance) {
    if (lhs.x == rhs.x) {
      return lhs.y < rhs.y;
    }
    return lhs.x < rhs.x;
  }
  return lhs_distance < rhs_distance;
}

int main() {
  int n;
  scanf("%d", &n);
  ParkingLot parking_lots[10];
  for (int i = 0; i < n; ++i) {
    scanf("%d%d%d", &parking_lots[i].x, &parking_lots[i].y,
          &parking_lots[i].capacity);
    parking_lots[i].stored = 0;
  }

  int m;
  scanf("%d", &m);
  for (int i = 0; i < m; ++i) {
    int x, y;
    scanf("%d%d", &x, &y);

    // Index of candidate parking lots, sorted by priority described in
    // description.
    int candidates[10];
    for (int j = 0; j < n; ++j) {
      candidates[j] = j;
    }
    // Bubble sort.
    for (int j = n - 1; j > 0; --j) {
      for (int k = 0; k < j; ++k) {
        if (!LessThan(parking_lots[candidates[k]],
                      parking_lots[candidates[k + 1]], x, y)) {
          Swap(&candidates[k], &candidates[k + 1]);
        }
      }
    }

    for (int j = 0; j < n; ++j) {
      if (parking_lots[candidates[j]].stored <
          parking_lots[candidates[j]].capacity) {
        ++parking_lots[candidates[j]].stored;
        break;
      }
    }
  }

  for (int i = 0; i < n; ++i) {
    printf("%d\n", parking_lots[i].stored);
  }

  return 0;
}
