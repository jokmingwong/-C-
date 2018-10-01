#include <stdio.h>
int main()
{
    int board[19][19];
    int i, j;
    //initialize
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 19; j++)
        {
            scanf("%d", &board[i][j]);
        }
    }
    //solve
    for (i = 0; i < 19; i++)
    {
        for (j = 0; j < 19; j++)
        {
            if (board[i][j] == 1)
            {
                int flag = 0;
                int t = 1;
                while (j + t < 19 && board[i][j + t] == 1)
                {
                    t++;
                }
                if (t == 4 && ((j + t < 19 && board[i][j + t] == 0) || (j - 1 >= 0 && board[i][j - 1] == 0)))
                    flag = 1;
                int q = 1;
                while (i + q < 19 && board[i + q][j] == 1)
                {
                    q++;
                }
                if (q == 4 && ((i + q < 19 && board[i + q][j] == 0) || (i - 1 >= 0 && board[i - 1][j] == 0)))
                    flag = 1;
                int p = 1;
                while (i + p < 19 && j + p < 19 && board[i + p][j + p] == 1)
                {
                    p++;
                }
                if (p == 4 && ((i + p < 19 && j + p < 19 && board[i + p][j + p] == 0) || (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 0)))
                    flag = 1;
                int f = 1;
                while (i + f < 19 && j - f >= 0 && board[i + f][j - f] == 1)
                {
                    f++;
                }
                if (f == 4 && ((i + f < 19 && j - f >= 0 && board[i + f][j - f] == 0) || (i - 1 >= 0 && j + 1 < 19 && board[i + 1][j + 1] == 0)))
                    flag = 1;
                //说明找到了
                if (flag)
                {
                    printf("1:%d,%d\n", i + 1, j + 1);
                    return 0;
                }
            }
            else if (board[i][j] == 2)
            {
                int flag = 0;
                int t = 1;
                while (j + t < 19 && board[i][j + t] == 2)
                {
                    t++;
                }
                if (t == 4 && ((j + t < 19 && board[i][j + t] == 0) || (j - 1 >= 0 && board[i][j - 1] == 0)))
                    flag = 1;
                int q = 1;
                while (i + q < 19 && board[i + q][j] == 2)
                {
                    q++;
                }
                if (q == 4 && ((i + q < 19 && board[i + q][j] == 0) || (i - 1 >= 0 && board[i - 1][j] == 0)))
                    flag = 1;
                int p = 1;
                while (i + p < 19 && j + p < 19 && board[i + p][j + p] == 2)
                {
                    p++;
                }
                if (p == 4 && ((i + p < 19 && j + p < 19 && board[i + p][j + p] == 0) || (i - 1 >= 0 && j - 1 >= 0 && board[i - 1][j - 1] == 0)))
                    flag = 1;
                int f = 1;
                while (i + f < 19 && j - f >= 0 && board[i + f][j - f] == 2)
                {
                    f++;
                }
                if (f == 4 && ((i + f < 19 && j - f >= 0 && board[i + f][j - f] == 0) || (i - 1 >= 0 && j + 1 < 19 && board[i + 1][j + 1] == 0)))
                    flag = 1;
                //说明找到了
                if (flag)
                {
                    printf("2:%d,%d\n", i + 1, j + 1);
                    return 0;
                }
            }
            if (i == 18 && j == 18)
            {
                printf("No\n");
                return 0;
            }
        }
    }
}