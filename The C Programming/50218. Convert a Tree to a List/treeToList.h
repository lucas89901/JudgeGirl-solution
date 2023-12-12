struct treenode {
  int value;
  struct treenode *left;
  struct treenode *right;
};

struct list {
  struct treenode *head;
  struct treenode *tail;
};

typedef struct treenode TreeNode;
typedef struct list List;

List treeToListFunc(TreeNode *root);
