#include <stdio.h>

#include "image2column.h"

int main() {
  int imgHeight, imgWidth;
  int colHeight, colWidth;
  int windowSize;
  int imgMat[MAXH][MAXW];
  int colMat[MAXK * MAXK][MAXW * MAXH];

  scanf("%d%d", &imgHeight, &imgWidth);
  scanf("%d", &windowSize);

  colHeight = windowSize * windowSize;
  colWidth = (imgWidth - windowSize + 1) * (imgHeight - windowSize + 1);

  for (int i = 0; i < imgHeight; i++)
    for (int j = 0; j < imgWidth; j++) scanf("%d", &imgMat[i][j]);

  img2col(imgHeight, imgWidth, windowSize, imgMat, colMat);

  for (int i = 0; i < colHeight; i++) {
    for (int j = 0; j < colWidth; j++) printf("%d ", colMat[i][j]);
    printf("\n");
  }
}
