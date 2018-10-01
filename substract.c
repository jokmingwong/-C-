#include <stdio.h>
#include <string.h>

int comp(const char *a, const char *b); //返回1表示a>b，返回-1表示a<b，返回0表示a==b

int sub(const char *a, const char *b, char *c); //执行相减操作，a>b
int main()
{

    char a[100], b[100];
    char c[101];
    int k, comp_res;

    gets(a);
    gets(b);

    comp_res = comp(a, b);

    if (comp_res == 0)
    {
        printf("0\n");
        return 0;
    }

    if (comp_res == 1)
    {
        k = sub(a, b, c);
    }
    else
    {
        k = sub(b, a, c);
        printf("-");
    }

    while (k >= 0)
    {
        printf("%c", c[k]);
        k--;
    }
    printf("\n");

    return 0;
}

int comp(const char *a, const char *b)
{
    int alen = strlen(a);
    int blen = strlen(b);
    int i = 0;

    if (alen > blen)
    {
        return 1;
    }
    else if (alen < blen)
    {
        return -1;
    }
    else
    {
        while (a[i] == b[i] && i < alen)
        {
            i++;
        }
        if (i == alen)
        {
            return 0;
        }
        else if (a[i] > b[i])
        {
            return 1;
        }
        else
        {
            return -1;
        }
    }
}

int sub(const char *a, const char *b, char *c)
{
    int alen, blen;
    int carry = 0;
    int temp;
    int i, j, k;

    alen = strlen(a);
    blen = strlen(b);
    i = alen - 1;
    j = blen - 1;
    k = 0;

    while (j >= 0)
    {
        temp = a[i] - b[j] - carry;
        if (temp < 0)
        {
            temp += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        c[k] = temp + '0';

        i--;
        j--;
        k++;
    }

    while (i >= 0)
    {
        temp = a[i] - '0' - carry;
        if (temp < 0)
        {
            temp += 10;
            carry = 1;
        }
        else
        {
            carry = 0;
        }
        c[k] = temp + '0';
        i--;
        k++;
    }

    k--;
    while (c[k] == '0')
        k--;
    return k;
}