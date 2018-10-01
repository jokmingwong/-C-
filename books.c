#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct bookNode {
  char name[50];
  char author_name[20];
  char press_name[30];
  int year;
  struct bookNode *next;
} bookListNode;

int find(char *T, char *target) {
  int t = 0;
  int end = strlen(target) - 1;
  while (T[t] != '\0') {
    if (T[t] == target[0] && t + end < strlen(T) && T[t + end] == target[end]) {
      int q;
      for (q = 1; q < end; q++) {
        if (T[q] != target[q]) {
          break;
        }
      }
      if (q == end) {
        return 1;
      }
    }
    t++;
  }
  return 0;
}

bookListNode *insert(bookListNode *list, char *n1, char *n2, char *n3, int n4) {
  bookListNode *q, *r;
  bookListNode *pb = (bookListNode *)malloc(sizeof(bookListNode));
  strcpy(pb->name, n1);
  strcpy(pb->author_name, n2);
  strcpy(pb->press_name, n3);
  pb->year = n4;
  if (list == NULL || (list != NULL && strcmp(n1, list->name) < 0)) {
    pb->next = list;
    list = pb; //指向被插入的新结点
  } else {
    q = list->next;
    r = list;
    while (r != NULL && q != NULL && strcmp(n1, q->name) > 0) {
      r = r->next;
      q = q->next;
    }
    pb->next = q;
    r->next = pb;
  }
  return list;
}

void printBook(bookListNode *t) {
  printf("%-50s%-20s%-30s%-10d\n", t->name, t->author_name, t->press_name,
         t->year);
}

void search(bookListNode *list, char *s) {
  bookListNode *p = list;
  while (p != NULL) {
    if (find(p->name, s)) {
      printBook(p);
    }
    p = p->next;
  }
}
bookListNode *delete (bookListNode *list, char *s) {
  if (list != NULL) {
    bookListNode *p = list->next;
    bookListNode *q = list;
    while (p != NULL) {
      if (find(p->name, s)) {
        q->next = p->next;
        free(p);
        p = q->next;
      } else {
        q = p;
        p = p->next;
      }
      if (find(list->name, s)) {
        q = list;
        list = list->next;
        free(q);
      }
    }
  }
  return list;
}

int main() {
  FILE *in = fopen("books.txt", "r");
  FILE *out = fopen("ordered.txt", "w");
  bookListNode *list = NULL;
  char t1[50], t2[20], t3[30];
  int t4;
  while (fscanf(in, "%s %s %s %d", t1, t2, t3, &t4) != EOF) {
    list = insert(list, t1, t2, t3, t4);
  }

  while (1) {
    char t;
    t = getchar();
    int canOut = 0;
    char bookname[100];
    char n1[50], n2[20], n3[30];
    int n4;
    switch (t) {
    case '0': {
      canOut = 1;
      break;
    }
    case '1': {
      scanf("%s %s %s %d", n1, n2, n3, &n4);
      list = insert(list, n1, n2, n3, n4);
      break;
    }
    case '2': {
      scanf("%s", bookname);
      search(list, bookname);
      break;
    }
    case '3': {
      scanf("%s", bookname);
      list = delete (list, bookname);
      break;
    }
    }
    if (canOut == 1) {
      break;
    }
  }
  bookListNode *pr = list;
  while (pr != NULL) {
    fprintf(out, "%-50s%-20s%-30s%-10d\n", pr->name, pr->author_name,
            pr->press_name, pr->year);
    pr = pr->next;
  }
  fclose(in);
  fclose(out);
  return 0;
}