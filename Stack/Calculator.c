/*基于infix_to_suffix.c修改的Calculator.c*/
#include <ctype.h>
#include <stdio.h>
#define MAX_STACK_NUM 100
#include "stack.h"

/*'('符号很特殊，pop的时候优先级最大，push的时候优先级最小*/
int compare(const char a, const char b) {
  if (a == b)
    return 0;
  else {
    if ((a == '*' || a == '/') && (b == '+' || b == '-'))
      return 1;
    else
      return -1;
  }
}

void Solve(const char c, Stack *num) {
  int a = num->item[num->top];
  pop(num);
  int b = num->item[num->top];
  pop(num);
  switch (c) {
  case '+':
    push(num, a + b);
    break;
  case '*':
    push(num, a * b);
    break;
  case '/':
    push(num, b / a);
    break;
  case '-':
    push(num, b - a);
    break;
  default:
    break;
  }
}

int main() {
  Stack *oper = CreateStack(MAX_STACK_NUM);
  Stack *num = CreateStack(MAX_STACK_NUM);
  char operation[100];
  gets(operation);
  unsigned int index;
  char c;
  for (index = 0; (c = operation[index]) != '\0'; index++) {
    if (isdigit(c)) {
      char temp[10];
      unsigned int temp_index = 0;
      while (isdigit(operation[index])) {
        temp[temp_index++] = operation[index++];
      }
      temp[temp_index] = '\0';
      index -= 1;
      push(num, atoi(temp));
    } else if (c == '+' || c == '-' || c == '/' || c == '*') {
      if (empty(oper) || compare(c, oper->item[oper->top]) > 0 ||
          oper->item[oper->top] == '(') {
        push(oper, c);
      } else if (oper->item[oper->top] != '(' &&
                 compare(c, oper->item[oper->top]) <= 0) {
        while (!empty(oper) && oper->item[oper->top] != '(' &&
               compare(c, oper->item[oper->top]) <= 0) {
          Solve(oper->item[oper->top], num);
          pop(oper);
        }
        push(oper, c);
      }
    } else if (c == '(')
      push(oper, c);
    else if (c == ')') {
      while (oper->item[oper->top] != '(') {
        Solve(oper->item[oper->top],num);
        pop(oper);
      }
      /*Ignore the '(' symbol*/
      pop(oper);
    }
  }
  while (!empty(oper)) {
    Solve(oper->item[oper->top],num);
    pop(oper);
  }
  printf("%d\n", num->item[num->top]);
  DisposeStack(oper);
  DisposeStack(num);
  return 0;
}