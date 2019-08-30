/*************
给定一个不含重复元素的整数数组。一个以此数组构建的最大二叉树定义如下：

二叉树的根是数组中的最大元素。
左子树是通过数组中最大值左边部分构造出的最大二叉树。
右子树是通过数组中最大值右边部分构造出的最大二叉树。
通过给定的数组构建最大二叉树，并且输出这个树的根节点。

Example 1:

输入: [3,2,1,6,0,5]
输入: 返回下面这棵树的根节点：

      6
    /   \
   3     5
    \    /
     2  0
       \
        1
注意:

给定的数组的大小在 [1, 1000] 之间。
************************/
#include <stdio.h>
#include <stdlib.h>
#define MAX_QUEUE_NUM 20
typedef struct TreeNode {
  int val;
  struct TreeNode *left;
  struct TreeNode *right;
} TreeNode;

TreeNode *insert(TreeNode *T, int item) {
  if (T == NULL) {
    T = malloc(sizeof(TreeNode));
    if (T == NULL) {
      printf("Error!");
      exit(-1);
    } else {
      T->val = item;
      T->left = T->right = NULL;
    }
  } else if (item < T->val) {
    T->left = insert(T->left, item);
  } else if (item > T->val) {
    T->right = insert(T->right, item);
  }
  return T;
}

TreeNode *constructMaximumBinaryTree(int *nums, const int begin,
                                     const int numsSize) {
  TreeNode *T = NULL;
  if (begin >= numsSize) {
    unsigned int index;
    int maxValue = -1, maxValueIndex = -1;
    for (index = 0; index < numsSize; index++)
      if (nums[index] > maxValue) {
        maxValue = nums[index];
        maxValueIndex = index;
      }
    if (maxValue != -1) {
      insert(T, maxValue);
      T->left = constructMaximumBinaryTree(nums, begin, maxValueIndex);
      T->right = constructMaximumBinaryTree(nums, maxValueIndex + 1, numsSize);
    }
  }
  return T;
}

typedef struct{
  TreeNode* member[MAX_QUEUE_NUM];
  int count;
  int front;
  int tail;
} Queue;

void init(Queue* q){
  q->count = q->front = q->tail = 0;
}

void enqueue(Queue* q,TreeNode* t){
  if(q->count<MAX_QUEUE_NUM){
    q->tail = (q->tail + 1) % MAX_QUEUE_NUM;
    q->member[q->tail] = t;
    q->count++;
  }
}

void deque(Queue* q){
  if(q->count>=0){
    q->front = (q->front - 1) % MAX_QUEUE_NUM;
    q->count--;
  }
}
/*Using BFS algorithm*/
void printTree(TreeNode* T){
  Queue *q = malloc(sizeof(Queue));
  init(q);
  if(T){
    printf("%d\n", T->val);
    enqueue(q, T);
  }
  while(q->count>0){
    TreeNode *temp;
    if((temp=q->member[q->front]->left)){
      printf("%d ", temp->val);
      enqueue(q, temp);
    }
    if((temp=q->member[q->front]->right)){
      printf("%d ", temp->val);
      enqueue(q, temp);
    }
    deque(q);
  }
}

int main() {
  int numSize;
  scanf("%d", &numSize);
  int *nums = malloc(sizeof(int) * numSize);
  unsigned int index;
  for (index = 0; index < numSize; index++)
    scanf("%d", &nums[index]);
  TreeNode *res = NULL;
  res= constructMaximumBinaryTree(nums, 0,numSize);
  printTree(res);
  return 0;
}