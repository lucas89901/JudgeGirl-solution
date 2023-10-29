#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Pattern {
  char pattern[4];
  int frequency;
} Pattern;

bool LessThan(const Pattern lhs, const Pattern rhs) {
  if (lhs.frequency == rhs.frequency) {
    return strcmp(lhs.pattern, rhs.pattern) > 0;
  }
  return lhs.frequency < rhs.frequency;
}

int main() {
  const int kSize = 17576;
  int frequencies[kSize];  // 26^3
  memset(frequencies, 0, sizeof(frequencies));

  char buffer[10005];
  while (scanf("%s", buffer) != EOF) {
    int size = strlen(buffer);
    if (size < 3) {
      continue;
    }

    int pattern_hash = (buffer[0] - 'a') * 26 * 26 + (buffer[1] - 'a') * 26 +
                       (buffer[2] - 'a');
    ++frequencies[pattern_hash];
    for (int i = 3; i < size; ++i) {
      // Rolling hash.
      pattern_hash -= (buffer[i - 3] - 'a') * 26 * 26;
      pattern_hash *= 26;
      pattern_hash += (buffer[i] - 'a');
      ++frequencies[pattern_hash];
    }
  }

  Pattern most_frequent[3];
  for (int i = 0; i < 3; ++i) {
    most_frequent[i] = (Pattern){"\0\0\0\0", -1};
  }
  for (int i = 0; i < kSize; ++i) {
    if (frequencies[i] == 0) {
      continue;
    }
    Pattern pattern = {{'a' + i / 26 / 26, 'a' + (i / 26) % 26, 'a' + i % 26},
                       frequencies[i]};
    int insert_index = 0;
    while (insert_index < 3 && LessThan(pattern, most_frequent[insert_index])) {
      ++insert_index;
    }
    if (insert_index == 3) {
      continue;
    }
    for (int j = 1; j >= insert_index; --j) {
      most_frequent[j + 1] = most_frequent[j];
    }
    most_frequent[insert_index] = pattern;
  }

  for (int i = 0; i < 3; ++i) {
    printf("%s\n", most_frequent[i].pattern);
  }
  return 0;
}
