#include <stdio.h>

int main()
{
    int slices;
    printf("Enter how much you ate:" );
    scanf("%d", &slices);

    switch(slices)
    {
        case 1:
            printf("You did a great job!");
            break;
        case 2:
            printf("You did okay");
            break;
        case 3:
            printf("You did bad");
            break;
        case 4:
            printf("You did horrible");
            break;
        default:
            printf("You need to eat less");
            break;
    }
    return 0;
}

