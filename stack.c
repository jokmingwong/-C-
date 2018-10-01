#include <stdio.h>
#define MAXSIZE 100
int main()
{
    int stack[100];
    int top = -1;
    while (1)
    {
        int op;
        scanf("%d", &op);
        switch (op)
        {
        case 1:
            //入栈
            if (top >= 99)
                printf("error ");
            else
            {
                int item;
                scanf("%d", &item);
                stack[++top] = item;
            }
            break;
        case 0:
            //出栈
            if (top <= -1)
                printf("error ");
            else
            {
                printf("%d ", stack[top--]);
            }
            break;
        case -1:
            //结束
            return 0;
        }
    }
    return 0;
}