#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int arr[1000];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &arr[i]);
  }

  for (int i = n - 1; i >= 0; --i) {
    printf("%d", arr[i]);
    if (i != 0) {
      printf(" ");
    }
  }
  printf("\n");

  return 0;
}
