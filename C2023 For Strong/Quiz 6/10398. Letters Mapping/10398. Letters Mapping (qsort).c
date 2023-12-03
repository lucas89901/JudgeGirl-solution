#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Frequency {
  char c;
  int frequency;
  int value;
} Frequency;

int Compare(const void *lhs2, const void *rhs2) {
  const Frequency *lhs = (const Frequency *)lhs2;
  const Frequency *rhs = (const Frequency *)rhs2;
  return (lhs->c > rhs->c) - (lhs->c < rhs->c);
}

int Find(Frequency arr[], int size, char target) {
  for (int i = 0; i < size; ++i) {
    if (arr[i].c == target) {
      return i;
    }
  }
  return -1;
}

bool Solve(const int k, Frequency charset[9], int value, bool is_char_used[9],
           char answer[9]) {
  // fprintf(stderr, "value=%d\n", value);
  // fprintf(stderr, "is_char_used=");
  // for (int i = 0; i < 9; ++i) {
  //   fprintf(stderr, "%d", is_char_used[i]);
  // }
  // fprintf(stderr, "\n");

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
  Frequency charset[9];
  int charset_size = 0;
  while (scanf("%s", strings[strings_size]) != EOF) {
    for (int i = 0, size = strlen(strings[strings_size]); i < size; ++i) {
      int found = Find(charset, charset_size, strings[strings_size][i]);
      if (found == -1) {
        charset[charset_size++] = (Frequency){strings[strings_size][i], 1};
      } else {
        ++charset[found].frequency;
      }
    }
    ++strings_size;
  }
  qsort(charset, 9, sizeof(charset[0]), Compare);

  bool is_char_used[9];
  memset(is_char_used, 0, sizeof(is_char_used));
  char answer[9];
  Solve(k, charset, 1, is_char_used, answer);
  for (int i = 0; i < 9; ++i) {
    printf("%c%c", answer[i], " \n"[i == 8]);
  }
  return 0;
}
