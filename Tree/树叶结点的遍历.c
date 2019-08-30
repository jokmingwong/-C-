#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int key;
    struct Node *right, *left;
    int height;
};
typedef struct Node Tree_node;

Tree_node *insert_order_tree(Tree_node *T, int i)
{
    if (T == NULL)
    {
        T = malloc(sizeof(Tree_node));
        T->key = i;
        T->right = T->left = NULL;
    }
    else if (i < T->key)
    {
        T->left = insert_order_tree(T->left, i);
    }
    else if (i >= T->key)
    {
        T->right = insert_order_tree(T->right, i);
    }
    return T;
}

void setHeight(Tree_node *T, int d)
{
    if (T == NULL)
    {
        return;
    }
    else
    {
        T->height = d;
        setHeight(T->left, d + 1);
        setHeight(T->right, d + 1);
    }
}

//输出叶子
void print_leaf(Tree_node *l)
{
    Tree_node *q = l;
    /*This is a leaf*/
    if (q->right == NULL && q->left == NULL)
    {
        printf("%d %d\n", q->key, q->height);
    }
    else
    {
        if (q->left != NULL)
            print_leaf(q->left);
        if (q->right != NULL)
            print_leaf(q->right);
    }
}

int main()
{
    int num;
    scanf("%d", &num);
    if (num <= 0)
        exit(0);
    Tree_node *root = NULL;
    while (num--)
    {
        int temp;
        scanf("%d", &temp);
        root = insert_order_tree(root, temp);
    }
    setHeight(root, 1);
    print_leaf(root);
    return 0;
}