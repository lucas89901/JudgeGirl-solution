#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

void Solve(int n, int k, int arr[], uint64_t sums[], uint64_t sum,
           uint64_t *answer) {
  if (n == 0) {
    *answer = sum;
    return;
  }

  for (int i = 0; i < k; ++i) {
    uint64_t old_sum_i = sums[i];
    sums[i] += arr[n - 1];
    uint64_t new_sum = sum - old_sum_i * old_sum_i + sums[i] * sums[i];
    if (new_sum < *answer) {
      Solve(n - 1, k, arr, sums, new_sum, answer);
    }
    sums[i] -= arr[n - 1];
  }
}

int main() {
  int n, k;
  scanf("%d %d", &n, &k);
  int arr[n];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  uint64_t sums[k];
  memset(sums, 0, sizeof(sums));
  uint64_t answer = UINT64_MAX;
  Solve(n, k, arr, sums, 0, &answer);
  printf("%lu\n", answer);
  return 0;
}
