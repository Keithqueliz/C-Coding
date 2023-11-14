#include <stdio.h>
#include <string.h>
#include <ctype.h>
#define MAX 50

int main()
{   
    // opens file
    FILE *infile;
    infile = fopen("student.txt", "r+");
    char Names[MAX][MAX];
    float Grades[MAX];
    char search[MAX], newName[MAX];
    int ID, N, Courses, g1, g2, g3;

    fscanf(infile, "%d %d", &N, &Courses);

    printf("%d %d\n", N, Courses);

    printf("Enter a search name & new name: ");
    scanf("%s %s", search, newName);
    printf("Finding %s to replace with %s....\n", search, newName);

    for(int i = 0; i < N; i++)
    {
        fscanf(infile, "%d%s", &ID, Names[i]);
        printf("%s\n", Names[i]);
    
        if(strcmp(search, newName[i]) == 0)
        {
            printf("Found the name. Updating...\n");
            fseek(infile, -strlen(Names[i]), SEEK_CUR);
            fprintf(infile, "%s", newName);
            break;
        }

        for(int j = 0; j < Courses; j++)
        {
            fscanf(infile, "%f", &Grades[j]);
        }
    }
    
    fclose(infile);

    return 0;
}