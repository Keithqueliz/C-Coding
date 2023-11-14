#include <stdio.h>
#define MAX_SIZE 50000
void arrayInput(int arr[MAX_SIZE], int size);
void display_array(int arr[MAX_SIZE], int size);
void copy_array(int arr[MAX_SIZE], int arrCopy[MAX_SIZE], int size);
void selection_sort(int arr[MAX_SIZE], int size);
void swap(int *xp, int *yp);
void bubble_sort(int arr[MAX_SIZE], int size);

int main()
{
    int arr[MAX_SIZE];
    int arrCopy[MAX_SIZE];
    int size;

    printf("How many numbers to sort? ");
    scanf("%d", &size);

    arrayInput(arr, size);

    printf("Array before sorting:\n");
    display_array(arr, size);
    copy_array(arr, arrCopy, size);

    printf("Using Bubble Sort\n");
    bubble_sort(arr, size);

    printf("\nUsing Selection sort\n");
    selection_sort(arrCopy, size);

    return 0;
}

void arrayInput(int arr[MAX_SIZE], int size)
{
    int num;

    for (int i = 0; i < size; i++)
    {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &num);
        arr[i] = num;
    }
}

void display_array(int arr[MAX_SIZE], int size)
{

    for (int i = 0; i < size; i++)
    {
        printf("%d ", arr[i]);
    }

    printf("\n");
}

void copy_array(int arr[MAX_SIZE], int arrCopy[MAX_SIZE], int size)
{
    for (int i = 0; i < size; i++)
    {
        arrCopy[i] = arr[i];
    }
}

void swap(int *xp, int *yp)
{
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void bubble_sort(int arr[MAX_SIZE], int size)
{
    int count = 1;

    for (int i = 0; i < size - 1; i++)
    {
        printf("iteration# %d\n", count);

        for (int j = 0; j < size - 1 - i; j++)
        {

            if (arr[j] > arr[j + 1])
            {
                swap(&arr[j], &arr[j + 1]);
            }

            display_array(arr, size);
        }

        count++;
    }

    printf("Sorted array using Bubble Sort:\n");
    display_array(arr, size);
    count++;
}

void selection_sort(int arr[MAX_SIZE], int size)
{
    int count = 1;

    for (int i = 0; i < size - 1; i++)
    {
        int min = i;

        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[min])
                min = j;
        }

        swap(&arr[min], &arr[i]);
        printf("Iteration# %d\n", count);
        display_array(arr, size);
        count++;
    }

    printf("\nSorted array using Selection Sort:\n");
    display_array(arr, size);
}