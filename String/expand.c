#include <stdio.h>
int main()
{
    char S[20];
    gets(S);
    int i = 0;
    while (1)
    {
        if (S[i] == '\0')
            break;
        if (S[i] == '-')
        {
            if (('a' <= S[i - 1] && S[i + 1] <= 'z') || ('A' <= S[i - 1] && S[i + 1] <= 'Z') || ('0' <= S[i - 1] && S[i + 1] <= '9'))
            {
                char temp = S[i - 1] + 1;
                while (1)
                {
                    putchar(temp);
                    if (temp == S[i + 1] - 1)
                        break;
                    temp++;
                }
            }
            else
            {
                putchar('-');
            }
        }
        else
        {
            putchar(S[i]);
        }
        i++;
    }
    return 0;
}