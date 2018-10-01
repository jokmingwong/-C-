#include <stdio.h>
int main()
{
    int a1[10];
    int a2[10];
    int a;
    //Input
    int i = 0;
    scanf("%d", &a);
    while (a != -1)
    {
        a1[i] = a;
        i++;
        scanf("%d", &a);
    }

    int len1 = i;

    int p = 0;
    scanf("%d", &a);
    while (a != -1)
    {
        a2[p] = a;
        p++;
        scanf("%d", &a);
    }

    int len2 = p;
    //Solve
    int index, q;
    for (index = 0; index < len1; index++)
    {
        for (q = 0; q < len2; q++)
        {
            if (a2[q] == a1[index])
                break;
            if (q == len2 - 1)
                printf("%d ", a1[index]);
        }
    }

    return 0;
}