//有BUG需要后期调试
#include <stdio.h>
#define INFINITY 10000
void printArray(int *S, int n) {
  int i = 0;
  for (; i < n - 1; i++) {
    printf("%d->", S[i]);
  }
  printf("%d", S[n - 1]);
}

void merge(int *A, int left, int mid, int right) {
  int n1 = mid - left + 1;
  int n2 = right - mid;
  int L[n1 + 1], T[n2 + 1];
  int i;
  for (i = left; i < n1; i++) {
    L[i] = A[left + i];
  }
  L[n1] = INFINITY;
  printArray(L, n1 + 1);
  printf("\n");
  for (i = left; i < n2; i++) {
    T[i] = A[mid + 1 + i];
  }
  T[n2] = INFINITY;
  printArray(T, n2 + 1);
  printf("\n");
  // Merge
  int t = 0, l = 0;
  i = left;
  while (t <= n1 && l <= n2 && i < right - left + 1) {
    if (T[t] <= L[l]) {
      A[i++] = T[t++];
    } else {
      A[i++] = L[l++];
    }
  }
}
void merge_sort(int *A, int left, int right) {
  if (left < right) {
    int mid = (left + right) / 2;
    merge_sort(A, left, mid);
    merge_sort(A, mid + 1, right);
    merge(A, left, mid, right);
  }
}

int main() {
  int num;
  scanf("%d", &num);
  int test[num];
  int i;
  for (i = 0; i < num; i++) {
    scanf("%d", &test[i]);
  }
  merge_sort(test, 0, num);
  printArray(test, num);
  return 0;
}