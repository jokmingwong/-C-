#include <stdio.h>
#include <stdlib.h>

//使用链表创建的hash表
typedef struct Node
{
    int times;
    int val;
    struct Node *next;
} ListNode;

int majorityElement(int *nums, int numsSize)
{
    ListNode *head = malloc(sizeof(ListNode));
    head->next = NULL;
    int i;
    for (i = 0; i < numsSize; i++)
    {
        //先找是否结点出现过
        ListNode *q = head->next;
        ListNode *r = head;
        while (q)
        {
            //这个数出现过
            if (q->val == nums[i])
            {
                q->times++;
                break;
            }
            r = q;
            q = q->next;
        }
        //若没出现过则新创建一个
        if (q == NULL)
        {
            ListNode *p = malloc(sizeof(ListNode));
            p->val = nums[i];
            p->times = 1;
            p->next = NULL;
            r->next = p;
        }
    }
    ListNode *t = head->next;
    int res = 0;
    int maxTimes = 0;
    while (t)
    {
        if (t->times > maxTimes)
        {
            maxTimes = t->times;
            res = t->val;
        }
        t = t->next;
    }
    return res;
}

int main()
{
    int numSizes;
    scanf("%d", &numSizes);
    int nums[numSizes];
    int i = 0;
    for (; i < numSizes; i++)
    {
        scanf("%d", &nums[i]);
    }
    printf("%d", majorityElement(nums, numSizes));
    return 0;
}