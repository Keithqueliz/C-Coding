#include <stdio.h>
#define MAX 100
#define MAXSTUDENTS 100

int main()
{
    int ID[MAXSTUDENTS];
    char Names[MAXSTUDENTS][MAX];
    float Grades[MAXSTUDENTS][MAX];

    FILE *ifp, *ofp;
    ipf = fopen("student.txt", "r");
    opf = ("Graderesults.txt", "w");
    int name, courses;

    fscanf(ifp, "%d%d", &name, &courses);

    fprintf(ofp, "List of Students\n");

    for(int i = 0; i < name; i++)
    {
        fscanf(ifp, "%d%s%d%d%d", &ID[i], &Names[i]);

        for(int j = 0; j < courses; j++)
        {
            fscanf(ifp, "%f", &Grades[i][j]);
        }
    }


    return 0;
}