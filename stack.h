#include<stdlib.h>
#ifndef _STACK_H_
#define _STACK_H_
typedef struct {
  int *item;
  int top;
} Stack;

/*
 * Create a stack that contains x items
 * For example: if x is 5,the function will return 
 * a stack pointer with 5 maximum items
*/
Stack *CreateStack(const int x) {
  Stack *res = (Stack*)malloc(sizeof(Stack));
  res->item = (int*)malloc(sizeof(int) * x);
  res->top = -1;
  return res;
}

/*Judge the stack is empty,if true return 1,else return 0*/
int empty(const Stack *s) { return s->top == -1; }

void pop(Stack *s) {
  if (!empty(s))
    s->top--;
}
void push(Stack* s,const int x){s->item[++s->top]=x;}

void DisposeStack(Stack* s){
  free(s->item);
  free(s);
}

#endif // !_STACK_H_
