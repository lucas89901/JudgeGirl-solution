#include <stdio.h>
#include <string.h>

int main() {
  const char kDelimiters[] = " .,!?;:[](){}\n";
  char tokenized[2][1000][105];
  int sizes[2] = {0, 0};
  for (int i = 0; i < 2; ++i) {
    char buffer[100005];
    fgets(buffer, 100005, stdin);
    for (char *token = strtok(buffer, kDelimiters); token;
         token = strtok(NULL, kDelimiters)) {
      // fprintf(stderr, "token=%s\n", token);
      strcpy(tokenized[i][sizes[i]++], token);
    }
  }

  for (int index0 = 0, index1 = 0; index0 < sizes[0] || index1 < sizes[1];) {
#ifdef GP_DEBUG
    fprintf(stderr,
            "index0=%d, tokenized[0][index0]=%s, index1=%d, "
            "tokenized[1][index1]=%s\n",
            index0, tokenized[0][index0], index1, tokenized[1][index1]);
#endif
    if (index1 == sizes[1] ||
        (index0 < sizes[0] &&
         strcmp(tokenized[0][index0], tokenized[1][index1]) < 0)) {
      printf("%s", tokenized[0][index0++]);
    } else {
      printf("%s", tokenized[1][index1++]);
    }
  }
  return 0;
}
