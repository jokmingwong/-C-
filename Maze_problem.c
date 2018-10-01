#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_STACK_SIZE 100

typedef struct {
  unsigned int x;
  unsigned int y;
  int isVisted;
} Point;

typedef struct {
  int top;
  Point item[MAX_STACK_SIZE];
} Stack;

void push(Stack* s,Point item){
    s->item[++s->top] = item;
}

int isEmpty(Stack* s){
    return s->top <= -1;
}
void pop(Stack* s){
    if(!isEmpty(s))
        s->top--;
}

void print_path(int **Maze, const unsigned int col, const unsigned int row,
                Point start, Point end) {
    Stack *path = malloc(sizeof(Stack));
    start.isVisted = 1;
    push(path, start);
    /*First of all,push the start point into the stack*/

    free(path);
}

int main() {
  printf("Please input the amount of row and column:\n");
  unsigned int row, column;
  scanf("%u%u", &row, &column);
  printf("And now input your maze matrix:\n");
  int **Maze = malloc(sizeof(int *) * row);
  unsigned int index;
  for (index = 0; index < row; index++) {
    Maze[index] = malloc(sizeof(int) * column);
  }
  for (index = 0; index < row; index++) {
    unsigned int index2;
    for (index2 = 0; index2 < column; index2++)
      scanf("%d", &Maze[index][index2]);
  }
  Point *start = malloc(sizeof(Point));
  scanf("%u%u", &start->x, &start->y);
  Point *end = malloc(sizeof(Point));
  scanf("%u%u", &end->x, &end->y);
  print_path(Maze, row, column, *start, *end);
  return 0;
}