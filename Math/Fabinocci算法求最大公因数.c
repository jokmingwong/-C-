#include <stdio.h>
int main()
{
    int N, M;
    scanf("%d %d", &N, &M);
    //Ensure the M is bigger one
    if (M < N)
    {
        int temp = N;
        N = M;
        M = temp;
    }
    while (M % N != 0)
    {
        int tp = M % N;
        M = N;
        N = tp;
    }
    printf("%d\n", N);
    return 0;
}