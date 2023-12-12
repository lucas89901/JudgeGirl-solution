#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

#include "treeToList.h"

TreeNode *buildTree(int **values, TreeNode **roots) {
  int val;
  scanf("%d", &val);
  if (val == 0) return NULL;
  **values = val;
  TreeNode *now = *roots;
  (*values)++;
  (*roots)++;
  now->value = val;
  now->left = buildTree(values, roots);
  now->right = buildTree(values, roots);
  return now;
}

int main(void) {
  int size;
  scanf("%d\n", &size);
  TreeNode *root = (TreeNode *)calloc(size, sizeof(TreeNode));

  int valueRecord[size];
  int *vptr = valueRecord;
  TreeNode *nptr = root;

  root = buildTree(&vptr, &nptr);

  List ans = treeToListFunc(root);

  TreeNode *node = ans.head;
  TreeNode *firstAddr = &root[0];
  TreeNode *lastAddr = &root[size];
  for (; node != NULL; node = node->left) {
    if (node->right != NULL) {
      printf("Right node should be null\n");
      break;
    }
    if (firstAddr > node || lastAddr <= node) {
      printf("Memory address out of bound\n");
      break;
    }
    int counter = node - firstAddr;
    if (node->value != valueRecord[counter]) {
      printf("You can't modify the value in the given treeNode\n");
      break;
    }
    printf("%d ", node->value);
  }

  free(root);
  return 0;
}
