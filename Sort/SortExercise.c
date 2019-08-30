#include <stdio.h>
#include <stdlib.h>

/*Define a global variable to count the comparison times*/

void showArray(int *T, int n) {
  int index;
  for (index = 0; index < n; index++) {
    printf("%d ", T[index]);
  }
  printf("\n");
}

void swap(int *T, int i, int j) {
  int temp = T[i];
  T[i] = T[j];
  T[j] = temp;
}

void select_sort(int T[], int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (T[j] < T[min]) {
        min = j;
      }
    }
    swap(T, i, min);
  }
}

void bubble_sort(int T[], int n) {
  int i, j;
  for (i = n - 1; i > 0; i--) {
    int flag = 0;
    for (j = 0; j < i; j++) {
      if (T[j] > T[j + 1]) {
        swap(T, j + 1, j);
        flag = 1;
      }
    }
    if (flag == 0)
      return;
  }
}

void mergeSort(int x[], int tmp[], int left, int leftend, int rightend) {
  if(left>=rightend)
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

void heap_sort(int T[], int n) {
  int k[n + 1];
  int i;
  for (i = 0; i < n; i++) {
    k[i + 1] = T[i];
  }
  for (i = n / 2; i > 0; --i)
    adjust(k, i, n);
  for (i = n; i > 1; --i) {
    swap(k, 1, i);
    adjust(k, 1, i - 1);
  }
  for (i = 0; i < n; i++) {
    T[i] = k[i + 1];
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

int main() {
  int n, method_num;
  scanf("%d%d", &n, &method_num);
  int *array = (int *)malloc(sizeof(int) * n);
  int *temp = (int *)malloc(sizeof(int) * n);
  int index;
  for (index = 0; index < n; index++) {
    scanf("%d", array + index);
  }
  switch (method_num) {
  case 1:
    select_sort(array, n);
    break;

  case 2:
    bubble_sort(array, n);
    break;
  case 3:
    heap_sort(array, n);
    break;
  case 4:
    mergeSort(array,temp, 0, (n-1)/2,n - 1);
    showArray(temp, n);
    return 0;
    break;
  case 5:
    quickSort(array, 0, n - 1);
    break;
  default:
    break;
  }
  /*Show the compare times*/
  showArray(array, n);
  return 0;
}