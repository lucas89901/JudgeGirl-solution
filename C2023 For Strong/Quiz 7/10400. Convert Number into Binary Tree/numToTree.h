#include <stdint.h>

struct treenode {
  uint64_t value;
  struct treenode *left;
  struct treenode *right;
};

typedef struct treenode TreeNode;
TreeNode *numToTree(uint64_t num, int bitNum);
