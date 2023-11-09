#include <stdio.h>

int findAndStore(int mainArray[], int result[], int size, int key)
{
    int r = 0;
    for(int i = 0; i < size; i++)
    {

        if(mainArray[i] == key)
        {
            result[r] = i;
            r++;
        }
        else 
            continue;
    }

    return r;
}

int main()
{
    int mainArray[7] = {10, 20, 10, 30, 20, 15, 10};
    int result[7];
    int r, key, size = 7;

    printf("Enter a number: ");
    scanf("%d", &key);

    r = findAndStore(mainArray, result, size, key);

    if(r > 0)
    {
     printf("Your key %d can be found in index ", key);
        for(int i = 0; i < r; i++)
        {
        printf("%d ", result[i]);
        }
    }
    else
        printf("Your key was not found\n");

    return 0;
}