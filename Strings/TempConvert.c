#include <stdio.h>
#include <ctype.h>

int main()
{   
    char unit;
    float temp;

    printf("Is the temperature in (F) or (C)?: ");
    scanf("%c", &unit);

    unit = toupper(unit);

    if(unit == 'C')
    {
        printf("The temperature is currently in C\n");
    }
    else if(unit == 'F')
    {
        printf("The temperature is currently in F\n");
    }
    else
    {
        printf("Invalid input\n");
    }

    return 0;
}