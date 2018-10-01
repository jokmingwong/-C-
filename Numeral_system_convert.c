#include <stdio.h>
#include "stack.h"

void TransTo(int target_num, const int target_system) {
  Stack *s = CreateStack(10);
  do{
    push(s, target_num % target_system);
    target_num /= target_system;
  } while (target_num != 0);
  while(!empty(s)){
    printf("%d", s->item[s->top]);
    pop(s);
  }
}


int main(){
  int num_sys,number;
  printf("Input the numeral system you want to convert(For example:2,8,16):\n");
  scanf("%d", &num_sys);
  printf("Please input your number you want to convert:\n");
  scanf("%d", &number);
  printf("The result is\n");
  TransTo(number, num_sys);
  return 0;
}