#include <stdio.h>
#include "main.h"

int main()
{
    int arr[SIZE];

    int i, num;

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        arr[i] = num;
        num =  getchar();
    }


    display(arr, SIZE);

    return 0;
}

// The function takes an int array and its size and prints the data in the array.
void display(int arr[], int SIZE)
{
    int i;
    for(i = 0; i < SIZE; i++)
        printf("%d", arr[i]);
}