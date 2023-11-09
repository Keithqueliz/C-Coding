#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int power_sum(int n);


int main()
{
    int n, count;

    while(1)
    {   
        printf("Enter n: ");
        scanf("%d", &n);

        if(n < 0)
            break;
        
        else
        {
            count = power_sum(n);
        }

    }

    printf("You have summed up %d series\n", count);

    return 0;
}

int power_sum(int n)
{
    float sum, count;
    int i;

    for(i = 1; i <= n; i++)
    {
        sum += 1.0/(2.0 * pow(2.0, i));

        count++;
    }

    printf("Sum of serices to %d is: %.3f\n", n, sum);

    return count;
}