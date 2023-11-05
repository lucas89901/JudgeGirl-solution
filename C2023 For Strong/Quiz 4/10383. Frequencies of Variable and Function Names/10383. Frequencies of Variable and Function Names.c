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
bool IsReserved(char word[]) {
  for (int i = 0; i < 12; ++i) {
    if (strcmp(kReserved[i], word) == 0) {
      return true;
    }
  }
  return false;
}

int main() {
  const char kDelimiters[] = " ,;(){}[]?:=+-*/%&|^<>!~\n";
  Frequency frequencies[30];
  char buffer[100000];
  memset(frequencies, 0, sizeof(frequencies));
  int frequencies_size = 0;
  while (fgets(buffer, 100000, stdin)) {
    for (char *token = strtok(buffer, kDelimiters); token;
         token = strtok(NULL, kDelimiters)) {
      if (IsReserved(token) || isdigit(token[0])) {
        continue;
      }
#ifdef GP_DEBUG
      fprintf(stderr, "token=%s\n", token);
#endif

      int found = Find(frequencies, frequencies_size, token);
      if (found == -1) {
        strncpy(frequencies[frequencies_size].name, token, 24);
        frequencies[frequencies_size++].frequency = 1;
      } else {
        ++frequencies[found].frequency;
      }
    }
  }

  for (int i = 0; i < frequencies_size; ++i) {
    printf("%s %d\n", frequencies[i].name, frequencies[i].frequency);
  }
  return 0;
}
