#include <stdio.h>
int count[26] = {0};
int max(int temp[], int size)
{
  int q = temp[0];
  int i;
  for (i = 2; i < size; i++)
    if (temp[i] > q)
      q = temp[i];
  return q;
}
int main()
{
  char a[200];
  while (scanf("%s", a) != EOF)
  {
    int i = 0;
    while (a[i] != '\0')
    {
      if ('a' <= a[i] && a[i] <= 'z')
      {
        count[a[i] - 'a']++;
      }
      i++;
    }
  }
  // printout
  int t, b;
  for (b = max(count, 26); b >= 0; b--)
  {
    for (t = 0; t < 26; t++)
    {
      if (count[t] > b)
      {
        printf("*");
      }
      else
      {
        printf(" ");
      }
    }
    printf("\n");
  }
  printf("abcdefghijklmnopqrstuvwxyz\n");
  return 0;
}
