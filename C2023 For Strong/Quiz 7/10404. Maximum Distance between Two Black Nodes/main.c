#include <stdio.h>
#include <stdlib.h>

#include "maxDist.h"

Node *newNode(bool color, Node *l, Node *r) {
  Node *n = (Node *)malloc(sizeof(Node));
  n->color = color;
  n->left = l;
  n->right = r;
  n->farthestLeft = n->farthestRight = 0;
  return n;
}

int main() {
  // clang-format off
    Node *root = newNode(
        false, // 1
            newNode(
                true, // 2
                    newNode(
                        false, // 3
                            newNode(
                                true, // 4
                                    newNode(false,  NULL, NULL), // 5
                                    newNode(true,  NULL, NULL) // 6
                            ),
                            newNode(
                                false, // 7
                                    newNode(true,  NULL, NULL), // 8
                                    NULL
                            )
                    ),
                    newNode(
                        false, // 9
                            newNode(
                                true, // 10
                                    NULL,
                                    newNode(false, NULL, NULL) // 11
                            ),
                            NULL
                    )
            ),
            newNode(
                false, // 12
                    NULL,
                    newNode(true, // 13
                                newNode(true, NULL, NULL), // 14
                                NULL)
            )
    );
  // clang-format on
  printf("%d\n", maxDist(root));
  return 0;
}
