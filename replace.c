#include <stdio.h>
#include <ctype.h>
int main()
{
    FILE *in, *out;
    in = fopen("filein.txt", "r");
    out = fopen("fileout.txt", "w");
    char input[10];
    gets(input);
    char output[10];
    gets(output);
    char buffer[1024];
    while (fgets(buffer, 1024, in) != NULL)
    {
        int i;
        for (i = 0; buffer[i] != '\0' && i < 1024; i++)
        {
            if (toupper(buffer[i]) == input[0] || tolower(buffer[i]) == input[0])
            {
                int t;
                for (t = 0; t < 10 && input[t] != '\0'; t++)
                {
                    if (islower(buffer[i + t]))
                    {

                        if ((input[t] != toupper(buffer[i + t])) && (input[t] != buffer[i + t]))
                            break;
                    }
                    else if (isupper(buffer[i + t]))
                    {
                        if ((input[t] != tolower(buffer[i + t])) && (input[t] != buffer[i + t]))
                            break;
                    }
                }
                if (input[t] == '\0')
                {
                    fprintf(out, "%s", output);
                    i += t - 1;
                    continue;
                }
            }
            fputc(buffer[i], out);
        }
    }

    return 0;
}