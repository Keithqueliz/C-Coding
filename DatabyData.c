#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#define MAX 500

int main()
{   
    int std_id, g1, g2, g3;
    char name[50];
    int IDS[MAX];
    char Names[MAX][MAX];
    float Grades[MAX][MAX];

    FILE *ifp, *ofp;
    char outputfile[10] = "result.txt";
    ifp = fopen("student.txt", "r");
    ofp = fopen(outputfile, "w");

    int numofs; 
    fscanf(ifp, "%d", &numofs);

    fprintf(ofp, "Grade summary:\n");
    for(int i = 0; i < numofs; i++)
    {
        fscanf(ifp, "%d%s%f%f%f\n", &IDS[i], Names[i], &Grades[i][0], &Grades[i][1], &Grades[i][2]);

        fprintf(ofp, "%d %.2f\n", IDS[i], (Grades[i][0] + Grades[i][1] + Grades[i][2])/3.0);
    }


    fclose(ifp); 
    fclose(ofp);

    return 0;
}