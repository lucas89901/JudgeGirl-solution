#include "tree.h"

void Trace(Node *node, Answer *ans, int depth) {
  ans->sumData += node->data;
  ans->sumDepth += depth;
  if (node->left) {
    Trace(node->left, ans, depth + 1);
  }
  if (node->right) {
    Trace(node->right, ans, depth + 1);
  }
}

void trace(Node *root, Answer *ans) {
  Trace(root, ans, 1);
}
