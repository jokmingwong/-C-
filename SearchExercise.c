#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int isFound = 0;
unsigned int times = 0;
/*这道题不用返回具体位置，只需要知道是否找到即可*/
void sequential_search(char *target, char dictionary[][21], int n) {
  unsigned int index = 0;
  while (index < n) {
    times++;
    if (strcmp(dictionary[index], target) > 0) {
      break;
    } else if (strcmp(dictionary[index], target) == 0) {
      isFound = 1;
      break;
    }
    index++;
  }
}

void binary_search(char *target, char dictionary[][21], int begin, int end) {
  if (begin <= end) {
    int mid = (begin + end) / 2;
    times++;
    if (strcmp(target, dictionary[mid]) == 0) {
      isFound = 1;
    } else if (strcmp(target, dictionary[mid]) < 0) {
      binary_search(target, dictionary, begin, mid - 1);
    } else {
      binary_search(target, dictionary, mid + 1, end);
    }
  }
}

void index_list_find(char *target, char dictionary[][21], int n) {
  char IndexList[26][500][21];
  int num_of_each_char[26] = {0};
  int index = 0;
  while (index < n) {
    /*Copy the string to index list*/
    int index_of_current_char = dictionary[index][0] - 'a';
    strcpy(IndexList[index_of_current_char]
                    [num_of_each_char[index_of_current_char]++],
           dictionary[index]);
    index++;
  }
  int target_index = target[0] - 'a';
  binary_search(target, IndexList[target_index], 0,
                num_of_each_char[target_index] - 1);
}

typedef struct node {
  struct node *next;
  char value[21];
} Node;

unsigned int hash(char *str, const int NHASH) {
  const int MULT = 31;
  unsigned int h = 0;
  char *p;
  for (p = str; *p != '\0'; p++)
    h = MULT * h + *p;
  return h % NHASH;
}

void buildHashAndFound(char *target, char dictionary[][21], int n) {
  const int NHASH = 3001;
  /*Build an array of dummy node*/
  Node *hashNode[NHASH];
  /*Initialize the hashNode*/
  int index = 0;
  while (index < NHASH) {
      hashNode[index] = malloc(sizeof(hashNode));
      hashNode[index]->next = NULL;
      index++;
  }
  for (index = 0; index < n;index++){
      int hashCode = hash(dictionary[index], NHASH);
      Node* temp_pointer=hashNode[hashCode];
      while(temp_pointer->next!=NULL){
          temp_pointer = temp_pointer->next;
      }
      /*Create a node*/
      temp_pointer->next = malloc(sizeof(hashNode));
      /*Move the pointer*/
      temp_pointer = temp_pointer->next;
      /*Initialise the new code*/
      temp_pointer->next = NULL; 
      strcpy(temp_pointer->value, dictionary[index]);
  }
  /*begin to find*/
  unsigned int target_index = hash(target, NHASH);
  Node *temp_pointer = hashNode[target_index]->next;
  while(temp_pointer!=NULL){
      times++;
      if(strcmp(temp_pointer->value,target)==0){
          isFound = 1;
          break;
      }
      else if(strcmp(temp_pointer->value,target)>0)
          break;
      temp_pointer =temp_pointer->next;
  }
  if(temp_pointer==NULL)
      times++;
}



int main() {
  char word[21];
  int method_num;
  scanf("%s%d", word, &method_num);
  FILE *in = fopen("dictionary3000.txt", "r");
  char buffer[3500][21];
  int index = 0;
  /*Read the all word in an array*/
  char temp[21];
  while (fscanf(in, "%s", temp) != EOF) {
    strcpy(buffer[index], temp);
    index++;
  }
  switch (method_num) {
  case 1:
    /*顺序查找*/
    sequential_search(word, buffer, index);
    break;
  case 2:
    binary_search(word, buffer, 0, index - 1);
    /*排好序，直接折半查找*/
    break;
  case 3:
    index_list_find(word, buffer, index);
    /*利用索引表间接折半查找*/
    break;
  case 4:
    buildHashAndFound(word,buffer,index);
    /*利用hash进行查找*/
    break;
  default:
    break;
  }
  /*Show the compare times*/
  printf("%d %d\n", isFound, times);
  return 0;
}