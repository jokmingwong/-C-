#include <stdio.h>
#include <stdlib.h>
/**************************
 * 二维动态数组示例:
 * 其中第一个内存空间存储 那行数组得长度
 * 基本操作就是malloc()函数
 * ***********************/
int main() {
  int **Matrix;
  int num;
  scanf("%d", &num);
  (Matrix) = malloc(sizeof(int*) * num);
  unsigned int index;
  for (index = 0; index < num; index++) {
    int num_of_each_array;
    scanf("%d", &num_of_each_array);
    Matrix[index] = malloc(sizeof(int) * (num_of_each_array + 1));
    /*第一个数存储数量*/
    Matrix[index][0] = num_of_each_array;
    unsigned int j = 0;
    for (j = 1; j < num_of_each_array+1; j++) {
      scanf("%d", &Matrix[index][j]);
    }
  }
  // Show the 2-d matrix
  printf("This is the result:\n");
  unsigned int i;
  for (i = 0; i < num; i++) {
    unsigned int j;
    for (j = 1; j < Matrix[i][0] + 1; j++) {
      printf("%d ", Matrix[i][j]);
    }
    printf("\n");
  }
  return 0;
}