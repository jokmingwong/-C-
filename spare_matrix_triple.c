/*This is the spare matrix using triple
to combine*/
#include <stdio.h>
#include <stdlib.h>
#define MAXSIZE 100 /*The maxive amount of non-zero number is MAXSIZE*/
typedef struct {
  int i, j; /*Mark the position*/
  int val;
} Triple;
typedef struct {
  Triple *data;
  unsigned int mu, nu, tu; /*Colunm,row,the number of non-zero*/
} TSMatrix;

TSMatrix *convertToTriple(int **A, const unsigned int row,
                          const unsigned int col) {
  unsigned int i;
  unsigned int mark = 0;
  TSMatrix *result = malloc(sizeof(TSMatrix));
  result->mu = row;
  result->nu = col;
  result->data = malloc(sizeof(Triple) * MAXSIZE);
  result->tu = 0;
  for (i = 0; i < row; i++) {
    unsigned int j;
    for (j = 0; j < MAXSIZE; j++) {
      if (A[i][j] != 0) {
        result->tu++;
        result->data[mark].i = i;
        result->data[mark].j = j;
        result->data[mark].val = A[i][j];
        mark++;
      }
    }
  }
  return result;
}
int main() {
  unsigned int t1, t2;
  scanf("%u%u", &t1, &t2);
  int **Matrix;
  Matrix = malloc(sizeof(int(*)));
  unsigned int i, j;
  for (i = 0; i < t1; i++) {
    for (j = 0; j < t2; j++) {
      scanf("%d", &Matrix[i][j]);
    }
  }
  TSMatrix *res = convertToTriple(Matrix, t1, t2);
  for (i = 0; i < res->tu; i++) {
    printf("%d ", res->data[i].val);
  }
  printf("\n");
  return 0;
}