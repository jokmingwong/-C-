#include <stdio.h>
#include <string.h>
void find(char *T, char *R)
{
    int i, lenT = strlen(T), lenR = strlen(R);
    for (i = 0; i < lenR; i++)
    {
        if (T[0] == R[i] && i + lenT - 1 < lenR && T[lenT - 1] == R[i + lenT - 1])
        {
            int j;
            for (j = 0; j < lenT; j++)
            {
                if (T[j] != R[i + j])
                {
                    //Not match and continue to find string
                    break;
                }
            }
            //Found
            if (j == lenT)
            {
                printf("The position is %d\n", i);
                return;
            }
        }
    }
    printf("NOT FOUND\n");
}
int main()
{
    char test[1000];
    FILE *in = fopen("books.txt", "r");
    fgets(test, 1000, in);
    printf("%s\n", test);
    char target[10];
    scanf("%s", target);
    find(target, test);
    fclose(in);
    return 0;
}