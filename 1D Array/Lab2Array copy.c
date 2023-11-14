#include <stdio.h>
#include "main.h"

int main() {

    int arr[SIZE];

    int num, i, j;

    for(i = 0; i < SIZE; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        arr[i] = num;
        num =  getchar();
    }

    int x2 = getDouble(num);
    display(arr, SIZE);
    printf("The sum of myArray is: %d\n", sumArray(arr, SIZE));
    printf("The max value of myArray is: %d\n", findMax(arr, SIZE));

    for(i = 0; i < 5; i++)
    {   
        num = arr[i];
        printf("Double of %d is %d\n", num, getDouble(num));
    }

    printf("Now the following data are from RevArray\n");
    
    for(i = SIZE - 1; i>= 0; i--)
        printf("%d ", arr[i]);
    
    printf("\nThe sum of RevArray is: %d\n", sumArray(arr, SIZE));
    printf("The max value of RevArray is: %d\n", findMax(arr, SIZE));
        
        for(i = 0; i < 5; i++)
    {   
        num = arr[i];
        printf("Double of %d is %d\n", num, getDouble(num));
    }


    return 0;
}

// The function takes an int array and its size and prints the data in the array.
void display(int arr[], int size) {
    for (int i = 0; i < size; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
}

// It takes an int array and size, and returns the sum of the elements of the array.
int sumArray(int arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

// It takes an int array and size, and returns the maximum value in the array.
int findMax(int arr[], int size) {
    if (size == 0) {
        // Handle empty array case
        printf("Error: Empty array\n");
        return 0;
    }

    int max = arr[0];
    for (int i = 1; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }
    return max;

}
// it takes an int data (not an array) and returns the double of the data passed to it.
int getDouble(int num)
{
    return num * 2;
}

