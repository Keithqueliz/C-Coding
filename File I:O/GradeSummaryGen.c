#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSTD 100  //maximum number of students
#define MAXITEMS 10 //maximum number of quizzes
#define STLEN 51  //maximum char array size. Max string length is 50.

char getLetterGrade(float score);
int getMaxTotalIdx(float totals[], int n);
int lookup(char names[][STLEN], char key[STLEN], int n);

int main()
{   
    char ID[MAXSTD][STLEN]; //for string ids
    char names[MAXSTD][STLEN];// for storing last names
    float grades[MAXSTD][MAXITEMS]; // for storing grades
    float totals[MAXSTD] = {0}; //for storing calculated totals
    int N, G, i, j;

    FILE *finput;
    FILE *foutput;
    char fileIN[STLEN];
    scanf("%s", fileIN);
    finput = fopen(fileIN, "r");
    foutput = fopen("summary.txt", "w+");
    
    fscanf(finput, "%d%d", &N, &G);
    
    // Loop will use fscanf to save the ID and names in arrays and save into summary.txt
    fprintf(foutput, "Summary of students:\n========\n");
   for(i = 0; i < N; i++)
   {    
        float quizGrade = 0.0;
        fscanf(finput, "%s%s", ID[i], names[i]);
        fprintf(foutput, "ID: %s Lname: %s ", ID[i], names[i]);

        // Loop will use fscanf to save the values of the grade into the Nth value but for G times
        for(j = 0; j < G + 2; j++)
        {   
            fscanf(finput, "%f", &grades[i][j]);

            // finds the total score = 35% of midterm + 40% of final term + 25% of the average of G quizzes
            if(j == 0)
                totals[i] += (grades[i][j] * 0.35);

            else if(j == 1)
                totals[i] += (grades[i][j] * 0.40);
            
            else
                quizGrade += grades[i][j];
        }

        // divides the total quiz grades to get the average, then the 25% 
        quizGrade = quizGrade / G;
        totals[i] += (quizGrade * .25);

        char finalGrade = getLetterGrade(totals[i]);
        fprintf(foutput, "Total: %.2f Grade: %c\n", totals[i], finalGrade);
   }

    fprintf(foutput, "\n========\n");

    rewind(foutput);
    char c;
    while((c = fgetc(foutput)) != EOF)
        printf("%c", c);
    
    fclose(finput);
    fclose(foutput);

    return 0;
}

char getLetterGrade(float score)
{   
    char finalGrade;
    // if states check and set the grade letter using the total score
    if(score >= 90)
        finalGrade = 'A';

    else if(score >= 80 && score < 90)
        finalGrade = 'B';
            
    else if(score >= 70 && score < 80)
        finalGrade = 'C';

    else
        finalGrade = 'F';
    
    return finalGrade;
}

int getMaxTotalIdx(float totals[MAXSTD], int n)
{

}

int lookup(char names[][STLEN], char key[STLEN], int n)
{

}
