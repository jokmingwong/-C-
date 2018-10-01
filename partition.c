#include <stdio.h>
void swap(int *A, int a, int b)
{
    int temp = A[a];
    A[a] = A[b];
    A[b] = temp;
}
void showArray(int *A, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("%d ", A[i]);
    }
    printf("\n");
}

int partition(int *A, int begin, int end)
{
    int i = 1, j = end;
    while (1)
    {
        while (i <= end)
        {
            if (A[i] > A[0])
            {
                break;
            }
            i++;
        }
        while (j >= begin)
        {
            if (A[j] < A[0])
            {
                break;
            }
            j--;
        }
        if (i >= j)
        {
            swap(A, 0, j);
            return j;
        }
        else
        {
            swap(A, i, j);
        }
    }
}
int main()
{
    int num;
    scanf("%d", &num);
    int i, test[num];
    for (i = 0; i < num; i++)
    {
        scanf("%d", &test[i]);
    }
    int q = partition(test, 0, num - 1);
    printf("%d\n", q + 1);
    showArray(test, num);
    return 0;
}