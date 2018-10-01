#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100
typedef struct ArcNode {
  struct ArcNode *next;
  unsigned int ArcId;
  int target_vertex;
} ArcNode;

typedef struct VNode {
  ArcNode *arcnode;
} VNode;

typedef struct {
  unsigned int arcNum, vertexNum;
  VNode AdjList[MAX_VERTEX_NUM];
} Graph;

Graph *insert(Graph *G, const int fromVertex, const int toVertex,
              const int arcId) {
  ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode)), *q, *r;
  t->target_vertex = toVertex;
  t->ArcId = arcId;
  /*Use head insert*/
  ArcNode *temp = G->AdjList[fromVertex].arcnode;
  if (temp == NULL || (temp != NULL && arcId < temp->ArcId)) {
    t->next = temp;
    G->AdjList[fromVertex].arcnode = t; //指向被插入的新结点
  } else {
    q = temp->next;
    r = temp;
    while (r != NULL && q != NULL && arcId > q->ArcId) {
      r = r->next;
      q = q->next;
    }
    t->next = q;
    r->next = t;
  }
  return G;
}

void printPath(int *T, const int n) {
  unsigned int index;
  for (index = 0; index < n; index++) {
    printf("%d ", T[index]);
  }
  printf("\n");
}

typedef struct {
  int top;
  int item[MAX_VERTEX_NUM];
} Stack;

int isEmpty(const Stack *s) { return s->top < 0; }
void pop(Stack *s) {
  if (!isEmpty(s)) {
    s->top--;
  }
}

void push(Stack *s, const int item) {
  if (s->top < MAX_VERTEX_NUM)
    s->item[++s->top] = item;
}

/*利用栈数据结构，记住:出栈后才设置边未访问*/
void find_all_path(const Graph *G) {
  Stack *NodeStack = (Stack *)malloc(sizeof(Stack));
  NodeStack->top = -1;
  int Path[MAX_VERTEX_NUM];
  int Arcvisited[MAX_VERTEX_NUM] = {0};
  unsigned int index_of_path = 0;
  push(NodeStack, 0);
  while (!isEmpty(NodeStack)) {
    ArcNode *temp = G->AdjList[NodeStack->item[NodeStack->top]].arcnode;
    while (temp) {
      if (Arcvisited[temp->ArcId] == 0) {
        Arcvisited[temp->ArcId] = 1;
        push(NodeStack, temp->target_vertex);
        Path[index_of_path++] = temp->ArcId;
        break;
      }
      temp = temp->next;
    }
    if (NodeStack->item[NodeStack->top] == G->vertexNum - 1) {
      printPath(Path, index_of_path);
      index_of_path--;
      pop(NodeStack);
    } else if (temp == NULL) {
      index_of_path--;
      ArcNode *temp2 = G->AdjList[NodeStack->item[NodeStack->top]].arcnode;
      /*退栈同时还原visited*/
      pop(NodeStack);
      while (temp2) {
        if (temp2->target_vertex != NodeStack->item[NodeStack->top])
          Arcvisited[temp2->ArcId] = 0;
        temp2 = temp2->next;
      }
    }
  }
}

int main() {
  Graph *G = malloc(sizeof(Graph));
  scanf("%u %u", &G->vertexNum, &G->arcNum);
  unsigned int index;
  for (index = 0; index < G->vertexNum; index++)
    G->AdjList[index].arcnode = NULL;
  for (index = 0; index < G->arcNum; index++) {
    int ArcID, fromID, toID;
    scanf("%d%d%d", &ArcID, &fromID, &toID);
    G = insert(G, fromID, toID, ArcID);
  }
  find_all_path(G);
  return 0;
}
