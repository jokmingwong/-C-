#include "stdio.h"
#include "stdlib.h"
int *orderArray(int n)
{
    int *res = (int *)malloc(sizeof(int) * n);
    int i;
    for (i = 1; i <= n; i++)
    {
        res[i - 1] = i;
    }
    return res;
}
void printArray(int *S, int n)
{
    int i = 0;
    for (; i < n - 1; i++)
    {
        printf("%d->", S[i]);
    }
    printf("%d", S[n - 1]);
}
int main()
{
    int n;
    scanf("%d", &n);
    printArray(orderArray(n), n);
    return 0;
}