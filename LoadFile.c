#include <stdio.h>
#define MAX 100
#define MAXSTUDENTS 100

int main()
{   
    // opens file in read and the output file in write
    FILE *ifp, *ofp;
    ifp = fopen("student.txt", "r");
    ofp = fopen("Graderesults.txt", "w");
    int name, courses;

    int ID[MAXSTUDENTS];
    char Names[MAXSTUDENTS][MAX];
    float Grades[MAXSTUDENTS][MAX];
    float AverageGrades[MAXSTUDENTS];

    // scans for the first two data types to find the total names and courses
    fscanf(ifp, "%d%d", &name, &courses);

    // prints in the output file 
    fprintf(ofp, "List of Students\n");

    // loop will save the ifp into arrays to be used later
    for(int i = 0; i < name; i++)
    {   
        float avg = 0.0;
        fscanf(ifp, "%d%s", &ID[i], Names[i]);

        for(int j = 0; j < courses; j++)
        {
            fscanf(ifp, "%f", &Grades[i][j]);
            avg += Grades[i][j];
        }

        AverageGrades[i] = (avg / courses);

        fprintf(ofp, "%d %s %.2f\n", ID[i], Names[i], AverageGrades[i]);
    }

    float maxAverage = AverageGrades[0];
    int maxID = 0;

    for(int i = 0; i < name; i++)
    {
        if(AverageGrades[i] > maxAverage)
        {
            maxAverage = AverageGrades[i];
            maxID = i;
        }
    }

    fprintf(ofp, "The max average is student %s with %.2f\n", Names[maxID], AverageGrades[maxID]);

    // must close files in seperate lines
    fclose(ifp);
    fclose(ofp);

    return 0;
}