#include <stdio.h>
int main()
{
    //输入想清楚注释的C文件名称
    FILE *in = fopen("CACULATOR.c", "r");
    FILE *out = fopen("CACULATOR2.c", "w");
    char buffer[1026];
    while (fgets(buffer, 1026, in) != NULL)
    {
        int i = 0;
        while (buffer[i] != '\0')
        {
            if (buffer[i] == '/' && buffer[i + 1] == '*')
            {
                buffer[i] = ' ';
                buffer[i + 1] = ' ';
                int j = i + 2;
                while (buffer[j] != '*' || buffer[j + 1] != '/')
                {
                    buffer[j] = ' ';
                    j++;
                }
                buffer[j] = ' ';
                buffer[j + 1] = '\0';
                break;
            }
            i++;
        }
        fputs(buffer, out);
    }
    fclose(in);
    fclose(out);
    return 0;
}