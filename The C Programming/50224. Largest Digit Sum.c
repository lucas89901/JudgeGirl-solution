#include <limits.h>
#include <stdbool.h>
#include <stdio.h>

typedef struct Number {
  int value, digit_sum, digit_count;
} Number;

bool GreaterThan(const Number lhs, const Number rhs) {
  if (lhs.digit_sum == rhs.digit_sum) {
    if (lhs.digit_count == rhs.digit_count) {
      return lhs.value > rhs.value;
    }
    return lhs.digit_count < rhs.digit_count;
  }
  return lhs.digit_sum > rhs.digit_sum;
}

Number NumberFromValue(int value) {
  Number number = {value, 0, 0};
  while (value != 0) {
    number.digit_sum += value % 10;
    ++number.digit_count;
    value /= 10;
  }
  return number;
}

int main() {
  Number answer = {-1, -1, INT_MAX};
  int value;
  while (scanf("%d", &value) != EOF) {
    Number current = NumberFromValue(value);
    if (GreaterThan(current, answer)) {
      answer = current;
    }
  }
  printf("%d\n", answer.value);
  return 0;
}
