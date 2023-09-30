#define MAXH 100
#define MAXW 100
#define MAXK 10

void img2col(int h, int w, int k, int imgMatrix[MAXH][MAXW],
             int colMatrix[MAXK * MAXK][MAXW * MAXH]) {
  for (int r = 0; r <= h - k; ++r) {
    for (int c = 0; c <= w - k; ++c) {
      for (int i = 0; i < k; ++i) {
        for (int j = 0; j < k; ++j) {
          colMatrix[i * k + j][r * (w - k + 1) + c] = imgMatrix[r + i][c + j];
        }
      }
    }
  }
}
