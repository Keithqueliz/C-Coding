#include <stdio.h>

int main()
{   
    char grade;

    printf("Enter a letter grade: ");
    scanf("%c", &grade);

    switch(grade)
    {
        case 'A':
            printf("Perfect!\n");
            break;
        case 'B':
            printf("You did good\n");
            break;
        case 'C':
            printf("You did alright\n");
            break;
        case 'D':
            printf("You didnt get an F");
            break;
        case 'F':
            printf("Your failed\n");
            break;
        default:
            printf("Please enter a valid letter grade\n");
    }

    return 0;
}