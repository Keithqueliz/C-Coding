#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

int main()
{   
    // opens file
    FILE *infile;
    int ID, N, Courses, g1, g2, g3;
    char Names[MAX];
    char searchKey[MAX], newName[MAX];
    infile = fopen("student.txt", "r");
    char ch;

    // loop will run while user inputs 1 to search for name within file
    while(1)
    {
        printf("Enter '1' to search by name\nEnter '2' to exit\n");
        
        ch = getchar();

        if(ch == '1')
        {   
            // rewind will set the file back to the beginging without having to close
            rewind(infile);
            printf("Enter a name to search:\n");
            scanf("%s", searchKey);
            printf("Searching for name...\n");

            int found = 0;
            
            // will scan and save the values line by line while comparing the search key to the name as it passes 
            while(fscanf(infile, "%d %s %d %d %d", &ID, Names, &g1, &g2, &g3) !=EOF)
            {
                if(strcmp(searchKey, Names) == 0)
                {
                    found = 1;
                    printf("We found %s\n", searchKey);
                    printf("ID: %d, Name: %s, Grades: %d %d %d\n", ID, Names, g1, g2, g3);
                    break;
                }
            }

             if(!found)
                {
                    printf("Sorry could not find item\n");
                }
            else
            {
                printf("Thanks for searching\n");
                break;
            }

            // cleanup will ensure the new space does not get taken as an input
            char cleanup;

            while((cleanup = getchar() != '\n') && cleanup != EOF);
        }
    }

    return 0;
}