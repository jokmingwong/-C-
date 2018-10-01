#include <stdio.h>
#include <string.h>
#define MAX_SIZE 11
typedef struct tel
{
    char name[MAX_SIZE];
    char number[MAX_SIZE];
} telbook;

void swapTelBook(int i, int j, telbook *t)
{
    telbook temp;
    temp = t[i];
    t[i] = t[j];
    t[j] = temp;
}

int main()
{
    int num;
    scanf("%d", &num);
    int i;
    telbook t[num];
    for (i = 0; i < num; i++)
    {
        scanf("%s", t[i].name);
        if (strlen(t[i].name) > 10)
            t[i].name[10] = '\0';
        scanf("%s", t[i].number);
        if (strlen(t[i].number) > 10)
            t[i].number[10] = '\0';
    }
    int j;
    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(t[i].name, t[j].name) > 0)
            {
                swapTelBook(i, j, t);
            }
        }
    }
    for (i = 0; i < num; i++)
    {
        printf("%12s", t[i].name);
        printf("%12s\n", t[i].number);
    }
    return 0;
}