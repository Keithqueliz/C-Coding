#include <stdio.h>
#define MAXSIZE 500

void readArray(int a[], int size)
{
    printf("Enter %d int items: ", size);
    for(int i = 0; i < size; i++)
    {
        scanf("%d", &a[i]);
    }
}

// function can change the values in array
void printArray(int a[], int size)
{
    printf("Your array is: ");
    for(int i = 0; i < size; i++)
        printf("%d ", a[i]);
}

int main()
{
    int nums[MAXSIZE];
    int n;
    printf("How many num? <500 ");
    scanf("%d", &n);

    readArray(nums, n);

    printArray(nums, n);  

    return 0;
}
