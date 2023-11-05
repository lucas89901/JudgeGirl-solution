#include <stdio.h>
#include <string.h>

int main() {
  const char kDelimiters[] = " .,!?;:[](){}\n";

  char raw[2][100005];
  char *tokens[2][1000];
  int sizes[2] = {0, 0};
  for (int i = 0; i < 2; ++i) {
    fgets(raw[i], 100005, stdin);
    for (char *token = strtok(raw[i], kDelimiters); token;
         token = strtok(NULL, kDelimiters)) {
      tokens[i][sizes[i]++] = token;
    }
  }

  for (int index0 = 0, index1 = 0; index0 < sizes[0] || index1 < sizes[1];) {
    if (index1 == sizes[1] ||
        (index0 < sizes[0] &&
         strcmp(tokens[0][index0], tokens[1][index1]) < 0)) {
      printf("%s", tokens[0][index0++]);
    } else {
      printf("%s", tokens[1][index1++]);
    }
  }
  printf("\n");
  return 0;
}
