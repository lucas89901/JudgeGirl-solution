#include <stdio.h>
#include <stdlib.h>

#include "tree.h"

Node *newNode(int data, Node *l, Node *r) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->data = data;
  n->left = l;
  n->right = r;
  return n;
}

int main() {
  // clang-format off
  Node *root = newNode(
    10,
      newNode(
        5,
          NULL,
          newNode(2, NULL, NULL)
      ),
      newNode(
        7,
          newNode(1, NULL, NULL),
          NULL
      )
  );
  // clang-format on
  Answer *ans = (Answer *)malloc(sizeof(Answer));
  ans->sumDepth = 0;
  ans->sumData = 0;
  trace(root, ans);
  printf("%d %d\n", ans->sumDepth, ans->sumData);
  return 0;
}
