#include <stdio.h>
void swap(int a, int b, char *c)
{
    char temp = c[a];
    c[a] = c[b];
    c[b] = temp;
}
void sort(int from, int to, char *temp)
{
    int i;
    for (i = from; i < to - 1; i++)
    {
        int j;
        for (j = i + 1; j < to; j++)
        {
            if (temp[j] < temp[i])
            {
                swap(j, i, temp);
            }
        }
    }
}

//k表示当前选取到第几个数,m表示共有多少数
void permutation(int k, int m, char *temp)
{
    if (k == m)
    {
        int i;
        for (i = 0; i < m; i++)
        {
            printf("%c ", temp[i]);
        }
        printf("\n");
    }
    //Begin to swap
    else
    {
        int t;
        for (t = k; t < m; t++)
        {
            sort(k, m, temp);
            swap(k, t, temp);
            permutation(k + 1, m, temp);
            swap(k, t, temp);
        }
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    int i;
    char temp[num];
    //Initialisation
    for (i = 0; i < num; i++)
    {
        temp[i] = '0' + i + 1;
    }
    permutation(0, num, temp);
    return 0;
}