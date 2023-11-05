#include <stdio.h>
#include <string.h>

int main() {
  const char kNumberToEnglish[20][10] = {
      "zero",    "one",     "two",       "three",    "four",
      "five",    "six",     "seven",     "eight",    "nine",
      "ten",     "eleven",  "twelve",    "thirteen", "fourteen",
      "fifteen", "sixteen", "seventeen", "eighteen", "nineteen",
  };
  const char kTensToEnglish[10][10] = {
      "",      "",      "twenty",  "thirty", "forty",
      "fifty", "sixty", "seventy", "eighty", "ninety",
  };
  const char kScale[7][16] = {"",           "thousand", "million",
                              "billion",    "trillion", "quadrillion",
                              "quintillion"};

  long long int N;
  scanf("%lld", &N);
  char answer[100][32];
  memset(answer, 0, sizeof(answer));
  int size = 0;
  for (int scale = 0; N; N /= 1000, ++scale) {
    strcpy(answer[size++], kScale[scale]);
    int hundreds = (N / 100) % 10;
    int tens = (N / 10) % 10;
    int ones = N % 10;
#ifdef GP_DEBUG
    fprintf(stderr, "%d, %d, %d\n", hundreds, tens, ones);
#endif
    if (tens >= 2) {  // 20-99
      strcpy(answer[size], kTensToEnglish[tens]);
      if (ones > 0) {
        strcat(answer[size], "-");
        strcat(answer[size], kNumberToEnglish[ones]);
      }
      ++size;
    } else if (tens * 10 + ones > 0) {  // 1-19
      strcpy(answer[size++], kNumberToEnglish[tens * 10 + ones]);
    }
    if (hundreds > 0) {
      strcpy(answer[size++], "hundred");
      strcpy(answer[size++], kNumberToEnglish[hundreds]);
    }
  }

  // Ignore answer[0], which is "" (kScale[0]).
  for (int i = size - 1; i >= 1; --i) {
    printf("%s%c", answer[i], " \n"[i == 1]);
  }
  return 0;
}
