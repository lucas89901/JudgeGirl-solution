#include <limits.h>
#include <stdbool.h>
#include <stdio.h>
#include <string.h>

typedef struct Edge {
  int u;
  int v;
} Edge;

int Max(int a, int b) {
  if (a > b) {
    return a;
  }
  return b;
}

int Abs(int a) {
  if (a < 0) {
    return -a;
  }
  return a;
}

int MaxLength(const int m, const Edge edges[], int node_to_int[]) {
  int max_length = INT_MIN;
  for (int i = 0; i < m; ++i) {
    if (node_to_int[edges[i].u] == -1 || node_to_int[edges[i].v] == -1) {
      continue;
    }
    max_length =
        Max(Abs(node_to_int[edges[i].u] - node_to_int[edges[i].v]), max_length);
  }
  return max_length;
}

void Solve(const int n, const int m, const Edge edges[], int i,
           int node_to_int[], bool is_int_used[], int answer[], int max_length,
           int *min_max_length) {
  if (max_length >= *min_max_length) {
    return;
  }

  if (i == n) {
    *min_max_length = max_length;
    for (int j = 0; j < n; ++j) {
      answer[j] = node_to_int[j] + 1;
    }
    return;
  }

  for (int j = 0; j < n; ++j) {
    if (is_int_used[j]) {
      continue;
    }
    is_int_used[j] = true;
    node_to_int[i] = j;
    Solve(n, m, edges, i + 1, node_to_int, is_int_used, answer,
          MaxLength(m, edges, node_to_int), min_max_length);
    is_int_used[j] = false;
    node_to_int[i] = -1;
  }
}

int main() {
  int n, m;
  scanf("%d %d", &n, &m);
  Edge edges[m];
  for (int i = 0; i < m; ++i) {
    scanf("%d %d", &edges[i].u, &edges[i].v);
    --edges[i].u;
    --edges[i].v;
  }

  int node_to_int[n];
  memset(node_to_int, -1, sizeof(node_to_int));
  bool is_int_used[n];
  memset(is_int_used, 0, sizeof(is_int_used));
  int answer[n];
  int min_max_length = INT_MAX;
  Solve(n, m, edges, 0, node_to_int, is_int_used, answer, INT_MIN,
        &min_max_length);
  for (int i = 0; i < n; ++i) {
    printf("%d%c", answer[i], " \n"[i == n - 1]);
  }
  return 0;
}
