#include <stdio.h>
#include <math.h>
// The function returns 1 if the number is 4 digits number. Otherwise, the function will return 0.
int isFourDigit(int num, int arr[]);
// The function reverse the 4-digit number and returns it.
int reverse4Digit(int num, int arr[]);
// The function adds the first and last digit of the number and prints their sum.
void addSides4Digit(int num, int arr[]);
// The function calls the reverse4Digit() function with the number and compares it with the original number. 
void isPalindrome4Digit(int num, int arr[]);

int main()
{   
    int arr[4];
    int num;
    printf("Enter a four digit number: ");
    scanf("%d", &num);

    reverse4Digit(num, arr);
    addSides4Digit(num, arr);
    isPalindrome4Digit(num, arr);

    return 0;
}

int isFourDigit(int num, int arr[])
{
    int temp, i, count = 0;
    
    for(i = 0; i < 4; i++)
    {
        arr[i] = num%10;
        num = num/10;
        count ++;
    }
    if(count == 4)
        return 1;
    else 
        return 0;
}

int reverse4Digit(int num, int arr[])
{
    int i;
    
    if(isFourDigit(num, arr) == 0)
    {
        printf("Invalid to reverse\n");
        return -1;
    }
    else
    {   
        printf("Reverse is: ");

        for(i = 0; i < 4; i++)
             printf("%d", arr[i]);
    }
}
void addSides4Digit(int num, int arr[])
{
    if(isFourDigit(num, arr) == 0)
        printf("\nInvalid input to calculate sides");
    else
        printf("\nSum of sides is: %d\n", arr[0] + arr[3]);
}
void isPalindrome4Digit(int num, int arr[])
{
    int reverse = reverse4Digit(num, arr);

    if(reverse == num)
        printf("\nPalindrome");

    else if(reverse == -1)
        printf("\nInvalid input for palindrome checker");

    else
        printf("\nNot palindrome");
}