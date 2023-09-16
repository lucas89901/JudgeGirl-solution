#include <stdbool.h>
#include <stdio.h>

int main() {
  int n;
  scanf("%d", &n);
  int a[1000];
  for (int i = 0; i < n; ++i) {
    scanf("%d", &a[i]);
  }

  for (int m = 1; m >= 0; --m) {
    bool first = true;
    for (int i = 0; i < n; ++i) {
      if (a[i] % 2 == m) {
        if (first) {
          first = false;
        } else {
          printf(" ");
        }

        printf("%d", a[i]);
      }
    }
    printf("\n");
  }
  return 0;
}
