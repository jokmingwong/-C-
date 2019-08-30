#include <stdio.h>
#include <stdlib.h>
int Partion(int T[], int low, int high)
{
    /*这个pivotkey可以随机定义*/
    int pivotKey = T[low];
    while (low < high && T[high] > pivotKey)
        high--;
    T[low] = T[high];
    while (low < high && T[low] < pivotKey)
        low++;
    T[high] = T[low];
    T[low] = pivotKey;
    return low;
}

void Qsort(int T[], int low, int high)
{
    if (low < high)
    {
        int pivotloc = Partion(T, low, high);
        Qsort(T, low, pivotloc - 1);
        Qsort(T, pivotloc + 1, high);
    }
}

int main()
{
    int n;
    scanf("%d", &n);
    int *array = malloc(n * sizeof(int));
    int index;
    for (index = 0; index < n; index++)
    {
        scanf("%d", &array[index]);
    }
    Qsort(array, 0, n - 1);
    for (index = 0; index < n; index++)
    {
        printf("%d ", array[index]);
    }
    return 0;
}