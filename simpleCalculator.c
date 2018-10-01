#include <stdio.h>
int main()
{
    int number[100];
    char oper[100];
    int i = 0, t;
    while (1)
    {
        scanf("%d %c", &number[i], &oper[i]);
        if (oper[i] == '=')
            break;
        i++;
    }

    int len = i + 1;
    for (t = 0; t < len; t++)
    {
        if (oper[t] == '*')
        {
            number[t + 1] = number[t] * number[t + 1];
            number[t] = 0;
            oper[t] = '+';
        }
        else if (oper[t] == '/')
        {
            number[t + 1] = number[t] / number[t + 1];
            number[t] = 0;
            oper[t] = '+';
        }
        else if (oper[t] == '-')
        {
            number[t + 1] = -number[t + 1];
            oper[t] = '+';
        }
    }
    int result = 0;
    if (oper[0] == '=')
    {
        printf("%d", number[i]);
        return 0;
    }
    for (t = 0; t < len; t++)
    {
        result += number[t];
    }
    printf("%d", result);
    return 0;
}