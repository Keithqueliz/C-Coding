#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main()
{
    char nameStr[MAXSTRINGS][MAXLENGTH];
    char x;
    int N;
    int count = 1;

    // Get the number of names from the user
    printf("Enter how many names: ");
    scanf("%d", &N);

    // Input names and convert to lowercase
    for(int i = 0; i < N; i++)
    {
        // Clear input buffer to avoid issues with previous newline characters
        while((x = getchar() != '\n') && x != EOF);

        // Prompt for name input
        printf("\nName %d: ", count);
        scanf("%[^\n]s", nameStr[i]);

        // Convert the entered name to lowercase
        lower(nameStr[i]);
        count++;
    }

    // Sort the names using selection sort
    selection_sort(nameStr, N);

    // Print sorted names
    printf("Sorted Names:\n");
    for(int i = 0; i < N; i++)
    {
        printf("%s\n", nameStr[i]);
    }

    char search[MAXLENGTH];

    // Search for names containing a given substring until "exit" is entered
    while(1)
    {
        // Clear input buffer to avoid issues with previous newline characters
        while((x = getchar() != '\n') && x != EOF);

        // Prompt for search string input
        printf("Enter search string: ");
        scanf("%[^\n]s", search);

        // Convert the search string to lowercase
        lower(search);

        // Exit the loop if the search string is "exit"
        if(strcmp("exit", search) == 0)
        {
            break;
        }

        // Search for names containing the given substring
        int found = 0;
        for (int i = 0; i < N; i++) 
        {
            if (strstr(nameStr[i], search) != NULL) {
                printf("%s\n", nameStr[i]);
                found = 1;
            }
        }

        // Print "not found" if no matching names were found
        if (!found) 
        {
            printf("not found\n");
        }
    }

    return 0;
}

// Function to perform selection sort on an array of strings
void selection_sort(char nameStr[MAXSTRINGS][MAXLENGTH], int N)
{   
   int i, j, min;

   for(i = 0; i < N - 1; i++)
   {    
        min = i;

        // Find the index of the minimum element in the remaining unsorted array
        for(j = i + 1; j < N; j++)
        {
            if(strcmp(nameStr[j], nameStr[min]) < 0)
            {
                min = j;
            }
        }

        // Swap the found minimum element with the first element
        swapString(nameStr[i], nameStr[min]);
   }
}

// Function to convert a string to lowercase
void lower(char *nameStr)
{
    for(int i = 0; nameStr[i] != '\0'; i++)
    {
        nameStr[i] = tolower(nameStr[i]);
    }
}

// Function to swap two strings
void swapString(char *S1, char *S2)
{
    char copy[MAXLENGTH];

    // Perform string swapping using a temporary variable
    strcpy(copy, S1);
    strcpy(S1, S2);
    strcpy(S2, copy);
}
