#include<stdio.h>
#include<string.h>
int main(){
  printf("This is the test of memmove()\n");
  char s1[] = "hello world";
  const char s2[] = "nihao";
  /*If cross the length of the s2 if will copy all the s2 to s1*/
  memmove(s1, s2, 3);
  printf("%s\n%s\n", s1, s2);
  return 0;
}