#include <stdio.h>

int main()
{
    int num, digit1, digit2, digit3, digit4;
    printf("Enter a four digit number: ");
    scanf("%d", &num);

    digit4 = num%10;
    num = num/10;
    digit3 = num%10;
    num = num/10;
    digit2 = num%10;
    num = num/10;

    int sum = digit1 + digit2 + digit3 + digit4;

    printf("Your digits are: %d %d %d %d\n", digit1, digit2, digit3, digit4);
    printf("The sum of your digit is: %d", sum);

    return 0;
}