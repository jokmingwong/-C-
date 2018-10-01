#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
    int num;
    struct Node *next;
} LNode;

int main()
{
    LNode *p;
    LNode *list = NULL, *r;
    int n, step, begin;
    scanf("%d %d %d", &n, &step, &begin);
    int i;
    for (i = 1; i <= n; i++)
    {
        p = (LNode *)malloc(sizeof(LNode));
        p->num = i;
        if (list == NULL)
        {
            list = p;
        }
        else
        {
            r->next = p;
        }
        r = p;
    }
    r->next = list;
    r = r->next;

    //Find the first monkey
    while (r->num != begin)
    {
        r = r->next;
    }

    while (1)
    {
        LNode *pre_r;
        int times = step - 1;
        if (times == 0)
        {
            printf("%d", n);
            return 0;
        }
        while (times > 0)
        {
            pre_r = r;
            r = r->next;
            times--;
        }

        if (r->next != r)
        {
            pre_r->next = r->next;
            free(r);
            r = pre_r->next;
        }
        else
        {
            printf("%d\n", r->num);
            break;
        }
    }

    return 0;
}