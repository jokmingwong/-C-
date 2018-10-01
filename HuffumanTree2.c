#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX 200
typedef struct {
  char letter;
  int count;
  char code[MAX];
} Word;

typedef struct node {
  Word data;
  struct node *lchild;
  struct node *rchild;
} Node;

Node *letterTree[MAX];
Word letterab[MAX];
/*Define the position of array*/
unsigned int pos = 1;

int myComp(const void *a1, const void *b1) {
  const Word *a = a1;
  const Word *b = b1;
  return a->count > b->count || (a->count == b->count && a->letter > b->letter)
             ? 1
             : -1;
}

void convertToRealLetter(Word *templetterab) {
  /*在最初始的位置加一个\0作为结束符*/
  letterab[0].letter = '\0';
  letterab[0].count = 1;
  unsigned int i;
  for (i = 1; i < MAX; i++) {
    if (templetterab[i].letter != '\0') {
      letterab[pos++] = templetterab[i];
    }
  }
  qsort(letterab, pos, sizeof(Word), myComp);
}

Node *buildTree(Node *tree) {
  unsigned int i = 0;
  int index1 = 0, index2 = 1;
  for (i = 0; i < pos; i++) {
    letterTree[i] = (Node *)malloc(sizeof(Node));
    letterTree[i]->data = letterab[i];
    letterTree[i]->rchild = letterTree[i]->lchild = NULL;
  }
  int times = pos;
  for (i = 1; i < times; i++) {
    Node *q = (Node *)malloc(sizeof(Node));
    q->data.count =
        letterTree[index1]->data.count + letterTree[index2]->data.count;
    q->lchild = letterTree[index1];
    q->rchild = letterTree[index2];
    unsigned int j = index1;
    /*插入新值*/
    while (letterTree[j] && letterTree[j]->data.count <= q->data.count)
      j++;
    unsigned int k = pos;
    while (k > j) {
      letterTree[k] = letterTree[k - 1];
      k--;
    }
    pos++;
    letterTree[j] = q;
    letterTree[index2] = letterTree[index1] = NULL;
    /*如果到了最后一个*/
    if (i == times - 1) {
      tree = letterTree[j];
      break;
    }
    /*分别找到index1和index2*/
    int findIndexOne = 0;
    for (j = 0; j < pos; j++) {
      if (findIndexOne == 0 && letterTree[j] != NULL) {
        index1 = j;
        findIndexOne = 1;
      } else if (findIndexOne == 1 && letterTree[j] != NULL) {
        index2 = j;
        break;
      }
    }
  }
  return tree;
}

void huffmanCode(Node *t, int depth, Word *huffman) {
  static char Hcode[MAX];
  if (t) {
    /*叶子结点 解码*/
    if (t->lchild == NULL && t->rchild == NULL) {
      int i;
      huffman[(unsigned int)t->data.letter].letter = t->data.letter;
      for (i = 0; i < depth; i++) {
        huffman[(unsigned int)t->data.letter].code[i] = Hcode[i];
      }
    } /*非叶子结点，继续寻找*/
    else {
      /*0向左*/
      Hcode[depth] = '0';
      huffmanCode(t->lchild, depth + 1, huffman);
      /*1向右*/
      Hcode[depth] = '1';
      huffmanCode(t->rchild, depth + 1, huffman);
    }
  }
}

void transInt(char *in, int *a) {
  *a = 0;
  while (*in != '\0') {
    *a = (*a << 1) + (*in - '0');
    in++;
  }
}

int main() {
  FILE *in = fopen("input.txt", "r");
  Word *templetterab = (Word *)malloc(sizeof(Word) * MAX);
  char *buffer = malloc(1024 * sizeof(char));
  while (fgets(buffer, 1024, in)) {
    while (*buffer != '\0' && *buffer != '\n') {
      templetterab[(unsigned int)*buffer].letter = *buffer;
      templetterab[(unsigned int)*buffer].count++;
      buffer++;
    }
  }
  fseek(in, 0, SEEK_SET);
  convertToRealLetter(templetterab);
  Node *tree = NULL;
  tree = buildTree(tree);
  /*Define a huffuman array*/
  Word huffman[MAX];
  huffmanCode(tree, 0, huffman);
  FILE *out = fopen("output.txt", "w");
  char code[MAX] = "";
  while (fgets(buffer, 1024, in) != NULL) {
    while (*buffer != '\0') {
      strcat(code, huffman[(int)*buffer].code);
      buffer++;
    }
  }
  fclose(in);
  strcat(code, huffman[0].code); /*末尾加上‘/0’*/
  int length = strlen(code);
  int left = 8 - length % 8;
  unsigned int i;
  for (i = length; i < length + left; i++)
    code[i] = '0';
  char temp[9] = "";
  int t = 0;
  for (i = 0; code[i] != '\0'; i++) {
    temp[t++] = code[i];
    if ((i + 1) % 8 == 0) {
      int huffman_code;
      transInt(temp, &huffman_code);
      printf("%x", huffman_code);
      fprintf(out, "%x", huffman_code);
      /*置空temp数组*/
      t = 0;
      strcpy(temp, "\0");
    }
  }
  fclose(out);
  return 0;
}
