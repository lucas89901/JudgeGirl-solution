#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

int64_t Sum(size_t l, size_t r, int64_t sum[]) {
  if (l == 0) {
    return sum[r];
  }
  return sum[r] - sum[l - 1];
}

void Solve(size_t l, size_t r, bool is_balancing_point[], int w[],
           int64_t sum[]) {
  if (r - l + 1 < 3) {
    return;
  }
  int64_t left_torque = 0;
  int64_t right_torque = 0;
  for (size_t i = l + 1; i <= r; ++i) {
    right_torque += w[i] * (i - l);
  }
  for (size_t i = l; i <= r && left_torque <= right_torque; ++i) {
    if (left_torque == right_torque) {
      is_balancing_point[i] = true;
      Solve(l, i - 1, is_balancing_point, w, sum);
      Solve(i + 1, r, is_balancing_point, w, sum);
    }
    left_torque += Sum(l, i, sum);
    right_torque -= Sum(i + 1, r, sum);
  }
}

int main() {
  int n;
  scanf("%d", &n);

  int w[n];
  int64_t sum[n];
  scanf("%d", &w[0]);
  sum[0] = w[0];
  for (int i = 1; i < n; ++i) {
    scanf("%d", &w[i]);
    sum[i] = sum[i - 1] + w[i];
  }

  bool is_balancing_point[n];
  memset(is_balancing_point, 0, sizeof(is_balancing_point));
  Solve(0, n - 1, is_balancing_point, w, sum);
  for (int i = 0; i < n; ++i) {
    if (is_balancing_point[i]) {
      printf("%d\n", i);
    }
  }
  return 0;
}
