#include "treeToList.h"

#include <stdlib.h>

void Concat(List *a, List *b) {
  a->tail->left = b->head;
  a->tail = b->tail;
}

List treeToListFunc(TreeNode *root) {
  if (!root) {
    return (List){NULL, NULL};
  }
  List list = {root, root};
  List front = treeToListFunc(root->left);
  List back = treeToListFunc(root->right);
  root->right = NULL;

  if (root->value & 1) {
    List temp = front;
    front = back;
    back = temp;
  }
  if (front.head) {
    Concat(&list, &front);
  }
  if (back.head) {
    Concat(&list, &back);
  }
  return list;
}
