#include <stdio.h>
#include <stdlib.h>
#define MAX_VERTEX_NUM 100
#define INFINITY 10000
#define NO_VERTEX -1
typedef struct ArcNode {
  struct ArcNode *next;
  unsigned int weight;
  int target_vertex;
} ArcNode;

typedef struct VNode {
  ArcNode *arcnode;
} VNode;

typedef struct {
  unsigned int arcNum, vertexNum;
  VNode AdjList[MAX_VERTEX_NUM];
} Graph;

typedef struct {
  int known;
  unsigned int dist;
  unsigned int Path;
} Table;

Graph *insert(Graph *G, const int fromVertex, const int toVertex,
              const int weight) {
  ArcNode *t = (ArcNode *)malloc(sizeof(ArcNode)), *q, *r;
  t->target_vertex = toVertex;
  t->next = NULL;
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

int find_smallest_unknown_distance_vertex(const Table *T,
                                          const unsigned int length) {
  unsigned int min = INFINITY;
  unsigned int index = 0;
  int res = NO_VERTEX;
  while (index < length) {
    if (T[index].known == 0 && min > T[index].dist) {
      min = T->dist;
      res = index;
    }
    index++;
  }
  return res;
}
void Djikstra(Table *T, const Graph *G) {
  unsigned int fromID;
  for (;;) {
    fromID = find_smallest_unknown_distance_vertex(T, G->vertexNum);
    if (fromID == NO_VERTEX)
      break;
    /*Have already been a start node*/
    T[fromID].known = 1;
    ArcNode *temp = G->AdjList[fromID].arcnode;
    while (temp) {
      unsigned int w;
      if (!T[w = temp->target_vertex].known) {
        if (T[fromID].dist + temp->weight < T[w].dist) {
          T[w].dist = T[fromID].dist + temp->weight;
          T[w].Path = fromID;
        }
      }
      temp = temp->next;
    }
  }
}

void printPath(const Table *T, const unsigned int targetID) {
  if (T[targetID].Path != NO_VERTEX) {
    printPath(T, T[targetID].Path);
    putchar(' ');
  }
  printf("%u", targetID);
}

int main() {
  /********Initialize the graph**********/
  Graph *G = malloc(sizeof(Graph));
  scanf("%u%u", &G->vertexNum, &G->arcNum);
  unsigned int index;
  for (index = 0; index < G->arcNum; index++) {
    G->AdjList[index].arcnode = NULL;
  }
  for (index = 0; index < G->arcNum; index++) {
    unsigned int fromID, toID, weight;
    scanf("%u%u%u", &fromID, &toID, &weight);
    G = insert(G, fromID, toID, weight);
  }
  printf("Input the start vertex ID and the end vertex ID:(from zero!)\n");
  unsigned int start_vertex_Id, end_vertex_Id;
  scanf("%d%d", &start_vertex_Id, &end_vertex_Id);
  /********Initialize the table**********/
  Table *T = malloc(sizeof(Table) * G->vertexNum);
  for (index = 0; index < G->vertexNum; index++) {
    T[index].dist = INFINITY;
    T[index].known = 0;
    T[index].Path = NO_VERTEX;
  }
  T[start_vertex_Id].dist = 0;
  /*********Using Dijkstra and print path***/
  Djikstra(T, G);
  printPath(T, end_vertex_Id);
  return 0;
}