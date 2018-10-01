#include <ctype.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct Node
{
    int times;
    char words[20];
    struct Node *next;
} WordNode;

//按照字典序插入一个未出现过的新词结点
WordNode *insert_word(WordNode *list, char *n1)
{
    WordNode *q, *r;
    WordNode *pb = (WordNode *)malloc(sizeof(WordNode));
    strcpy(pb->words, n1);
    pb->times = 1;
    if (list == NULL || (list != NULL && strcmp(n1, list->words) < 0))
    {
        pb->next = list;
        list = pb; //指向被插入的新结点
    }
    else
    {
        q = list;
        while (q != NULL && strcmp(n1, q->words) > 0)
        {
            r = q;
            q = q->next;
        }
        pb->next = q;
        r->next = pb;
    }
    return list;
}

int find_and_plustime(WordNode *list, char *target)
{
    WordNode *p = list;
    while (p != NULL)
    {
        if (strcmp(p->words, target) == 0)
        {
            //若发现这个词之前存在
            p->times++;
            return 1;
        }
        p = p->next;
    }
    return 0;
}
int main()
{
    char input[1000];
    FILE *in = fopen("article.txt", "r");
    WordNode *list = NULL;
    while (fgets(input, 1026, in) != NULL)
    {
        int index;
        char temp[30] = " ";
        int pos = 0;
        for (index = 0; index < strlen(input); index++)
        {
            if (isalpha(input[index]))
            {
                temp[pos++] = tolower(input[index]);
            }
            else if (!isalpha(input[index]) && pos != 0)
            {
                if (!find_and_plustime(list, temp))
                {
                    list = insert_word(list, temp);
                }
                memset(temp, '\0', sizeof(char) * pos);
                pos = 0;
            }
        }
    }
    WordNode *wp = list;
    while (wp != NULL)
    {
        printf("%s ", wp->words);
        printf("%d\n", wp->times);
        wp = wp->next;
    }
    fclose(in);
    return 0;
}