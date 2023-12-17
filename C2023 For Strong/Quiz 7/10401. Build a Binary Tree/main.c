#include <stdio.h>
#include <stdlib.h>

#include "buildTree.h"

void preorderTree(TreeNode *root) {
  if (root == NULL) return;
  printf("%d ", root->value);
  preorderTree(root->left);
  preorderTree(root->right);
}

void inorderTree(TreeNode *root) {
  if (root == NULL) return;
  inorderTree(root->left);
  printf("%d ", root->value);
  inorderTree(root->right);
}

int main() {
  int traverseOrder[MAXARR];
  int arrSize = 0;

  while (scanf("%d", &traverseOrder[arrSize]) != EOF) arrSize++;

  TreeNode *root = (TreeNode *)malloc(sizeof(TreeNode));
  root = buildTree(traverseOrder, arrSize);

  preorderTree(root);
  printf("\n");
  inorderTree(root);
  printf("\n");

  return 0;
}
