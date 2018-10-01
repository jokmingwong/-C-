#include <stdio.h>
#include <stdlib.h>
typedef struct node
{
    int data;
    struct node *next; //一定要加struct才能够成功
} LNode, *LinkList;

LinkList create(int n)
{
    LinkList p, r, list = NULL;
    int temp;
    int i;
    for (i = 0; i < n; i++)
    {
        scanf("%d", &temp);
        p = (LinkList)malloc(sizeof(LNode));
        p->data = temp;
        p->next = NULL;
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
    return (list);
}

void printList(LinkList t)
{
    while (t != NULL)
    {
        printf("%d", t->data);
        if (t->next != NULL)
            printf("->");
        t = t->next;
    }
}
int main()
{
    int number;
    scanf("%d", &number);
    LinkList A = create(number);
    printList(A);
    return 0;
}