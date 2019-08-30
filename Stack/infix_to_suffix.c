#include <ctype.h>
#include <stdio.h>
#define MAX_STACK_NUM 100
#include"stack.h"

/*'('符号很特殊，pop的时候优先级最大，push的时候优先级最小*/
int compare(const char a,const char b){
    if(a==b)
        return 0;
    else{
        if((a=='*'||a=='/')&&(b=='+'||b=='-'))
            return 1;
        else
            return -1;
    }
}

int main() {
  Stack *oper = CreateStack(MAX_STACK_NUM);
  char operation[100];
  gets(operation);
  unsigned int index;
  char c;
  for (index = 0; (c = operation[index]) != '\0'; index++) {
    if (isdigit(c)||isalpha(c))
      putchar(c);
    else if(c=='+'||c=='-'||c=='/'||c=='*'){
        if(empty(oper)||compare(c,oper->item[oper->top])>0||oper->item[oper->top]=='('){
            push(oper, c);
        }else if(oper->item[oper->top]!='('&&compare(c,oper->item[oper->top])<=0){
            while(!empty(oper)&&oper->item[oper->top]!='('&&compare(c,oper->item[oper->top])<=0){
                putchar(oper->item[oper->top]);
                pop(oper);
            }
            push(oper, c);
        }
    }else if(c=='(')push(oper, c);
    else if(c==')'){
        while(oper->item[oper->top]!='('){
            putchar(oper->item[oper->top]);
            pop(oper);
        }
        /*Ignore the '(' symbol*/
        pop(oper);
    }
  }
  while(!empty(oper)){
      putchar(oper->item[oper->top]);
      pop(oper);
  }
  putchar('\n');
  return 0;
}