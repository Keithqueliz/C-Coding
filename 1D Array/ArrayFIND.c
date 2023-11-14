#include <stdio.h>
int findItem(int a[], int n, int key);
int keyFinder(int a[], int n);

int main()
{   
    int a[] = {10, 5, 10, 20, 19, 10, 70};
    int key, flag;

    printf("Enter a number to search: ");
    scanf("%d", &key);

    findItem(a, 6, key);

}


int findItem(int a[], int n, int key)
{
    int flag = 0, index = -1;
    for(int i = 0; i < n; i++)
    {
        if(a[i] == key)
        {
            flag =  1;
            index += i;
        }
    }

    if(flag == 1)
        printf("Found it!, we found it in index %d\n", index);
    else
        printf("Flag not found.");
}