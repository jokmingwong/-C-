#include <stdio.h>
#include <stdlib.h>
#define MaxDgree 1000
typedef struct Node
{
    int Coefficients;
    int HighPower;
    struct Node *next;
} * Polynomial;

//??highpower??????
Polynomial insert(Polynomial poly, int a, int b)
{
    Polynomial q, r;
    Polynomial pb = (Polynomial)malloc(sizeof(struct Node));
    pb->Coefficients = a;
    pb->HighPower = b;
    if (poly == NULL || (poly != NULL && b > poly->HighPower))
    {
        pb->next = poly;
        poly = pb; //?????????
    }
    else
    {
        q = poly->next;
        r = poly;
        while (q != NULL && b < q->HighPower)
        {
            r = r->next;
            q = q->next;
        }
        pb->next = q;
        r->next = pb;
    }
    return poly;
}

Polynomial MulitPolynomial(Polynomial list1, Polynomial list2)
{
    Polynomial res = NULL;
    Polynomial p1 = list1;
    while (p1 != NULL)
    {
        Polynomial p2 = list2;
        while (p2 != NULL)
        {
            res = insert(res, p1->Coefficients * p2->Coefficients, p1->HighPower + p2->HighPower);
            p2 = p2->next;
        }
        p1 = p1->next;
    }
    //???
    Polynomial pq = res;
    while (pq != NULL)
    {
        if (pq->HighPower != -1)
        {
            Polynomial pq2 = pq->next;
            while (pq2 != NULL)
            {
                if (pq2->HighPower != -1 && pq->HighPower == pq2->HighPower)
                {
                    pq->Coefficients += pq2->Coefficients;
                    //????????
                    pq2->HighPower = -1;
                }
                pq2 = pq2->next;
            }
        }
        pq = pq->next;
    }
    return res;
}

int main()
{
    int a, b;
    Polynomial poly1 = NULL, poly2 = NULL;
    //Poly1???
    while (1)
    {
        scanf("%d %d", &a, &b);
        poly1 = insert(poly1, a, b);
        if (getchar() == '\n')
            break;
    }
    //Poly2???
    while (1)
    {
        scanf("%d %d", &a, &b);
        poly2 = insert(poly2, a, b);
        if (getchar() == '\n')
            break;
    }
    Polynomial result = MulitPolynomial(poly1, poly2);
    Polynomial p = result;
    while (p != NULL)
    {
        if (p->HighPower != -1)
        {
            printf("%d %d ", p->Coefficients, p->HighPower);
        }
        p = p->next;
    }
    return 0;
}