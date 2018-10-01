#include <stdio.h>
int hash(const char *test, int TableSize)
{
    unsigned int HashVal = 0;
    while (*test != '\0')
    {
        HashVal = (HashVal << 5) + *test++;
    }
    return HashVal % TableSize;
}
int main()
{
    char test[10];
    int tablesize;
    while (scanf("%s %d", test, &tablesize) != EOF)
    {
        printf("The %s index is %d\n", test, hash(test, tablesize));
    }
    return 0;
}