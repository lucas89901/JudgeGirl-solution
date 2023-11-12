#include <stdio.h>

void MergeSort(int arr[], int left, int right) {
  for (int i = left; i <= right; ++i) {
    printf("%d%c", arr[i], " \n"[i == right]);
  }
  if (left == right) {
    return;
  }

  int mid = left + (right - left - 1) / 2;
  MergeSort(arr, left, mid);
  MergeSort(arr, mid + 1, right);

  int sorted[right - left + 1];
  int sorted_index = 0;
  for (int i = left, j = mid + 1; i <= mid || j <= right;) {
    if (j > right || (i <= mid && arr[i] < arr[j])) {
      // Choose from left subarray.
      sorted[sorted_index++] = arr[i++];
    } else {
      // Choose from right subarray.
      sorted[sorted_index++] = arr[j++];
    }
  }

  for (int i = left; i <= right; ++i) {
    arr[i] = sorted[i - left];
    printf("%d%c", arr[i], " \n"[i == right]);
  }
}

int main() {
  int arr[100000];
  int size = 0;
  while (scanf("%d", &arr[size]) != EOF) {
    ++size;
  }
  MergeSort(arr, 0, size - 1);
  return 0;
}
