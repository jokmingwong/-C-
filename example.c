#include <ctype.h>
#include <stdio.h>
#include <string.h>

#define MAXSIZE 200
int top = -1;
typedef struct
{
    char s;
    int line;
} MISSING;
char all[200];
int allIndex = 0;
void push(char q, int t, MISSING *s)
{
    MISSING s2;
    s2.s = q;
    all[allIndex++] = q;
    s2.line = t;
    if (top >= MAXSIZE - 1)
    {
        return;
    }
    s[++top] = s2;
}

void pop(MISSING *s)
{
    if (top <= -1)
    {
        return;
    }
    top--;
}

int isEmpty()
{
    return top <= -1;
}

int main()
{
    MISSING stack[MAXSIZE];
    char buffer[1026];
    FILE *in = fopen("example.txt", "r");
    int line = 1;
    while (fgets(buffer, 1026, in) != NULL)
    {
        int i = 0;
        while (buffer[i] != '\0')
        {
            //遇到注释
            if (buffer[i] == '/' && buffer[i + 1] == '/')
                break;
            //遇到另类注释
            else if (buffer[i] == '/' && buffer[i + 1] == '*')
            {
                int j = i + 2;
                while (buffer[j] != '*' || buffer[j + 1] != '/')
                {
                    j++;
                }
                i = j + 1;
            }
            //遇到字符串
            else if (buffer[i] == '\"' || buffer[i] == '\'')
            {
                int j = i + 1;
                while (buffer[j] != '\"')
                {
                    j++;
                }
                i = j;
            }
            //遇到括号
            else if (buffer[i] == '{' || buffer[i] == '(')
            {
                push(buffer[i], line, stack);
            }
            else if (buffer[i] == '}')
            {
                //取出栈顶元素
                if (stack[top].s == '{')
                {
                    all[allIndex++] = '}';
                    pop(stack);
                }
                else
                {
                    printf("without matching \'}\' at line %d\n", line);
                    return 0;
                }
            }
            else if (buffer[i] == ')')
            {
                //取出栈顶元素
                if (stack[top].s == '(')
                {
                    all[allIndex++] = ')';
                    pop(stack);
                }
                //若不是则表示有匹配问题
                else
                {
                    printf("without matching \')\' at line %d\n", line);
                    return 0;
                }
            }
            i++;
        }
        line++;
    }
    if (!isEmpty())
    {
        if (stack[top].s == '(')
            printf("without matching \'(\' at line %d\n", stack[top].line);
        else
        {
            printf("without matching \'{\' at line %d\n", stack[top].line);
        }
        return 0;
    }
    int t;
    for (t = 0; t <= allIndex; t++)
    {
        putchar(all[t]);
    }
    fclose(in);
    return 0;
}
