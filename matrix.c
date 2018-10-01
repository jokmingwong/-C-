#include <stdio.h>
int digt(int num)
{
    int count = 0;
    if (num == 0)
        return 1;
    while (num != 0)
    {
        num /= 10;
        count++;
    }
    return count;
}
int main()
{
    int a, i, t;
    scanf("%d", &a);
    int matrix[a][a];
    //initialise
    for (i = 0; i < a; i++)
    {
        for (t = 0; t < a; t++)
        {
            scanf("%d", &matrix[i][t]);
        }
    }
    //Judege char
    while (1)
    {
        char c;
        scanf("%c", &c);
        if (c == '#')
            break;
        else if (c == '+')
        {
            int k, j;
            for (k = 0; k < a; k++)
            {
                for (j = 0; j < a; j++)
                {
                    int temp;
                    scanf("%d", &temp);
                    matrix[k][j] += temp;
                }
            }
        }
        else if (c == '-')
        {
            int k, j;
            for (k = 0; k < a; k++)
            {
                for (j = 0; j < a; j++)
                {
                    int temp;
                    scanf("%d", &temp);
                    matrix[k][j] -= temp;
                }
            }
        }
    }
    //print out
    for (i = 0; i < a; i++)
    {
        for (t = 0; t < a; t++)
        {
            if (matrix[i][t] >= 0)
            {
                int times = 5 - digt(matrix[i][t]);
                while (times--)
                    printf(" ");
                printf("%d", matrix[i][t]);
            }
            else
            {
                int times = 4 - digt(matrix[i][t]);
                while (times--)
                    printf(" ");
                printf("%d", matrix[i][t]);
            }
        }
        printf("\n");
    }
    return 0;
}