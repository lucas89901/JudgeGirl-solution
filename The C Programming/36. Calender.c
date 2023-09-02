#include <stdio.h>

int main() {
  int year, month, day_of_week;
  scanf("%d%d%d", &year, &month, &day_of_week);

  if (month < 1 || month > 12 || day_of_week < 0 || day_of_week > 6) {
    printf("invalid\n");
    return 0;
  }

  int days_in_month;
  switch (month) {
    case 1:
    case 3:
    case 5:
    case 7:
    case 8:
    case 10:
    case 12:
      days_in_month = 31;
      break;
    case 4:
    case 6:
    case 9:
    case 11:
      days_in_month = 30;
      break;
    case 2:
      // Is leap year
      if (year % 400 == 0 || (year % 4 == 0 && year % 100 != 0)) {
        days_in_month = 29;
      } else {
        days_in_month = 28;
      }
      break;
    default:
      days_in_month = -1;
  }

  printf(" Su Mo Tu We Th Fr Sa\n");
  printf("=====================\n");
  for (int i = 0; i < day_of_week; ++i) {  // Pad first line
    printf("   ");
  }
  for (int day = 1; day <= days_in_month; ++day) {
    printf("%3d", day);
    if (day_of_week == 6) {
      printf("\n");
    }
    day_of_week = (day_of_week + 1) % 7;
  }
  if (day_of_week != 0) {
    printf("\n");
  }
  printf("=====================\n");
  return 0;
}
