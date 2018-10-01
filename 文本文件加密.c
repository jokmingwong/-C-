#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct node {
  char key;
  struct node *next;
  struct node *pre;
} char_node;

// build a circle list
char_node *build_list(char *line) {
  int i = 1;
  int size = strlen(line);
  char_node *list = (char_node *)malloc(sizeof(char_node));
  list->pre = list->next = list;
  list->key = line[0];
  while (i++ < size) // insert nodes
  {
    char_node *next_node = (char_node *)malloc(sizeof(char_node));
    next_node->key = line[i - 1];
    next_node->next = list;
    list->pre->next = next_node;
    next_node->pre = list->pre;
    list->pre = next_node;
  }
  return list;
}

//删除多余字符串以及补进未出现的字符直到全部出现
void delete_multiple(char *S) {
  int judge[95] = {0};
  int i = 0, j = 0;
  while (i < strlen(S)) {
    if (judge[S[i] - 32] == 0) {
      judge[S[i] - 32] = 1;
      S[j] = S[i];
      i++;
      j++;
    } else {
      i++;
    }
  }
  int q = 0;
  for (; q < 95; q++) {
    if (judge[q] == 0) {
      S[j] = q + 32;
      j++;
    }
  }
  S[95] = '\0';
}

char_node *delete_head_and_set_key(char_node *list, char *keys) {
  char head_value = list->key;

  // delete
  char_node *temp = list;
  list->pre->next = list->next;
  list->next->pre = list->pre;
  list = list->next;
  temp->pre = temp->next = NULL;
  free(temp);
  // now list is next of deleted element
  int i = 1;
  for (; i < head_value; ++i)
    list = list->next;
  keys[head_value - 32] = list->key;
  return list;
}

int main() {
  char test[100];
  gets(test);
  delete_multiple(test);
  char keys[95] = "";
  char_node *list = build_list(test);

  int j = 0;
  for (; j < strlen(test) - 1; ++j) {
    list = delete_head_and_set_key(list, keys);
  }
  //解决问题
  keys[list->key - 32] = test[0];

  FILE *in = fopen("in.txt", "r");
  FILE *out = fopen("in_crpyt.txt", "w");

  char buffer[1026];
  while (fgets(buffer, 1026, in) != NULL) {
    int q = 0;
    for (; q < strlen(buffer); q++) {
      if (buffer[q] >= 32 && buffer[q] <= 126)
        fputc(keys[(int)buffer[q] - 32], out);
      else {
        fputc(buffer[q], out);
      }
    }
  }
  fclose(in);
  fclose(out);
  return 0;
}