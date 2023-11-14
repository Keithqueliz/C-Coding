#include <stdio.h>
void print_triangle(int max);

int main()
{
    int max, count;

    while(1)
    {
        printf("Enter the max value: ");
        scanf("%d", &max);

        print_triangle(max);

        printf("Enter 0 for exit or any other digit to continue: ");
        max = getchar();

        scanf("%d", &max);

        if(max == 0)
            break;
        
        count++;
    }

    printf("Total triangles printed: %d", count);

    return 0;
}

void print_triangle(int max)
{   
    int i;

    for(i = 1; i < max; i ++)
    {
        for(i = 0; i <= max; i++)
            printf("%d", i);
        
        printf("\n");
    }
}