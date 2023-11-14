#include <stdio.h>

void display(int arr[], int size)
{
    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);      
}

int sumArray(int arr[], int size)
{
    int sum = 0;
    for(int i = 0; i < size; i++)
    {
        sum += arr[i];
    }
    return sum;
}

int findMax(int arr[], int size)
{
    int max_value = 0;
    for(int i = 0; i < size; i++)
    {   
       int max = arr[i];
       if(max > max_value)
        max_value = max;
    }
    return max_value;
}

int getDouble(int num)
{
    return num*2;
}

int main()
{
    int size = 5;
    int arr[size];
    int num, i;

    for(i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        arr[i] = num;
    }

    display(arr, size);
    int sum = sumArray(arr, size);
    int max = findMax(arr, size);

    printf("\nThe sum of myArray is: %d\n", sum);
    printf("The max value of myArray is: %d\n", max);

    for(i = 0; i < size; i ++)
    {   
        num = arr[i];
        printf("Double of %d is %d\n", num, getDouble(num));
    }

    return 0;
}