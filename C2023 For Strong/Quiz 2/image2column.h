#define MAXW 100
#define MAXH 100
#define MAXK 10

void img2col(int w, int h, int k, int imgMatrix[MAXW][MAXH],
             int colMatrix[MAXW * MAXH][MAXK * MAXK]) {
  // for (int i = 0; i < w; ++i) {
  //   for (int j = 0; j < h; ++j) {
  //     fprintf(stderr, "%d ", imgMatrix[i][j]);
  //   }
  //   fprintf(stderr, "\n");
  // }

  for (int c = 0; c <= h - k; ++c) {
    for (int r = 0; r <= w - k; ++r) {
      // fprintf(stderr, "col: %d\n", c * (w - k + 1) + r);
      for (int j = 0; j < k; ++j) {
        for (int i = 0; i < k; ++i) {
          // fprintf(stderr, "%d: %d, ", j * k + i, imgMatrix[r + i][c + j]);
          colMatrix[c * (w - k + 1) + r][j * k + i] = imgMatrix[r + i][c + j];
        }
      }
      // fprintf(stderr, "\n");
    }
  }
}
