#include <stdio.h>
#include<ctype.h>
#include <stdlib.h>
#include<string.h>

typedef struct Node {
    char key[10];
    struct Node *left, *right;
    int times;
} TreeNode;

TreeNode *insert(char *temp, TreeNode *T) {
    if (T == NULL) {
        T = malloc(sizeof(TreeNode));
        T->right = T->left = NULL;
        strcpy(T->key,temp);
        T->times = 1;
    } else if (strcmp(temp, T->key) < 0) {
        T->left=insert(temp, T->left);
    } else if (strcmp(temp, T->key) > 0) {
        T->right=insert(temp, T->right);
    } else {
        /*At this time,the key is equal to the temp*/
        T->times++;
    }
    return T;
}

void printInOrder(TreeNode *T) {
    if (T != NULL) {
        printInOrder(T->left);
        printf("%s %d\n", T->key, T->times);
        printInOrder(T->right);
    }
}

int main() {
    //READ
    FILE *in = fopen("article.txt", "r");
    char buffer[1024];
    TreeNode *root = NULL;
    while (fgets(buffer, 1024, in) != NULL) {
        int i = 0;
        while (buffer[i] != '\0') {
            //READ A WORD
            if (isalpha(buffer[i])) {
                int t = 0;
                char temp[10];
                while (isalpha(buffer[i])) {
                    buffer[i] = (char) tolower(buffer[i]);
                    temp[t] = buffer[i];
                    i++;
                    t++;
                }
                temp[t] = '\0';
                root=insert(temp, root);
            }
            i++;
        }
    }
    //print 3 node
    TreeNode* root_temp=root;
    int times=0;
    while(root_temp&&times<3){
        printf("%s ",root_temp->key);
        root_temp=root_temp->right;
        times++;
    }
    putchar('\n');
    //Above is the problem need
    printInOrder(root);
    fclose(in);
    return 0;
}