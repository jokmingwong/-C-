#include <stdio.h>
typedef struct Point
{
    int x;
    int y;
} Point;
#define max(a, b) (a > b ? a : b)
#define min(a, b) (a < b ? a : b)
int common(int A1X, int A2X, int B1X, int B2X)
{
    int MAX_AX, MAX_BX, MIN_AX, MIN_BX;
    if (A1X < A2X)
    {
        MAX_AX = A2X;
        MIN_AX = A1X;
    }
    else
    {
        MIN_AX = A2X;
        MAX_AX = A1X;
    }
    if (B1X < B2X)
    {
        MAX_BX = B2X;
        MIN_BX = B1X;
    }
    else
    {
        MIN_BX = B2X;
        MAX_BX = B1X;
    }
    int result = min(MAX_AX, MAX_BX) - max(MIN_AX, MIN_BX);
    if (result >= 0)
        return result;
    else
    {
        return 0;
    }
}

int main()
{
    Point A1, A2, B1, B2;
    scanf("%d %d %d %d", &A1.x, &A1.y, &A2.x, &A2.y);
    scanf("%d %d %d %d", &B1.x, &B1.y, &B2.x, &B2.y);
    printf("%d", common(A1.x, A2.x, B1.x, B2.x) * common(A1.y, A2.y, B1.y, B2.y));
    return 0;
}