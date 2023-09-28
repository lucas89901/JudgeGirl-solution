#include <stdio.h>

#include "image2column.h"

int main() {
  int imgWidth, imgHeight;
  int colWidth, colHeight;
  int windowSize;
  int imgMat[MAXW][MAXH];
  int colMat[MAXW * MAXH][MAXK * MAXK];

  scanf("%d%d", &imgWidth, &imgHeight);
  scanf("%d", &windowSize);

  colWidth = (imgWidth - windowSize + 1) * (imgHeight - windowSize + 1);
  colHeight = windowSize * windowSize;

  for (int i = 0; i < imgHeight; i++)
    for (int j = 0; j < imgWidth; j++) scanf("%d", &imgMat[j][i]);

  img2col(imgWidth, imgHeight, windowSize, imgMat, colMat);

  for (int i = 0; i < colHeight; i++) {
    for (int j = 0; j < colWidth; j++) printf("%d ", colMat[j][i]);
    printf("\n");
  }
}
