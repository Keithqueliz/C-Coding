#include <stdio.h>
#include <math.h>
#include "main.h"

// function while loop if num is less than 0, it will remove each digit then multiply by the power of 3
int SumDigitCube(int num)
{
    int sum = 0;
    while(num > 0)
    {
        int digit = num % 10;
        sum += pow(digit, 3);
        num /= 10;
    }
    return sum;
}

int main()
{
    int num;
    printf("Enter a number: ");
    scanf("%d", &num);

    printf("The Armstrong numbers are:\n");

    // for loop will create each number from 1 to num
    for (int i = 1; i <= num; i++) {
        int sum = SumDigitCube(i);
        // if the sum is equal to i, then it is an armstrong number
        if (sum == i) {
            printf("%d\n", i);
        }
    }

    return 0;
}
