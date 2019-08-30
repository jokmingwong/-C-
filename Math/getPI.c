#include <stdio.h>
//π/2=1+1!/3+2!/(3×5)+3!/(3×5×7)+…+(n-1)!/(3×5×7×…×(2n-1))
void solve(double t)
{
    int i = 0;
    double up = 1;
    double down = 1;
    double pi = 0;
    while (1)
    {
        double plus;
        plus = 2.0 * up / down;
        pi += plus;
        i++;
        up *= i;
        down *= 2 * i + 1;
        if (plus < t)
        {
            printf("%d %.7lf", i, pi);
            return;
        }
    }
}
int main()
{
    void solve(double);
    double f;
    scanf("%lf", &f);
    solve(f);
    return 0;
}