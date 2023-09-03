#include <stdbool.h>
#include <stdio.h>

typedef struct Point {
  int x, y;
} Point;

Point Minus(Point a, Point b) {
  return (Point){a.x - b.x, a.y - b.y};
}

int Dot(Point a, Point b) {
  return a.x * b.x + a.y * b.y;
}

int Cross(Point a, Point b) {
  return a.x * b.y - a.y * b.x;
}

int main() {
  int n;
  scanf("%d", &n);

  for (int tc = 0; tc < n; ++tc) {
    Point points[4];
    for (int i = 0; i < 4; ++i) {
      scanf("%d%d", &points[i].x, &points[i].y);
    }

    // Consider points[3] as the origin, and sort the first three points
    // counterclockwise.
    for (int i = 2; i > 0; --i) {
      for (int j = 0; j < i; ++j) {
        if (Cross(Minus(points[j], points[3]),
                  Minus(points[j + 1], points[3])) < 0) {
          Point tmp = points[j];
          points[j] = points[j + 1];
          points[j + 1] = tmp;
        }
      }
    }

    bool all_sides_equal = true;
    bool all_right_angle = true;
    for (int i = 0; i < 3; ++i) {
      // Vectors for two adjacent edges.
      Point edge1 = Minus(points[(i + 1) % 4], points[i]);
      Point edge2 = Minus(points[(i + 2) % 4], points[(i + 1) % 4]);
      if (Dot(edge1, edge1) != Dot(edge2, edge2)) {
        all_sides_equal = false;
      }
      if (Dot(edge1, edge2) != 0) {
        all_right_angle = false;
      }
    }

    if (all_sides_equal) {
      if (all_right_angle) {
        printf("square\n");
      } else {
        printf("diamond\n");
      }
    } else {
      if (all_right_angle) {
        printf("rectangle\n");
      } else {
        printf("other\n");
      }
    }
  }
  return 0;
}
