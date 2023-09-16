#include <stdbool.h>
#include <stdio.h>

typedef struct ArithmeticSeries {
  int sum, count, first, diff;
} ArithmeticSeries;

bool GreaterThan(const ArithmeticSeries lhs, const ArithmeticSeries rhs) {
  if (lhs.sum == rhs.sum) {
    if (lhs.count == rhs.count) {
      return lhs.first > rhs.first;
    }
    return lhs.count > rhs.count;
  }
  return lhs.sum > rhs.sum;
}

int main() {
  int size;
  scanf("%d", &size);
  if (size == 1) {
    int answer;
    scanf("%d", &answer);
    printf("%d 1 %d\n", answer, answer);
    return 0;
  }

  ArithmeticSeries answer = {-1, -1, -1, -1};
  ArithmeticSeries now;
  int last;
  scanf("%d%d", &now.first, &last);
  now.sum = now.first + last;
  now.count = 2;
  now.diff = last - now.first;

  int n;
  for (int i = 0; i < size - 2; ++i) {
    scanf("%d", &n);
    if (n - last == now.diff) {
      now.sum += n;
      ++now.count;
    } else {
      if (GreaterThan(now, answer)) {
        answer = now;
      }
      now = (ArithmeticSeries){last + n, 2, last, n - last};
    }
    last = n;
  }
  if (GreaterThan(now, answer)) {
    answer = now;
  }

  printf("%d %d %d\n", answer.sum, answer.count, answer.first);
  return 0;
}
