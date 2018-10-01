#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define MAX_SIZE 11

void swap(char *t1, char *t2)
{
    char temp[MAX_SIZE];
    strcpy(temp, t1);
    strcpy(t1, t2);
    strcpy(t2, temp);
}
void printSpace(char *t)
{
    int q = 12 - strlen(t);
    while (q--)
    {
        if (q < 0)
            break;
        printf(" ");
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    char dic[num][MAX_SIZE];
    char telNum[num][MAX_SIZE];
    int i;
    for (i = 0; i < num; i++)
    {
        scanf("%s", dic[i]);
        scanf("%s", telNum[i]);
    }
    //bubble sort
    int j;
    for (i = 0; i < num - 1; i++)
    {
        for (j = i + 1; j < num; j++)
        {
            if (strcmp(dic[i], dic[j]) > 0)
            {
                swap(dic[i], dic[j]);
                swap(telNum[i], telNum[j]);
            }
        }
    }

    for (i = 0; i < num; i++)
    {
        printSpace(dic[i]);
        printf("%s", dic[i]);
        printSpace(telNum[i]);
        printf("%s\n", telNum[i]);
    }
    return 0;
}