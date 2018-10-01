#include <stdio.h>
int testPower(int n, int q)
{
    if (q == 1)
    {
        return n;
    }
    else if (q == 0)
    {
        return 1;
    }
    if (q % 2 == 0)
    {
        return testPower(n, q / 2) * testPower(n, q / 2);
    }
    else
    {
        return (n * testPower(n, (q - 1) / 2) * testPower(n, (q - 1) / 2));
    }
}
int main()
{
    int n, q;
    printf("The number you want to input:\n");
    scanf("%d %d", &n, &q);
    printf("the result is:%d", testPower(n, q));
    return 0;
}