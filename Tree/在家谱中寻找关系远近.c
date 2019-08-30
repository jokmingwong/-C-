#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAXSIZE 22
//这道题给我的教训就是字符串处理一定要加用string头文件里面的函数
typedef struct Node {
  struct Node *parent, *left, *right;
  char key[MAXSIZE];
  int height;
} TreeNode;

void setHeight(TreeNode *T, int d) {
  if (T == NULL) {
    return;
  } else {
    T->height = d;
    setHeight(T->left, d + 1);
    setHeight(T->right, d + 1);
  }
}

TreeNode *find(char *s, TreeNode *target_tree) {
  if (target_tree == NULL)
    return NULL;
  TreeNode *target = NULL;
  /* If this node is not the target,find its children*/
  if (strcmp(target_tree->key, s) != 0) {
    if ((target = find(s, target_tree->left)) != NULL) {
      return target;
    } else if ((target = find(s, target_tree->right)) != NULL) {
      return target;
    } else
      return NULL;
  } /* else we find the node is the target*/
  else {
    return target_tree;
  }
}

TreeNode *MakeNode(char *s) {
  TreeNode *T = malloc(sizeof(TreeNode));
  T->right = T->left = NULL;
  strcpy(T->key, s);
  return T;
}

void showCommonParent(TreeNode *node1, TreeNode *node2) {
  TreeNode *t1 = node1, *t2 = node2;
  while (t1 != NULL && t1 != t2) {
    t1 = t1->parent;
    t2 = t2->parent;
  }
  if (t1 != NULL) {
    int diff = node1->height - t1->height;
    printf("%s %s %d\n", t1->key, node1->key, diff);
    printf("%s %s %d\n", t1->key, node2->key, diff);
  }
}

int main() {
  int num;
  FILE *in = fopen("in.txt", "r");
  fscanf(in, "%d", &num);
  TreeNode *root = NULL;
  while (num-- > 0) {
    char s1[MAXSIZE], s2[MAXSIZE], s3[MAXSIZE];
    fscanf(in, "%s %s %s", s1, s2, s3);
    TreeNode *temp = find(s1, root);
    /*It means this is an empty tree*/
    if (temp == NULL) {
      root = MakeNode(s1);
      root->parent = NULL;
      temp = root;
    }
    /*Judge s2*/
    if (strcmp(s2, "NULL") == 0) {
      temp->left = NULL;
    } else {
      temp->left = MakeNode(s2);
      temp->left->parent = temp;
    }
    /*Judge s3*/
    if (strcmp(s3, "NULL") == 0) {
      temp->right = NULL;
    } else {
      temp->right = MakeNode(s3);
      temp->right->parent = temp;
    }
  }
  setHeight(root, 1);
  char targetNode1[MAXSIZE], targetNode2[MAXSIZE];
  scanf("%s %s", targetNode1, targetNode2);
  TreeNode *t1 = find(targetNode1, root), *t2 = find(targetNode2, root);
  int result = (t1->height) - (t2->height);
  if (result == 0) {
    showCommonParent(t1, t2);
  } else {
    printf("%s %s %d\n", targetNode1, targetNode2, result);
  }
  fclose(in);
  return 0;
}