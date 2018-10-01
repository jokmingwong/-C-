#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_LINE_AMOUNT 30
#define MAX_NAME_SIZE 20
typedef struct StopNode {
  char stop_name[MAX_NAME_SIZE];
  struct StopNode *next;
  int isTransfer;
} StopNode;

typedef struct LineNode {
  unsigned int LineNumber;
  unsigned int StopAmount;
  StopNode *firstStop;
} LineNode;

typedef struct SubwayGraph {
  unsigned int LineAmount;
  LineNode line[MAX_LINE_AMOUNT];
} SubwayGraph;

SubwayGraph* insert(SubwayGraph*G, const int lineNumber,const char* name,const int isChange){
    StopNode *S = (StopNode *)malloc(sizeof(StopNode));
    strcpy(S->stop_name, name);
    S->isTransfer = isChange;
    S->next = NULL;
    StopNode *temp = G->line[lineNumber].firstStop;
    if(temp==NULL){
        G->line[lineNumber].firstStop = S;
    }else{
        while(temp->next)
            temp = temp->next;
        temp->next = S;
    }
    return G;
}

SubwayGraph* read_file_and_build_graph(SubwayGraph* G){
    FILE *in = fopen("bgstations.txt", "r");
    fscanf(in, "%u", &G->LineAmount);
    unsigned int index;
    for (index = 0; index < G->LineAmount;index++){
        unsigned int lineNumber,stopAmount;
        fscanf(in, "%u %u", &lineNumber,&stopAmount);
        while(stopAmount--){
            char name[MAX_NAME_SIZE];
            int isChange;
            fscanf(in,"%s%d", name, &isChange);
            G = insert(G,lineNumber, name, isChange);
        }
    }
    fclose(in);
    return G;
}

inline void print_shortest_path(const char* fromWhere,const char* toWhere){
    //PASS
}

int main() {
    SubwayGraph* G = malloc(sizeof(SubwayGraph));
    G=read_file_and_build_graph(G);
    char fromWhere[MAX_NAME_SIZE], toWhere[MAX_NAME_SIZE];
    scanf("%s%s", fromWhere, toWhere);
    print_shortest_path(fromWhere, toWhere);
    free(G);
    return 0;
}
