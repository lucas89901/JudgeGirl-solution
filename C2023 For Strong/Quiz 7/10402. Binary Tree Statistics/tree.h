typedef struct Node {
  int data;
  struct Node *left, *right;
} Node;

typedef struct Answer {
  int sumDepth;
  int sumData;
} Answer;

void trace(Node *root, Answer *ans);
