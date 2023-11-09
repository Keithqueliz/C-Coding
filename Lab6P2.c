#include <stdio.h>

long long int factorial(int n)
{
    long long fact = 1;

    for ( int i = 0; i <= n; i ++)
    {
        fact *= n;
    }

    return fact; 
}

long long power(int x, int y)
{ 
    long long product = 1;

    while(y > 0)
    {
        product *= x;
        y --;
    }

    return product;
}

int main()
{
    int n;
    printf("Enter your n: ");
    scanf("%d", &n);

    float sum = 0.0;

    for(int i = 0; i <= n; i ++)
    {
        long long pow = power(n,i);
        long long fact = factorial(n);
        
        sum += fact/pow;
    }

    printf("Summation of the series from 1 to %d is: %.2lf", n, sum);

    return 0;
}