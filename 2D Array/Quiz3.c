#include <stdio.h>
#define NOE 5
#define NOP 3

// Searches and displays all ID and salaries in the dep, then the total for all salaries
void searchDisplay(int emp[NOE][NOP], int dno)
{
    int totalSal = 0;

    for(int i = 0; i < NOE; i++)
    {
        for(int j = 0; j < NOP; j++)
        {
            if(emp[i][j] == dno)
            {   
                printf("The employee %d has a salary of $%d \n", emp[i][j - 1], emp[i][j + 1]);
                totalSal += emp[i][j + 1];
            }
        }
    }

    printf("The total salary for all employees is %d", totalSal);
}

int main()
{   
    int emp[NOE][NOP];
    int dno;

    for(int i = 0; i < NOE; i++)
    {   
        printf("Enter the ID, department, and salary for the employee:\n");

        for(int j = 0; j < NOP; j++)
        {
            scanf("%d", &emp[i][j]);
        }
    }

    printf("Enter a department nunber to search: ");
    scanf("%d", &dno);

    searchDisplay(emp, dno);

    return 0;
}