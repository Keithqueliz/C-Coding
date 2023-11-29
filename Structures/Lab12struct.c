#include <stdio.h>
#include <string.h>

#define MAX 50

// Define Employee structure
typedef struct Employee
{
    char ID[20];
    char Name[100];
    int Salary;

} Employee;

// Define Dept structure
typedef struct Dept
{
    char ID[20];
    char DeptName[100];

} Dept;

// Define Query structure
typedef struct Query
{
    int Key;
    char QContents[MAX];

} Query;

// Function to read employee data from a file
int readEmp(Employee ArrayOfEmployees[], char empFileName[]);

// Function to read department data from a file
void readDept(Dept ArrayOfDepartments[], int *numOfDept, char depetFileName[]);

// Function to print details of all employees and their departments
void printAll(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept);

// Function to search for an employee based on a query
void search_employee(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[]);

// Function to calculate the total salary of a department based on a query
int totalSal_dept(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[]);

// Function to read queries from a file
int readQuery(Query Q[], FILE *QFile);

int main()
{
    char EmpFile[MAX], Deptfile[MAX], Queryfile[MAX];
    Employee EmpArray[MAX];
    Dept DeptArray[MAX];
    int NumEmp = 0, NumDept = 0;

    // Get file names from user input
    scanf("%s%s%s", EmpFile, Deptfile, Queryfile);

    // Read employee and department data from files
    NumEmp = readEmp(EmpArray, EmpFile);
    readDept(DeptArray, &NumDept, Deptfile);

    // Print details of all employees and their departments
    printAll(EmpArray, NumEmp, DeptArray, NumDept);

    printf("Query Phase\n");

    // Process queries
    search_employee(EmpArray, NumEmp, DeptArray, NumDept, Queryfile);

    return 0;
}

// Function to read employee data from a file
int readEmp(Employee ArrayOfEmployees[], char empFileName[])
{
    FILE *EFile;
    EFile = fopen(empFileName, "r");

    int i = 0;

    while (fscanf(EFile, "%s %s %d", ArrayOfEmployees[i].ID, ArrayOfEmployees[i].Name, &ArrayOfEmployees[i].Salary) != EOF)
    {
        i++;
    }

    return i;
}

// Function to read department data from a file
void readDept(Dept ArrayOfDepartments[], int *numOfDept, char depetFileName[])
{
    FILE *DFile;
    DFile = fopen(depetFileName, "r");

    int i = 0;
    while (fscanf(DFile, "%s %s", ArrayOfDepartments[i].ID, ArrayOfDepartments[i].DeptName) != EOF)
    {
        i++;
    }

    *numOfDept = i;
}

// Function to print details of all employees and their departments
void printAll(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept)
{
    printf("Printing the list of Employees:\n");
    printf("=================\n");

    for (int i = 0; i < totalEmp; i++)
    {
        int found = 0;

        printf("ID: %s LName: %s Salary: %d ", Arr[i].ID, Arr[i].Name, Arr[i].Salary);

        for (int j = 0; j < totalDept; j++)
        {
            if (strcmp(Arr[i].ID, ArrayOfDepartments[j].ID) == 0)
            {
                printf("Department: %s\n", ArrayOfDepartments[j].DeptName);
                found++;
            }
        }

        if (found == 0)
        {
            printf("Department: None\n");
        }
    }
}

// Function to search for an employee based on a query
void search_employee(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[])
{
    FILE *QFile;
    QFile = fopen(qStr, "r");
    Query Q[MAX];
    int N = readQuery(Q, QFile);

    for (int i = 0; i < N; i++)
    {
        if (Q[i].Key == 1)
        {
            int foundemp = 0;

            for (int j = 0; j < totalEmp; j++)
            {
                if (strcmp(Q[i].QContents, Arr[j].Name) == 0)
                {
                    printf("ID: %s LName: %s Salary: %d Department: %s\n", Arr[j].ID, Arr[j].Name, Arr[j].Salary, ArrayOfDepartments[j].DeptName);
                    foundemp++;
                }
            }

            if (foundemp == 0)
            {
                printf("Employee %s Not Found\n", Q[i].QContents);
            }
        }

        if (Q[i].Key == 2)
        {
            int total = totalSal_dept(Arr, totalEmp, ArrayOfDepartments, totalDept, Q[i].QContents);
            printf("Total salary of Department %s is %d\n", Q[i].QContents, total);
        }
    }
}

// Function to calculate the total salary of a department based on a query
int totalSal_dept(Employee Arr[], int totalEmp, Dept ArrayOfDepartments[], int totalDept, char qStr[])
{
    int totalsal = 0;

    for (int i = 0; i < totalDept; i++)
    {
        if (strcmp(qStr, ArrayOfDepartments[i].DeptName) == 0)
        {
            for (int j = 0; j < totalEmp; j++)
            {
                if (strcmp(Arr[j].ID, ArrayOfDepartments[i].ID) == 0)
                {
                    totalsal += Arr[j].Salary;
                }
            }
        }
    }

    return totalsal;
}

// Function to read queries from a file
int readQuery(Query Q[], FILE *QFile)
{
    int N;
    fscanf(QFile, "%d", &N);

    for (int i = 0; i < N; i++)
    {
        fscanf(QFile, "%d%s", &Q[i].Key, Q[i].QContents);
    }

    return N;
}
