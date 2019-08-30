#include <math.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define NHASH 5000011
#define FILE_SIZE 6000000
#define PREFIX_NUM 2
typedef struct State State;
typedef struct Suffix Suffix;
struct State {
  char *pref[PREFIX_NUM];
  Suffix *suf;
  State *next;
  unsigned int sufNum;
};
struct Suffix {
  char *word;
  Suffix *next;
};
State *statetab[NHASH];
unsigned int fileSize = 0;
char fileArray[FILE_SIZE];

unsigned long hash(char *s[PREFIX_NUM]);
inline unsigned long hash(char *s[PREFIX_NUM]) {
  unsigned int seed = 131;
  unsigned int hash = 0;
  unsigned int i;
  for (i = 0; i < PREFIX_NUM; i++) {
    const char *str = s[i];
    while (*str)
      hash = hash * seed + (*str++);
  }
  return hash % NHASH;
}

/*查找前缀数组prefix[PREFIX_NUM]是否在哈希表中出现*/
State *lookup(char *prefix[PREFIX_NUM], const int isBuild) {
  /*If isBuild is true,it will could a new node*/
  int i;
  unsigned long h;
  h = hash(prefix);
  State *sp = statetab[h];
  while (sp != NULL) {
    for (i = 0; i < PREFIX_NUM; ++i) {
      if (strcmp(prefix[i], sp->pref[i]))
        break;
    }
    if (i == PREFIX_NUM) //找到就返回
      return sp;
    sp = sp->next;
  }
  if (isBuild) {
    sp = malloc(sizeof(State));
    for (i = 0; i < PREFIX_NUM; ++i) {
      sp->pref[i] = prefix[i];
    }
    sp->suf = NULL;
    sp->sufNum = 0;
    sp->next = statetab[h]; //头插法
    statetab[h] = sp;
  }
  return sp;
}

/*直接在头结点插入减少时间*/
State *addsuffix(State *sp, char *suffix);
inline State *addsuffix(State *sp, char *suffix) {
  Suffix *suf = malloc(sizeof(Suffix));
  suf->word = suffix;
  suf->next = sp->suf;
  sp->sufNum++;
  sp->suf = suf;
  return sp;
}
double seed = 997;

double rrand();
inline double rrand() {
  double lambda = 3125.0;
  double m = 34359738337.0;
  double r;
  seed = fmod(lambda * seed, m); //要包含头文件#include <math.h>
  r = seed / m;
  return r;
}

void build(char *prefix[PREFIX_NUM] /*, FILE *f*/) {
  State *sp;
  unsigned int i;
  for (i = 0; i < fileSize; i++) {
    char buf[60];
    /*Jump the space*/
    while (fileArray[i] == ' ' || fileArray[i] == '\r' ||
           fileArray[i] == '\t' || fileArray[i] == '\n')
      i++;
    unsigned int j = 0;
    while (fileArray[i] != '\0' && fileArray[i] != ' ' &&
           fileArray[i] != '\r' && fileArray[i] != '\t' &&
           fileArray[i] != '\n') {
      buf[j++] = fileArray[i++];
    }
    buf[j] = '\0';
    char *suffix = strdup(buf);
    sp = lookup(prefix, 1);
    sp = addsuffix(sp, suffix);
    // memmove(prefix, prefix + 1, sizeof(prefix[0]));
    memcpy(prefix, prefix + 1, sizeof(prefix[0]));
    prefix[1] = suffix;
  }

  /*末尾加一个(end)*/
  sp = lookup(prefix, 1);
  sp = addsuffix(sp, "(end)");
  memcpy(prefix, prefix + 1, sizeof(prefix[0]));
  prefix[1] = "(end)";
}

void generate(int nwords, FILE *OUT) {
  State *sp;
  char *prefix[PREFIX_NUM], *w;
  unsigned int i;
  for (i = 0; i < PREFIX_NUM; ++i)
    prefix[i] = "\0";
  for (i = 0; i < nwords; ++i) {
    sp = lookup(prefix, 0);
    Suffix *suf = sp->suf;
    if (sp->sufNum == 1) {
      w = suf->word;
    } else {
      int n = sp->sufNum - (int)(rrand() * sp->sufNum) - 1;
      while (suf != NULL) {
        if (n == 0) {
          w = suf->word;
          break;
        }
        suf = suf->next;
        n--;
      }
    }
    if (strcmp(w, "(end)") == 0)
      break;
    fprintf(OUT, "%s ", w);
    memcpy(prefix, prefix + 1, (PREFIX_NUM - 1) * sizeof(Suffix));
    // strcpy(prefix[0], prefix[1]);
    prefix[1] = w;
  }
}

int main() {
  unsigned long int nwords;
  unsigned int i;
  scanf("%lu", &nwords);
  char *prefix[PREFIX_NUM];
  for (i = 0; i < PREFIX_NUM; ++i)
    prefix[i] = "\0";
  FILE *in = fopen("article.txt", "r");
  fileSize = fread(fileArray, 1, FILE_SIZE, in);
  fileArray[fileSize] = '\0';
  fclose(in);
  build(prefix);
  FILE *out = fopen("markov.txt", "w");
  generate(nwords, out);
  fclose(out);
  return 0;
}