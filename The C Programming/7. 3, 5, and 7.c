#include <stdio.h>

int main() {
  int x;
  scanf("%d", &x);
  printf("%d\n", !(x % 3 == 0 && x % 5 == 0 && x % 7 != 0));
  return 0;
}
