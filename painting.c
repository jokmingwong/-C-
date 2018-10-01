#include <stdio.h>
#define width 10
#define length 10
void painting(char(*) temp[length], int i, int j)
{
    temp[i][j] = '2';
    if (j + 1 < n && temp[i][j + 1] == '0')
    {
        painting(temp[length], i, j + 1);
    }
    if (j > 0 && temp[i][j - 1] == '0')
    {
        painting(temp[length], i, j - 1);
    }
    if (i + 1 < width && temp[i + 1][j] == '0')
    {
        painting(temp[length], i + 1, j);
    }
    if (i > 0 && temp[i - 1][j] == '0')
    {
        painting(temp[length], i - 1, j);
    }
}
int getSquare(char(*) test[length])
{
    int result = 0;
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            if (test[i][j] == '2')
                result++;
        }
    }
    return result;
}
int main()
{
    int i;
    int j;
    char test[length][width];
    for (i = 0; i < length; i++)
    {
        for (j = 0; j < width; j++)
        {
            putchar(test[i][j]);
        }
    }
    painting(test, 0, 0);
    printf("%d", getSquare(test));
    return 0;
}