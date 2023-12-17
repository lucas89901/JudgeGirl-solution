#include "freqCalculator.h"

#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

double *freqCalculate(char names[1024]) {
  const double kRatio = 1.0594630943593;

  double frequencies[7] = {
      440,                   // A4
      440 * pow(kRatio, 2),  // B4
      440 / pow(kRatio, 9),  // C4
      440 / pow(kRatio, 7),  // D4
      440 / pow(kRatio, 5),  // E4
      440 / pow(kRatio, 4),  // F4
      440 / pow(kRatio, 2),  // G4
  };

  int size = (strlen(names) + 1) / 3;
  double *answer = calloc(sizeof(double), size);
  for (int i = 0; i < size; ++i) {
    answer[i] =
        frequencies[names[3 * i] - 'A'] * pow(2, (names[3 * i + 1] - '4'));
#ifdef GP_DEBUG
    fprintf(stderr, "%c%c=%lf\n", names[3 * i], names[3 * i + 1], answer[i]);
#endif  // GP_DEBUG
  }
  return answer;
}
