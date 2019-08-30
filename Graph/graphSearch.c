#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 30
#define QUEUE_MAX_SIZE 30
typedef struct ArcNode {
  struct ArcNode *next;
  int target_vertex;
} ArcNode;

typedef struct VNode {
  ArcNode *arcNode;
  int isExsit;
} VNode;

typedef struct {
  unsigned int arcNode, vertexNum;
  VNode AdjList[MAX_VERTEX_NUM];
} Graph;

/*需要顺序插入*/
Graph *insert(Graph *G, int fromVertex, int toVertex) {
  ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode)), *q, *r;
  t->target_vertex = toVertex;
  /*Use head insert*/
  ArcNode *temp = G->AdjList[fromVertex].arcNode;
  G->AdjList[fromVertex].isExsit = 1;
  if (temp == NULL || (temp != NULL && toVertex < temp->target_vertex)) {
    t->next = temp;
    G->AdjList[fromVertex].arcNode = t; //指向被插入的新结点
  } else {
    q = temp->next;
    r = temp;
    while (r != NULL && q != NULL && toVertex > q->target_vertex) {
      r = r->next;
      q = q->next;
    }
    t->next = q;
    r->next = t;
  }
  return G;
}

/*Define a temporary*/
typedef struct {
  int member[QUEUE_MAX_SIZE];
  int front;
  int rear;
  int count;
} Queue;

void init(Queue *q) { q->front = q->rear = q->count = 0; }

int isFull(Queue *q) { return q->count == QUEUE_MAX_SIZE; }

int isEmpty(Queue *q) { return q->count <= 0; }

void enqueue(Queue *q, int item) {
  if (isFull(q))
    return;
  q->count++;
  q->member[q->rear] = item;
  q->rear = (q->rear + 1) % QUEUE_MAX_SIZE;
}

void deque(Queue *q) {
  if (isEmpty(q))
    return;
  q->count--;
  q->front = (q->front + 1) % QUEUE_MAX_SIZE;
}
/*The definition of queue end*/

int visited[MAX_VERTEX_NUM];
void BFSTraverse(const Graph *G) {
  /*Initialize the array */
  unsigned int index;
  for (index = 0; index < G->vertexNum; index++) {
      visited[index] = 0;
  }
  Queue *q = (Queue *)malloc(sizeof(Queue));
  init(q);
  for (index = 0; index < G->vertexNum; index++) {
    if (!visited[index]&&G->AdjList[index].isExsit==1) {
      visited[index] = 1;
      printf("%d ", index);
      enqueue(q, index);
      while (!isEmpty(q)) {
        int u = q->member[q->front];
        deque(q);
        ArcNode *temp = G->AdjList[u].arcNode;
        for (; temp != NULL; temp = temp->next) {
          int index2 = temp->target_vertex;
          if (!visited[index2]&&G->AdjList[index2].isExsit==1) {
            visited[index2] = 1;
            printf("%d ", index2);
            enqueue(q, index2);
          }
        } // for
      }   // while
    }     // if
  }       // for
}

/*Define a DFS algorithm*/
void DFS(const Graph *G, const int fromID) {
  visited[fromID] = 1;
  printf("%d ", fromID);
  ArcNode *temp = G->AdjList[fromID].arcNode;
  while (temp != NULL) {
    int j = temp->target_vertex;
    if (!visited[j]&&G->AdjList[j].isExsit==1)
      DFS(G, j);
    temp = temp->next;
  }
}

void DFSTraverse(Graph *G) {
  unsigned int i;
  for (i = 0; i < G->vertexNum; i++) {
      visited[i] = 0;
  }
  for (i = 0; i < G->vertexNum; i++)
    if (!visited[i]&&G->AdjList[i].isExsit==1)
      DFS(G, i);
}

Graph *deleteVertex(const int target, Graph *G) {
  unsigned int i;
  ArcNode *list;
  G->AdjList[target].isExsit = 0;
  for (i = 0; i < G->vertexNum; i++) {
    if ((list = G->AdjList[i].arcNode) != NULL) {
      ArcNode *p = list->next;
      ArcNode *q = list;
      while (p != NULL) {
        /*Find one and can exit*/
        if (p->target_vertex == target) {
          q->next = p->next;
          free(p);
          break;
        } else {
          q = p;
          p = p->next;
        }
      }
      if (list->target_vertex == target) {
        q = list;
        G->AdjList[i].arcNode = list->next;
        free(q);
      }
    }
  }
  return G;
}

int main() {
  unsigned int index;
  Graph *G = (Graph *)malloc(sizeof(Graph));
  scanf("%d %d", &G->vertexNum, &G->arcNode);
  /*Intialization*/
  for (index = 0; index < G->vertexNum; index++)
    G->AdjList[index].arcNode = NULL;
  int fromID, toID;
  for (index = 0; index < G->arcNode; index++) {
    /*minus one when scanf a number while plus one when print it*/
    scanf("%d %d", &fromID, &toID);
    G = insert(G, fromID, toID);
    G = insert(G, toID, fromID);
  }
  int deleteNum;
  scanf("%d", &deleteNum);
  /*end of initialization*/
  DFSTraverse(G);
  putchar('\n');
  BFSTraverse(G);
  putchar('\n');
  deleteVertex(deleteNum, G);
  DFSTraverse(G);
  putchar('\n');
  BFSTraverse(G);
  putchar('\n');
  return 0;
}