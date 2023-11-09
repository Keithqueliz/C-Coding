#include <stdio.h>


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

    for(i = 0; i < size/2; i++)
    {
        int temp = arr[i];
        arr[i] = arr[size - 1 - i];
        arr[size - 1 - i] = temp;

    }

    for(int i = 0; i < size; i++)
        printf("%d ", arr[i]);      

    return 0;

}