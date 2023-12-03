#include <stdbool.h>
#include <stdint.h>
#include <stdio.h>
#include <string.h>

typedef struct Friendship {
  int u;
  int v;
} Friendship;

void PrintBinary(uint64_t x) {
  for (int i = 0; i < 64; ++i) {
    fprintf(stderr, "%d", x & 1);
    x >>= 1;
  }
  fprintf(stderr, "\n");
}

void Solve(const int n, const int m, const Friendship friendships[], int i,
           uint64_t friends_of[], uint64_t selected_friendships,
           int selected_friendships_count, int *max_count, uint64_t *answer) {
#ifdef GP_DEBUG
  fprintf(stderr, "i=%d\n", i);
  PrintBinary(selected_friendships);
#endif
  // Cut
  if (selected_friendships_count + m - i <= *max_count) {
    return;
  }

  if (i == m) {
    *max_count = selected_friendships_count;
    *answer = selected_friendships;
    return;
  }

  bool can_select = true;
  for (int j = 0; j < n; ++j) {
    if (friends_of[j] & 1ULL << friendships[i].u &&
        friends_of[j] & 1ULL << friendships[i].v) {
      can_select = false;
      break;
    }
  }
  if (can_select) {
#ifdef GP_DEBUG
    fprintf(stderr, "Select friendship[%d]: %d %d\n", i, friendships[i].u,
            friendships[i].v);
#endif
    //  Select friendships[i].
    friends_of[friendships[i].u] |= 1ULL << friendships[i].v;
    friends_of[friendships[i].v] |= 1ULL << friendships[i].u;
    Solve(n, m, friendships, i + 1, friends_of,
          selected_friendships | 1ULL << i, selected_friendships_count + 1,
          max_count, answer);
    // Deselect friendships[i].
    friends_of[friendships[i].u] &= ~(1ULL << friendships[i].v);
    friends_of[friendships[i].v] &= ~(1ULL << friendships[i].u);
  }

  // Don't select friendships[i].
  Solve(n, m, friendships, i + 1, friends_of, selected_friendships,
        selected_friendships_count, max_count, answer);
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Friendship friendships[m];
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &friendships[i].u, &friendships[i].v);
  }

  uint64_t friends_of[n];
  memset(friends_of, 0, sizeof(friends_of));
  int max_count = 0;
  uint64_t answer = 0;
  Solve(n, m, friendships, 0, friends_of, 0, 0, &max_count, &answer);
  for (int i = 0; i < m; ++i) {
    if (answer & 1) {
      printf("%d %d\n", friendships[i].u, friendships[i].v);
    }
    answer >>= 1;
  }
  return 0;
}
