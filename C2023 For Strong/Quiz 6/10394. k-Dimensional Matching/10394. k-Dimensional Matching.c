#include <stdbool.h>
#include <stdio.h>
#include <string.h>

void Solve(const int k, const int n, const int adj[n][k],
           const int adj_sizes[n], bool selected[n], int paths[n][k],
           int current_path, int *answer_path_count, int answer[n][k]);

void SolvePath(const int k, const int n, const int adj[n][k],
               const int adj_sizes[n], int v, bool selected[n], int paths[][k],
               int current_path, int *answer_path_count, int answer[n][k]) {
  if (v >= n - n / k) {  // Reached last set.
    if (current_path + 1 > *answer_path_count) {
      *answer_path_count = current_path + 1;
      for (int i = 0; i <= current_path; ++i) {
        for (int j = 0; j < k; ++j) {
          answer[i][j] = paths[i][j];
#ifdef GP_DEBUG
          fprintf(stderr, "answer[%d][%d]=%d\n", i, j, answer[i][j]);
#endif
        }
      }
    }
    return Solve(k, n, adj, adj_sizes, selected, paths, current_path + 1,
                 answer_path_count, answer);
  }

  for (int i = 0; i < adj_sizes[v]; ++i) {
    int u = adj[v][i];
    if (selected[u]) {
      continue;
    }
    selected[u] = true;
    paths[current_path][u / (n / k)] = u;
    SolvePath(k, n, adj, adj_sizes, u, selected, paths, current_path,
              answer_path_count, answer);
    selected[u] = false;
  }
}

void Solve(const int k, const int n, const int adj[n][k],
           const int adj_sizes[n], bool selected[n], int paths[n][k],
           int current_path, int *answer_path_count, int answer[n][k]) {
  for (int v = 0; v < n / k; ++v) {
    if (selected[v]) {
      continue;
    }
    selected[v] = true;
    paths[current_path][0] = v;
    SolvePath(k, n, adj, adj_sizes, v, selected, paths, current_path,
              answer_path_count, answer);
    selected[v] = false;
  }
}

int main() {
  int k, n;
  scanf("%d %d", &k, &n);
  int e;
  scanf("%d", &e);

  int adj[n][k];
  int adj_sizes[n];
  memset(adj_sizes, 0, sizeof(adj_sizes));
  for (int k = 0; k < e; ++k) {
    int i, j;
    scanf("%d %d", &i, &j);
    adj[i][adj_sizes[i]++] = j;
  }

  bool selected[n];
  memset(selected, 0, sizeof(selected));
  int paths[n][k];
  int answer_path_count = 0;
  int answer[n][k];
  Solve(k, n, adj, adj_sizes, selected, paths, 0, &answer_path_count, answer);
  for (int i = 0; i < answer_path_count; ++i) {
    for (int j = 0; j < k; ++j) {
      printf("%d%c", answer[i][j], " \n"[j == k - 1]);
    }
  }
  return 0;
}
