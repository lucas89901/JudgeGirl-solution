#define MAXARR 10000
struct treenode {
  int value;
  struct treenode *left;
  struct treenode *right;
};

typedef struct treenode TreeNode;
TreeNode *buildTree(int traverseOrder[MAXARR], int arrSize);
