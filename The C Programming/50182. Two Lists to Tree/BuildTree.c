#include "BuildTree.h"

#include <stdio.h>
#include <stdlib.h>

Node *Advance(Node *node, int offset) {
  for (int i = 0; i < offset && node; ++i) {
    node = node->left;
  }
  return node;
}

int Size(Node *list) {
  int size = 0;
  for (; list; list = list->left) {
    ++size;
  }
  return size;
}

Node *Build(Node *l, int l_size, Node *r, int r_size) {
  if (l_size == 0 && r_size == 0) {
    return NULL;
  }
  if (l_size == 0) {
    r->left = Build(l, l_size, r->left, r_size - 1);
    return r;
  }
  if (r_size == 0) {
    l->left = Build(l->left, l_size - 1, r, r_size);
    return l;
  }

  if (l->val < r->val) {
    --l_size;
    l->right = Build(Advance(l, (l_size + 1) / 2 + 1), l_size / 2,
                     Advance(r, (r_size + 1) / 2), r_size / 2);
    l->left = Build(Advance(l, 1), (l_size + 1) / 2, r, (r_size + 1) / 2);
    return l;
  } else {
    --r_size;
    r->right = Build(Advance(l, (l_size + 1) / 2), l_size / 2,
                     Advance(r, (r_size + 1) / 2 + 1), r_size / 2);
    r->left = Build(l, (l_size + 1) / 2, Advance(r, 1), (r_size + 1) / 2);
    return r;
  }
}

Node *BuildTree(Node *list1, Node *list2) {
  return Build(list1, Size(list1), list2, Size(list2));
}
