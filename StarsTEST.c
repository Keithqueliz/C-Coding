#include <stdio.h>

int main()
{
    int n;
    printf("Enter n: ");
    scanf("%d", &n);

    for(int i = 0; i <= n; i ++)
    {   //nest loop will run untill no longer true each time 
        for(int j = 0; j <= i; j ++)
            printf("*");
        //print outside loop so it prints after j loop ends creating the triangle effect
        printf("\n");
    }
    //i starts at n to print a decreasing triangle, while is more than or equal to 1 it runs j
    for(int i = n; i >= 1; i --)
    {   
        //while j is more than or equal to 1, it prints a *
        for(int j = i; j >= 1; j --)
            printf("*");

        printf("\n");
    }

    return 0;
}