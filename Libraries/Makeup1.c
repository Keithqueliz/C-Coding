#include <stdio.h>
#include <math.h>
float sumSeries(int x, int max);

int main()
{
    int x, max;
    float sum;

    printf("Enter the value of x and max: ");
    scanf("%d%d", &x, &max);

    sum = sumSeries(x, max);

    printf("Sum = %.2f\n", sum);

    return 0;
}

float sumSeries(int x, int max)
{
    float sum = (x - 1.0) / x;

    for (int i = 2; i <= max; i++)
    {
        sum += .5 * (pow((x - 1.0) / x, i));
    }

    return sum;
}