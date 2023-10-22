#include <stdio.h>

#include "Turing_Machine.h"

int main() {
  int n, p, K;
  scanf("%d%d%d", &n, &p, &K);
  int tape[n];
  for (int i = 0; i < n; i++) scanf("%d", &tape[i]);

  int *head = &tape[p];
  Turing_Machine(head, K);

  for (int i = 0; i < n; i++) printf("%d ", tape[i]);

  return 0;
}
