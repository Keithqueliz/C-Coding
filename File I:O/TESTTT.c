#include <stdio.h>
#include <ctype.h>
#include <string.h>

#define MAXSTD 100  //maximum number of students
#define MAXITEMS 10 //maximum number of quizzes
#define STLEN 51  //maximum char array size. Max string length is 50.

char getLetterGrade(float score);
int getMaxTotalIdx(float totals[], int n);
int lookup(char names[][STLEN], char key[STLEN], int n);
void writeData(FILE *foutput, char ID[MAXSTD][STLEN], char names[MAXSTD][STLEN],  float totals[MAXSTD], int N);

int main()
{   
    char ID[MAXSTD][STLEN]; //for string ids
    char names[MAXSTD][STLEN];// for storing last names
    float grades[MAXSTD][MAXITEMS]; // for storing grades
    float totals[MAXSTD] = {0}; //for storing calculated totals
    char key[STLEN];
    int N, G, i, j;

    FILE *finput;
    FILE *foutput;
    char fileIN[STLEN];
    scanf("%s", fileIN);
    // opens input file in read mode
    finput = fopen(fileIN, "r");
    // opens output file in write + read mode
    foutput = fopen("summary.txt", "w+");
    
    fscanf(finput, "%d%d", &N, &G);
    
    // Loop will use fscanf to save the ID and names in arrays and save into summary.txt
   for(i = 0; i < N; i++)
   {    
        float quizGrade = 0.0;
        fscanf(finput, "%s%s", ID[i], names[i]);

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
   }

   writeData(foutput, ID, names, totals, N);

   printf("Enter a last name to search: ");
   scanf("%s", key);
   int keyIndex = lookup(names, key, N);

   if(keyIndex == -1)
   {
        printf("%s not found in the list\n", key);    
   }
    
    else  
    {
        printf("%s was found in the list. Here is the details:\n", key);
        printf("ID: %s Lname: %s Total: %.2f Grades:\n", ID[keyIndex], names[keyIndex], totals[keyIndex]);
        printf("Midterm: %.2f, Final term: %.2f, quzies:\n", grades[keyIndex][0], grades[keyIndex][1]);
        for(int i = 2; i < G + 2; i++)
        {
            printf("%.2f ", grades[keyIndex][i]);
        }
    } 
   
    // closes both files after finished
    fclose(finput);
    fclose(foutput);

    return 0;
}

void writeData(FILE *foutput, char ID[][STLEN], char names[][STLEN],  float totals[MAXSTD], int N)
{
    // Loop will use fscanf to save the ID and names in arrays and save into summary.txt
    fprintf(foutput, "Summary of students:\n========\n");
   for(int i = 0; i < N; i++)
   {  
        fprintf(foutput, "ID: %s Lname: %s ", ID[i], names[i]);
        char finalGrade = getLetterGrade(totals[i]);
        fprintf(foutput, "Total: %.2f Grade: %c\n", totals[i], finalGrade);
   }

    fprintf(foutput, "\n========\n");

    // Prints the contents of summary.txt by rewinding to begining and prints untill EOF
    rewind(foutput);
    char c;
    while((c = fgetc(foutput)) != EOF)
        printf("%c", c);

    // calls and prints the first student with the highest total
    int index = getMaxTotalIdx(totals, N);
    printf("First student with the highest total is %s %s %.2f\n", ID[index], names[index], totals[index]);
    printf("Data written in summary.txt file\n");

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
    int index;
    float highest = totals[0];

    for(int i = 0; i < n; i ++)
    {
        if(totals[i] > highest)
        {
            highest = totals[i];
            index = i;
        }
    }

    return index;
}

int lookup(char names[][STLEN], char key[STLEN], int n)
{   
    int found;

    for(int j = 0; j < strlen(key); j++)
  {
        key[j] = tolower(key[j]);
  }

    for(int i = 0; i < n; i++)
    {   
        if(strcmp(names[i], key) == 0)
        {   
            return i;
        }
        if(strcmp(names[i], key) != 0)
        {
            found = -1;
        }
    }

    return found;

}
