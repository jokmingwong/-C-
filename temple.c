#include <stdio.h>
int main() {
  int M, N, i, j, got = 0, count = 0;
  /*我新定义了一个变量用于记录最早进入背包的物品下标*/
  int index_of_first_in=0;
  /*int a[1000];*/
  scanf("%d %d", &M, &N);
  /*这段代码最终只用了M+1个位置*/
  int a[M+1];
  for (i = 0; i < M; i++)
  {
      scanf("%d", &a[i]);
      for (j = 0; j < i; j++)
      {
          if (a[j] == a[i])
              i--;
      }
  }
  for (/*i = M*/; count < (N - M); /*i++*/) {
    scanf("%d", &a[M]);
    /*先看书包内有没有*/
    for (j = 0; j < /*i*/M; j++) {
      if (a[j] == a[M])
      /*找到*/
        break;
    /*
      else {
        a[got] = a[i];
        got++;
        break;
      }
      */
    }
    /*M==j说明在背包里面没找到*/
    if(j==M){
        /*用a[M]替代最早放入书包的*/
        a[index_of_first_in] = a[M];
        /*保证下标不越界*/
        index_of_first_in = (index_of_first_in + 1) % M;
        /*got加一个*/
        got++;
    }
    count++;
    /*i--;*/
  }
  printf("%d",got+i/*原来是got+M,但是这样错了因为M一直不变，不符合你想要的初始动态变化的想法*/);
  return 0;
}