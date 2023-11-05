#include <stdio.h>
#include <string.h>

int main() {
  const char kDelimiters[] = " .,!?;:[](){}\n";
  const int kMaxSize = 100005;

  char raw[2][kMaxSize];
  char *tokens[2][1000];
  int sizes[2] = {0, 0};
  for (int i = 0; i < 2; ++i) {
    fgets(raw[i], kMaxSize, stdin);
    for (char *token = strtok(raw[i], kDelimiters); token;
         token = strtok(NULL, kDelimiters)) {
      tokens[i][sizes[i]++] = token;
    }
  }

  char answer[200005] = "";
  for (int index0 = 0, index1 = 0; index0 < sizes[0] || index1 < sizes[1];) {
    if (index1 == sizes[1] ||
        (index0 < sizes[0] &&
         strcmp(tokens[0][index0], tokens[1][index1]) < 0)) {
      strcat(answer, tokens[0][index0++]);
    } else {
      strcat(answer, tokens[1][index1++]);
    }
  }
  printf("%s\n", answer);
}

/*
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

  char answer[200005] = "";
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
      strcat(answer, tokenized[0][index0++]);
    } else {
      strcat(answer, tokenized[1][index1++]);
    }
  }
  printf("%s\n", answer);
  return 0;
}
*/
