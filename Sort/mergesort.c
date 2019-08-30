#include <stdio.h>
#define MAX_INT 1000
void showArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void merge(int *A, int left, int mid, int right)
{
    int n1 = mid - left + 1;
    int n2 = right - mid;
    int L[n1 + 1], T[n2 + 1];
    int i;
    for (i = 0; i < n1; i++)
    {
        L[i] = A[left + i];
    }
    L[n1] = MAX_INT;

    for (i = 0; i < n2; i++)
    {
        T[i] = A[mid + 1 + i];
    }
    T[n2] = MAX_INT;
    int t = 0, l = 0;
    for (i = left; i < right + 1; i++)
    {
        A[i] = T[t] > L[l] ? L[l++] : T[t++];
    }
}

void mergeSort(int *A, int begin, int end)
{
    if (begin < end)
    {
        int mid = (begin + end) / 2;
        mergeSort(A, begin, mid);
        mergeSort(A, mid + 1, end);
        merge(A, begin, mid, end);
    }
}
int main()
{
    int test[3] = {3, 2, 1};
    int test2[4] = {4, 5, 1, 9};
    mergeSort(test, 0, 2);
    showArray(test, 3);
    mergeSort(test2, 0, 3);
    showArray(test2, 4);
    return 0;
}