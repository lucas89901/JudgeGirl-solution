#include <ctype.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Frequency {
  char name[25];
  int frequency;
} Frequency;

int Find(Frequency frequencies[], int size, char target[]) {
  for (int i = 0; i < size; ++i) {
    if (strncmp(frequencies[i].name, target, 24) == 0) {
      return i;
    }
  }
  return -1;
}

const char kReserved[12][7] = {"if",     "else", "while", "for",
                               "switch", "case", "break", "return",
                               "void",   "int",  "float", "char"};
inline bool IsReservedWord(char word[]) {
  for (int i = 0; i < 12; ++i) {
    if (strcmp(kReserved[i], word) == 0) {
      return true;
    }
  }
  return false;
}

int main() {
  const char kValidNameChar[] =
      "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";
  const char kValidNameStartChar[] =
      "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ_";

  Frequency frequencies[30];
  memset(frequencies, 0, sizeof(frequencies));
  int frequencies_size = 0;
  char buffer[100000];
  while (fgets(buffer, 100000, stdin)) {
    for (char *token = strpbrk(buffer, kValidNameStartChar); token;) {
      int token_size = strspn(token, kValidNameChar);
      token[token_size] = '\0';
#ifdef GP_DEBUG
      fprintf(stderr, "%s, %d\n", token, token_size);
#endif
      if (IsReservedWord(token)) {
        token = strpbrk(token + token_size + 1, kValidNameStartChar);
        continue;
      }
      int found = Find(frequencies, frequencies_size, token);
      if (found == -1) {
        strncpy(frequencies[frequencies_size].name, token, 24);
        frequencies[frequencies_size++].frequency = 1;
      } else {
        ++frequencies[found].frequency;
      }

      token = strpbrk(token + token_size + 1, kValidNameStartChar);
    }
  }

  for (int i = 0; i < frequencies_size; ++i) {
    printf("%s %d\n", frequencies[i].name, frequencies[i].frequency);
  }
  return 0;
}
