#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Frequency {
  char c;
  int frequency;
  int value;
} Frequency;

bool Solve(const int k, Frequency charset[9], int value, bool is_char_used[9],
           char answer[9]) {
  if (value == 10) {
    int sum = 0;
    for (int i = 0; i < 9; ++i) {
      sum += charset[i].frequency * charset[i].value;
    }
    return sum == k;
  }

  for (int i = 0; i < 9; ++i) {
    if (is_char_used[i]) {
      continue;
    }
    is_char_used[i] = true;
    charset[i].value = value;
    answer[value - 1] = charset[i].c;
    if (Solve(k, charset, value + 1, is_char_used, answer)) {
      return true;
    }
    is_char_used[i] = false;
  }
  return false;
}

int main() {
  int k;
  scanf("%d", &k);

  char strings[20][100];
  int strings_size = 0;
  int count[26];
  memset(count, 0, sizeof(count));
  while (scanf("%s", strings[strings_size]) != EOF) {
    for (int i = 0, size = strlen(strings[strings_size]); i < size; ++i) {
      ++count[strings[strings_size][i] - 'a'];
    }
    ++strings_size;
  }

  Frequency charset[9];
  int charset_size = 0;
  for (int i = 0; i < 26; ++i) {
    if (count[i] == 0) {
      continue;
    }
    charset[charset_size++] = (Frequency){'a' + i, count[i], -1};
  }

  bool is_char_used[9];
  memset(is_char_used, 0, sizeof(is_char_used));
  char answer[9];
  Solve(k, charset, 1, is_char_used, answer);
  for (int i = 0; i < 9; ++i) {
    printf("%c%c", answer[i], " \n"[i == 8]);
  }
  return 0;
}
