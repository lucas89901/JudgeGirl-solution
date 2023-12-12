#include "tree.h"

#include <stdbool.h>
#include <stdio.h>

void traversal(Node *root, int N, int command[]) {
  // Store path from root node to current node in stack (implemented with an
  // array).
  int size = 1;
  Node *path[N];
  path[0] = root;

  int last;
  for (int i = 0; i < N && size >= 1 && path[size - 1]; ++i) {
    last = path[size - 1]->label;
    switch (command[i]) {
      case 0:
        size = 0;
        break;
      case 1:
        printf("%d\n", path[size - 1]->label);
        break;
      case 2:
        --size;
        break;
      case 3:
        path[size] = path[size - 1]->left;
        ++size;
        break;
      case 4:
        path[size] = path[size - 1]->right;
        ++size;
        break;
      case 5:
        if (size <= 1) {
          size = 0;
          break;
        }
        if (path[size - 2]->left == path[size - 1]) {
          path[size - 1] = path[size - 2]->right;
        } else {
          path[size - 1] = path[size - 2]->left;
        }
        break;
    }
  }
  printf("%d\n", last);
}
