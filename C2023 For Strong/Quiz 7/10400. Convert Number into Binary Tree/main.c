#include <stdio.h>
#include <stdlib.h>

#include "numToTree.h"
#define NUMBITS 64

void preorderTree(TreeNode *root) {
  if (root == NULL) return;
  printf("%llu ", root->value);
  preorderTree(root->left);
  preorderTree(root->right);
}

void inorderTree(TreeNode *root) {
  if (root == NULL) return;
  inorderTree(root->left);
  printf("%llu ", root->value);
  inorderTree(root->right);
}

int main() {
  uint64_t num;
  scanf("%llu", &num);

  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root = numToTree(num, NUMBITS);

  preorderTree(root);
  printf("\n");
  inorderTree(root);
  printf("\n");

  return 0;
}
