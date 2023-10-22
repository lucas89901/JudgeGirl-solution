#include "countIntersections.h"

#include <stddef.h>

int countIntersections(int *ptrArray[]) {
  int answer = 0;
  for (int i = 0; ptrArray[i] != NULL; ++i) {
    for (int j = 0; j < i; ++j) {
      answer += (ptrArray[j] > ptrArray[i]);
    }
  }
  return answer;
}
