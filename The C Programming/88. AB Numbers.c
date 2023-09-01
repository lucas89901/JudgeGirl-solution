#include <stdio.h>

int main() {
  char n1[5], n2[5];
  scanf("%s%s", n1, n2);

  int a = 0, b = 0;
  for (size_t i = 0; i < 4; ++i) {
    for (size_t j = 0; j < 4; ++j) {
      if (n1[i] == n2[j]) {
        if (i == j) {
          ++a;
        } else {
          ++b;
        }
        break;
      }
    }
  }
  printf("%dA%dB", a, b);

  return 0;
}
