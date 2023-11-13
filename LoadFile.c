#include <stdio.h>
#define MAX 100
#define MAXSTUDENTS 100

int main()
{
    int ID[MAXSTUDENTS];
    char Names[MAXSTUDENTS][MAX];
    float Grades[MAXSTUDENTS][MAX];
    float AverageGrades[MAXSTUDENTS];

    FILE *ifp, *ofp;
    ipf = fopen("student.txt", "r");
    opf = ("Graderesults.txt", "w");
    int name, courses;

    fscanf(ifp, "%d%d", &name, &courses);

    fprintf(ofp, "List of Students\n");

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


    return 0;
}