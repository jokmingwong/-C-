#include <stdio.h>
int main()
{
    FILE *in, *out;
    in = fopen("encrypt.txt", "r");
    out = fopen("output.txt", "w");
    char key[27];
    char map[27];
    scanf("%s", key);
    char INPUT[1000];
    fgets(INPUT, 1000, in);
    int i;
    int t = 0;
    int alphbetCount[26] = {0};
    //Delete odd letter
    for (i = 0; key[i] != '\0'; i++)
    {
        if (alphbetCount[key[i] - 'a'] >= 1)
        {
            continue;
        }
        alphbetCount[key[i] - 'a']++;
        map[t++] = key[i];
    }
    for (i = 25; i >= 0; i--)
    {
        if (t <= 25 && alphbetCount[i] == 0)
        {
            map[t++] = 'a' + i;
        }
    }
    map[26] = '\0';
    int q;
    for (q = 0; INPUT[q] != '\0' && q < 1000; q++)
    {
        if (INPUT[q] >= 'a' && INPUT[q] <= 'z')
            fputc(map[INPUT[q] - 'a'], out);
        else
        {
            fputc(INPUT[q], out);
        }
    }
    return 0;
}