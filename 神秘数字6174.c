#include <math.h>
#include <stdio.h>
int showNum(int a)
{
    int temp[4];
    temp[0] = a % 10;
    temp[1] = (a - temp[0]) / 10 % 10;
    temp[2] = ((a - temp[0]) / 100) % 10;
    temp[3] = a / 1000;
    int q;
    for (q = 0; q < 3; q++)
    {
        int j;
        for (j = q + 1; j < 4; j++)
        {
            if (temp[j] < temp[q])
            {
                int te = temp[j];
                temp[j] = temp[q];
                temp[q] = te;
            }
        }
    }
    int res1 = 0, res2 = 0;
    for (q = 0; q < 4; q++)
    {
        res1 += pow(10, q) * temp[q];
        res2 += pow(10, 3 - q) * temp[q];
    }
    int res3 = res1 - res2;
    printf("%d-%d=%d\n", res1, res2, res3);
    return res3;
}

int main()
{
    int num;
    scanf("%d", &num);
    int times = 1;
    while ((num = showNum(num)) != 6174)
    {
        times++;
    }
    printf("%d\n", times);
    return 0;
}