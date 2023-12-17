#include <stdbool.h>

typedef struct Node {
  bool color;
  struct Node *left, *right;
  int farthestLeft, farthestRight;
} Node;

int maxDist(Node *root);
