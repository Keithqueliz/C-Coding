#include <stdio.h>
#include <string.h>

#define MAX 100

typedef struct employee
{
    char name[MAX];
    float salary;
    int ID;
}employee;

void getData(employee *p)
{   
    // how to take input using pointer must use & for int or float
    scanf("%s %f %d", p->name, &(p->salary), &(p->ID));
}

void printV2(employee *b) 
{
    printf("%s %.2f %d\n", b->name, b->salary, b->ID);
}

int main()
{   
    employee Test;
    getData(&Test);
    printV2(&Test);

    employee officeworker;
    // Pointer of employee structure
    employee *temp;
    // store the address of the officeworker struct
    temp = &officeworker;
    // Dereferences temp to access salary of office worker **MUST use ()**
    (*temp).salary = 5000;
    // Another way to dereference pointer is using ->
    temp -> salary = 5000;

    
    return 0;
}