#include <ctype.h>
#include <stdio.h>
int main()
{
    char oper[100];
    gets(oper);
    //Delete space
    int i = 0, j = 0;
    while (oper[i] != '\0')
    {
        if (isspace(oper[i]))
        {
            i++;
        }
        else
        {
            oper[j] = oper[i];
            i++;
            j++;
        }
    }
    oper[j] = '\0';
    puts(oper);
    /*
    char *variable[20];
    char *value[20];
    int index_value = 0;
    */
    return 0;
}
