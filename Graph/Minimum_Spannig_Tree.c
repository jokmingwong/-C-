#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100
#define INFINITY 10000
typedef struct ArcNode {
  struct ArcNode *next;
  unsigned int arcId;
  unsigned int weight;
  int target_vertex;
} ArcNode;

int result[MAX_VERTEX_NUM];
unsigned int index_of_result = 0;

typedef struct VNode {
  ArcNode *arcnode;
} VNode;

typedef struct {
  unsigned int arcNum, vertexNum;
  VNode AdjList[MAX_VERTEX_NUM];
} Graph;

Graph *insert(Graph *G, const int fromVertex, const int toVertex,
              const int arcId, const int weight) {
  ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode)), *q, *r;
  t->target_vertex = toVertex;
  t->arcId = arcId;
  t->weight = weight;
  /*Use head insert*/
  ArcNode *temp = G->AdjList[fromVertex].arcnode;
  if (temp == NULL || (temp != NULL && toVertex < temp->target_vertex)) {
    t->next = temp;
    G->AdjList[fromVertex].arcnode = t; //指向被插入的新结点
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

int findWeight(const Graph *G, int fromVertex, int toVertex) {
  ArcNode *temp = G->AdjList[fromVertex].arcnode;
  while (temp) {
    if (temp->target_vertex == toVertex) {
      return temp->weight;
    }
    temp = temp->next;
  }
  return INFINITY;
}

void find_min_arcId_and_weight(const Graph *G, int fromVertexID, int vertexID,
                               int *arcID, int *weight) {
  ArcNode *temp = G->AdjList[fromVertexID].arcnode;
  while (temp) {
    if (temp->target_vertex == vertexID) {
      *arcID = temp->arcId;
      *weight = temp->weight;
    }
    temp = temp->next;
  }
}

void MinSpanTreePrim(const Graph *G, unsigned int *sum) {
  int lowcost[G->vertexNum], teend[MAX_VERTEX_NUM], i, j, k, mincost;
  lowcost[0] = 0;
  teend[0] = 0;
  /*Initialize the secondary array*/
  for (j = 0; j < G->vertexNum; j++) {
    teend[j] = 0;
    /*If find the weight return it,if not find return infinity*/
    lowcost[j] = findWeight(G, 0, j);
  }
  for (i = 1; i < G->vertexNum; i++) {
    mincost = INFINITY;
    j = 1;
    while (j < G->vertexNum) {
      /*If the vertex j is in the MST,the lowcost[j] is zero*/
      if (lowcost[j] > 0 && mincost > lowcost[j]) {
        mincost = lowcost[j];
        k = j;
      }
      j++;
    }
    int arcID = -1, weight = 0;
    find_min_arcId_and_weight(G, teend[k], k, &arcID, &weight);
    *sum += weight;
    result[index_of_result++] = arcID;
    lowcost[k] = 0;
    ArcNode *temp = G->AdjList[k].arcnode;
    while (temp) {
      if (temp->weight < lowcost[(j = temp->target_vertex)]) {
        lowcost[j] = temp->weight;
        teend[j] = k;
      }
      temp = temp->next;
    }
  }
}

void select_sort(int T[], const int n) {
  int i, j;
  for (i = 0; i < n - 1; i++) {
    int min = i;
    for (j = i + 1; j < n; j++) {
      if (T[j] < T[min]) {
        min = j;
      }
    }
    // swap(T, i, min);
    int temp = T[min];
    T[min] = T[i];
    T[i] = temp;
  }
}

void showArray(int *T, const int n) {
  int index;
  for (index = 0; index < n; index++) {
    printf("%d ", T[index]);
  }
  printf("\n");
}

int main() {
  Graph *G = malloc(sizeof(Graph));
  scanf("%u %u", &G->vertexNum, &G->arcNum);
  unsigned int index;
  for (index = 0; index < G->vertexNum; index++)
    G->AdjList[index].arcnode = NULL;
  /*Initialization*/
  for (index = 0; index < G->arcNum; index++) {
    int ArcID, fromID, toID, weight;
    scanf("%d%d%d%d", &ArcID, &fromID, &toID, &weight);
    G = insert(G, fromID, toID, ArcID, weight);
    G = insert(G, toID, fromID, ArcID, weight);
  }
  unsigned int sum = 0;
  MinSpanTreePrim(G, &sum);
  printf("%d\n", sum);
  /*Put the result into an array and sort it*/
  select_sort(result, index_of_result);
  showArray(result, index_of_result);
  return 0;
}