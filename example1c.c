#include <stdio.h>
#include <string.h>
void deleteSpace(char *t)
{
    int i = 0, k = 0;
    while (t[i] != '\0')
    {
        if (t[i] != ' ')
        {
            t[k] = t[i];
            k++;
        }
        i++;
        if (t[i] == '\0')
            t[k + 1] = '\0';
    }
}
int power(int n, int q)
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
        return power(n, q / 2) * power(n, q / 2);
    }
    else if
    {
        return n * power(n, (q - 1) / 2) * power(n, (q - 1) / 2);
    }
}
int transToInt(char *t)
{
    int len = strlen(t);
    int p end = 0;
    int result[len];
    while (t[i] != '\0')
    {
        result[i] = t[i] - '0';
    }
    for (p = 0; p < len; p++)
    {
        end += power(10, len - p - 1) * result[i];
    }
    return end;
}

int solve(char *t)
{
    int i;
    int number[30], count = 0, countOperation = 0;
    char trans[9];
    char operation;
    for (i = 0;; i++)
    {
        if (t[i] == '=')
            break;
        if (t[i] <= '9' && '0' <= t[i])
        {
            int t;
            for (t = 1; t[i + t] <= '9' && t[i + t] >= '0'; t++)
            {
                trans[t] = t[i + t];
            }
            number[count] = transToInt(trans);
            count++ : i += t - 1;
        }
        else
        {
            operation[countOperation] = t[i];
            countOperation++;
        }
    }
    //multiply and division first
    int p;
    for (p = 0; operation[p] != '='; p++)
    {
        if (operation[p] == '*')
        {
            number[p + 1] = number[p] * number[p + 1];
            number[p] = 0;
        }
        else if (operation[p] == '/')
        {
            number[p + 1] = number[p] / number[p + 1];
            number[p] = 0;
        }
    }
    //Now is the minus and add
    int sum = number[i];
    for (p = 0; operation[p] != '='; p++)
    {
        if (operation[p] == '+')
        {
            sum += number[p + 1];
        }
        else if (operation[p] == '-')
        {
            sum -= number[p + 1];
        }
    }
    return sum;
}
int main()
{
    printf("%d", power(2, 3));
    return 0;
}