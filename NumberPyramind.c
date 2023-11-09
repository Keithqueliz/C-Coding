#include <stdio.h>
void print_triangle(int max_value);


int main()
{
    //int created the input value for max and sets count to 0 which will count the times the while loop runs
    int max_value;
    int count = 0;

    // while 1 = while true so not false or '0'
    while(1)
    {  
        printf("Enter max value: ");
        scanf("%d", &max_value);

        print_triangle(max_value);
        // after function runs, it will return and print if they would like to continue 
        printf("Enter 0 for exit or any other digit to continue: ");

        // count ++ will create a count of the times the triangle function runs unless it is 0
        count++;

        // getchar() will remove the previous value entered for max_value
        int max_vaule = getchar();
        scanf("%d", &max_value);

        if(max_value == 0)
            break;
    }

    printf("Total triangle printed: %d", count);

    return 0;
}
// I was a bit confused with the way this function worked due to the mutliple loops
void print_triangle(int max_value)
{
    // the main loop will run for n times, it runs for the amount of total lines
    for(int i = 1; i <= max_value; i++)
   {    
        // first loop will print the spaces to align the triangle, max value - 1 will print the spaces for the first line
        for(int j = 1; j <= max_value - i; j++)
                printf(" ");
        // second loop will run to print the count of j until i
        for(int j = 1; j <= i; j++)
            printf("%d", j);
        // third loop prints j in a decending starting from i
        for(int j = i - 1; j >= 1; j--)
            printf("%d", j);
        //prints new space afterwards
        printf("\n");
   }
}