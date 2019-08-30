#include <stdio.h>
void solve(char *t)
{
    int i;
    int count;
    if (t[0] == '0')
    {
        count = -1;
        i = 2; //直接跳跃小数点开始
        while (t[i] != '\0')
        {
            if (t[i] == '0')
            {
                count--;
            }
            else
            {
                break;
            }
            i++;
        }
        putchar(t[i]);
        i++;
        if (t[i] != '\0')
            putchar('.');
        while (t[i] != '\0')
        {
            putchar(t[i]);
            i++;
        }
        printf("e%d\n", count);
    }
    else
    {
        int i = 0, count = 0;
        putchar(t[i++]);
        putchar('.');
        while (t[i] != '\0')
        {
            if (t[i] == '.')
            {
                count = i - 1;
            }
            else
            {
                putchar(t[i]);
            }
            i++;
        }
        printf("e%d", count);
    }
}
int main()
{
    char S[50];
    scanf("%s", S);
    solve(S);
    return 0;
}