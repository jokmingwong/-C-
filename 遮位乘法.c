#include <stdio.h>
/*aX*Xb=XcdX*/
int main() {
  int times;
  scanf("%d", &times);
  while (times-- > 0) {
    int a, b, c, d;
    int flag = 0; /*标记是否存在，默认不存在*/
    scanf("%d%d%d%d", &a, &b, &c, &d);
    /*四重循环来了*/
    int i, j, k, m;
    for (i = 0; i <= 9; i++)
      for (j = 0; j <= 9; j++)
        for (k = 0; k <= 9; k++)
          for (m = 0; m <= 9; m++) {
            if (i + a * 10 + j * 10 + b == 1000 * k + 100 * c + 10 * d + m) {
              printf("%d%d*%d%d=%d%d%d%d\n", a, i, b, j, k, c, d, m);
              flag = 1;
            }
          }
    /*如果没有找到*/
    if (flag == 0) {
      printf("IMPOSSIBLE\n");
    }
  }
  return 0;
}