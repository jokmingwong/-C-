#include<iostream>
#include<random>
#include<string>
uis
long long function(long long n)
{
    if (n <= 1)
        return 1;
    else
        return n * function(n-1);
}
double tylor(double, long long)
{
    long long t = 2 *n -1;
    double temp =pow(x, t);
    temp /= t;
    temp /= function(t);
    if (n % 2 == 0)
        temp *= -1;
    return temp;
}

int main()
{
    double n = 0.00;
    cin >> n;
    double result = 0.00;
    for (long long i = 1; i <= 10; ++i)
    {
        result +=tylor(n, i);
    }
    printf("%.3f", result);
    return 0;
}
