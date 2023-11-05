#include <stdio.h>
#include <string.h>

int main() {
  char strings[100][1005];
  int size = 0;
  while (scanf("%s", strings[size++]) != EOF) {
  }
  --size;

  int answer = 0;
  for (int i = 0; i < size; ++i) {
#ifdef GP_DEBUG
    fprintf(stderr, "%s, %s, %s\n", strings[i], strings[(i + 1) % size],
            strings[(i - 1 + size) % size]);
    fprintf(stderr, "%lu, %lu\n", strcspn(strings[i], strings[(i + 1) % size]),
            strcspn(strings[i], strings[(i - 1 + size) % size]));
#endif
    answer += strcspn(strings[i], strings[(i + 1) % size]) -
              strcspn(strings[i], strings[(i - 1 + size) % size]);
  }
  printf("%d\n", answer);
  return 0;
}
