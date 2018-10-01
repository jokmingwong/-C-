#include <stdio.h>
void swap(int a, int b)
{
    int temp = a;
    a = b;
    b = temp;
}
void QuickSort(int A[], int s, int t)
{
    int i, j;
    if (s < t)
    {
        i = s;
        j = t + 1;
        while (1)
        {
            do
                i++;
            while (!(A[s] <= A[i] || i == t));
            do
                i--;
            while (!(A[s] >= A[j] || j == s));
            if (i < j)
                swap(A[i], A[j]);
            else
                break;
        }
        swap(A[s], A[j]);
        QuickSort(A, s, j - 1);
        QuickSort(A, j + 1, t);
    }
}
void deleteRepeat(int A[], int n)
{
    int i, k = 0;
    for (i = 1; i < n; i++)
    {
        if (A[i] != A[k])
        {
            A[++k] = A[i];
        }
    }
    n = k + 1;
    int t;
    for (t = 0; t < n; t++)
    {
        printf("%d ", A[t]);
    }
}
int main()
{
    printf("Input the number of the array:\n");
    int num, t;
    scanf("%d", &num);
    int A[num];
    for (t = 0; t < num; t++)
    {
        scanf("%d", &A[t]);
    }
    QuickSort(A, 0, num);
    deleteRepeat(A, num);
    return 0;
}