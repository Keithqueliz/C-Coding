#include <stdio.h>
#include <string.h>

#define MAX 100

int main()
{
    char first[MAX], last[MAX], fullName[MAX * 2];

    printf("Enter your first and last name: ");
    scanf("%s %s", first, last);

    // Finds lenght of first name string
    int firstLen = strlen(first);
    printf("The length of your first name is: %d\n", firstLen);

    // Saves the result of strcmp to compare to 
    int cmpResults = strcmp(first, last);

    if(cmpResults > 0)
    {
        printf("Your last name comes first\n");
    }
    
    else if(cmpResults < 0)
    {
        printf("Your first name comes first\n");
    }

    // Using concat and strcpy to add the first and last to fullname
    strcpy(fullName, first);
    strcat(fullName, " ");
    strcat(fullName, last);
    printf("Your full name is %s\n", fullName);

    // Using strstr
    printf("Enter a sub string to search: ");
    char key[MAX];
    scanf("%s", key);

    // Char pointer saves the address of the start of the key to be printed later
    char *remainder = strstr(fullName, key);
    if(remainder)
    {
        printf("Your key was found! The remainder is %s\n", remainder);
    }
    else
    {
        printf("Your key was not found\n");
    }

    return 0;
}