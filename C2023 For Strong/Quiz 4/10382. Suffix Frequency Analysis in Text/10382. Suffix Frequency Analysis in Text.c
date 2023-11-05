#include <stdio.h>
#include <string.h>

typedef struct Frequency {
  char suffix[5];
  int frequency;
} Frequency;

int main() {
  const char kDelimiters[] = " .,!?;:\n";
  Frequency frequencies[20] = {
      {"able", 0}, {"ary", 0},  {"ed", 0},  {"ence", 0}, {"ful", 0},
      {"hood", 0}, {"ical", 0}, {"ing", 0}, {"ish", 0},  {"ism", 0},
      {"ist", 0},  {"ive", 0},  {"ize", 0}, {"less", 0}, {"ly", 0},
      {"ment", 0}, {"ness", 0}, {"ous", 0}, {"ship", 0}, {"tion", 0}};

  char buffer[100005];
  while (fgets(buffer, 100005, stdin)) {
    for (char *token = strtok(buffer, kDelimiters); token;
         token = strtok(NULL, kDelimiters)) {
      int token_length = strlen(token);
      for (int i = 0; i < 20; ++i) {
        int suffix_length = strlen(frequencies[i].suffix);
        if (token_length >= suffix_length &&
            strcmp(token + token_length - suffix_length,
                   frequencies[i].suffix) == 0) {
          ++frequencies[i].frequency;
          break;
        }
      }
    }
  }

  for (int i = 0; i < 20; ++i) {
    if (frequencies[i].frequency > 0) {
      printf("%s:\nFrequency: %d\n", frequencies[i].suffix,
             frequencies[i].frequency);
    }
  }
  return 0;
}
