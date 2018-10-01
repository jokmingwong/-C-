#include <stdio.h>
#define INF 10000
void showArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

void INSERT_SORT(int *A, int n)
{
    int minJ, i, j;
    for (i = 0; i < n - 1; i++)
    {
        minJ = i;
        for (j = i; j < n; j++)
        {
            if (A[minJ] > A[j])
                minJ = j;
        }
        int temp = A[i];
        A[i] = A[minJ];
        A[minJ] = temp;
    }
    printf("This is the result of the insert-sort:\n");
    showArray(A, n);
}

void BUBBLE_SORT(int *A, int n)
{
    int i, j;
    for (i = 0; i < n - 1; i++)
    {
        for (j = i + 1; j < n; j++)
        {
            if (A[j] < A[i])
            {
                int temp = A[i];
                A[i] = A[j];
                A[j] = temp;
            }
        }
    }
    printf("This is the result of the bubble sort\n");
    showArray(A, n);
}

void MERGE_SORT(int *A, int p, int q, int r)
{
    int n1 = q - p + 1;
    int n2 = r - q;
    int L[n1 + 1];
    int R[n2 + 1];
    int i, j;
    for (i = 0; i < n1; i++)
    {
        L[i] = A[i];
    }
    for (j = 0; j < n2; j++)
    {
        R[j] = A[n1 + j];
    }
    L[n1] = INF;
    R[n2] = INF;
    i = 1, j = 1;
    int k;
    for (k = p; k < r; k++)
    {
        if (L[i] <= R[j])
        {
            A[k] = L[i];
            i++;
        }
        else
        {
            A[k] = R[j];
            j++;
        }
    }
    printf("This is the result of the merge sort\n");
    showArray(A, 8);
}

int main()
{
    int test[8] = {5, 4, 7, 9, 13, 6, 2, -7};
    INSERT_SORT(test, 8);
    return 0;
}