#include <stdio.h>
#define ANSW -100

int main()
{   
    int num;
    int pos = 0, neg = 0, zero = 0;

    printf("Input your guess: ");

    while(num != ANSW)
    {
        scanf("%d", &num);

        if(num > 0)
            pos++;
        else if(num == 0)
            zero++;
        else
            neg++; 
    }

    printf("Number of postive numbers: %d\n", pos);
    printf("Number of negative numbers: %d\n", neg - 1);
    printf("Number of zeros: %d\n", zero);

    return 0;
}