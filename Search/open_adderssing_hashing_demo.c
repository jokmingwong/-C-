#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef unsigned int Index;
#define HASHNUM 97
/*There is still some error in this page*/
Index hash(const char *key) {
  Index seed = 131;
  Index hash = 0;
  while (*key)
    hash = hash * seed + (*key++);
  return hash % HASHNUM;
}

typedef struct {
  int isExsit;
  char value[10];
} HashElement;

Index FindWord(const char *key, HashElement *T) {
  Index CurrentPos = hash(key);
  int CollisionNum = 0;
  while (T[CurrentPos].isExsit != 0) {
    CurrentPos += 2 * ++CollisionNum - 1;
    if (CollisionNum >= HASHNUM) {
      CurrentPos -= HASHNUM;
    }
  }
  return CurrentPos;
}

void initialize(HashElement *T) {
  Index index;
  for (index = 0; index < HASHNUM; index++) {
    T->isExsit = 0;
  }
}

void ShowArray(const HashElement *T, const unsigned int Num) {
  unsigned int index;
  for (index = 0; index < Num; index++) {
    if (T[index].isExsit)
      printf("Index:%u,Value:%s\n", index, T[index].value);
  }
}

int main() {
  char test[15];
  HashElement *HashTable = malloc(sizeof(HashElement) * HASHNUM);
  initialize(HashTable);
  while (scanf("%15s",test)!=EOF) {
      Index target = FindWord(test, HashTable);
      strcpy(HashTable[target].value, test);
      HashTable[target].isExsit = 1;
  }
  ShowArray(HashTable, HASHNUM);
  return 0;
}