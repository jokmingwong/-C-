#include <stdio.h>
#ifndef _INTSORT_H_
#define _INTSORT_H_

/*Show the array*/
void showArray(const int *Array, const unsigned int ArraySize) {
  int index;
  for (index = 0; index < ArraySize; index++) {
    printf("%d ", Array[index]);
  }
  printf("\n");
}

void swap(int *Array, int i, int j) {
  int temp = Array[i];
  Array[i] = Array[j];
  Array[j] = temp;
}

void select_sort(int Array[], const unsigned int ArraySize) {
  int i, j;
  for (i = 0; i < ArraySize - 1; i++) {
    int min = i;
    for (j = i + 1; j < ArraySize; j++) {
      if (Array[j] < Array[min]) {
        min = j;
      }
    }
    swap(Array, i, min);
  }
}

void bubble_sort(int Array[], const unsigned int ArraySize) {
  int i, j;
  for (i = ArraySize - 1; i > 0; i--) {
    int flag = 0;
    for (j = 0; j < i; j++) {
      if (Array[j] > Array[j + 1]) {
        swap(Array, j + 1, j);
        flag = 1;
      }
    }
    if (flag == 0)
      return;
  }
}

void mergeSort(int x[], int tmp[], int left, int leftend, int rightend) {
  if (left >= rightend)
    return;
  unsigned int i = left, j = leftend + 1, q = left;
  mergeSort(x, tmp, left, (left + leftend) / 2, leftend);
  mergeSort(x, tmp, leftend + 1, (leftend + 1 + rightend) / 2, rightend);
  while (i <= leftend && j <= rightend) {
    if (x[i] <= x[j])
      tmp[q++] = x[i++];
    else
      tmp[q++] = x[j++];
  }
  while (i <= leftend)
    tmp[q++] = x[i++];

  while (j <= rightend)
    tmp[q++] = x[j++];
  for (i = left; i <= rightend; i++)
    x[i] = tmp[i];
}

void adjust(int k[], int s, int m) {
  int rc = k[s];
  int j;
  for (j = 2 * s; j <= m; j *= 2) {
    if (j < m && k[j] < k[j + 1])
      j++;
    if (rc >= k[j])
      break;
    k[s] = k[j];
    s = j;
  }
  k[s] = rc;
}

void heap_sort(int Array[], const unsigned int ArraySize) {
  int k[ArraySize + 1];
  int i;
  for (i = 0; i < ArraySize; i++) {
    k[i + 1] = Array[i];
  }
  for (i = ArraySize / 2; i > 0; --i)
    adjust(k, i, ArraySize);
  for (i = ArraySize; i > 1; --i) {
    swap(k, 1, i);
    adjust(k, 1, i - 1);
  }
  for (i = 0; i < ArraySize; i++) {
    Array[i] = k[i + 1];
  }
}

void quickSort(int k[], int left, int right) {
  int i, last;
  if (left < right) {
    last = left;
    for (i = left + 1; i <= right; i++) {
      if (k[i] < k[left])
        swap(k, ++last, i);
    }
    swap(k, left, last);
    quickSort(k, left, last - 1);
    quickSort(k, last + 1, right);
  }
}
#endif