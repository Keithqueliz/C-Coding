#include <stdio.h>
#define ROWS 10
#define COLUMNS 10
void FillData(int Array[ROWS][COLUMNS], int r, int c);
void Display(int Array[ROWS][COLUMNS], int r, int c);
void Multiply(int Matrix1[ROWS][COLUMNS], int r1, int c1, int Matrix2[ROWS][COLUMNS], int r2, int c2);

int main()
{
    int Matrix1[ROWS][COLUMNS];
    int Matrix2[ROWS][COLUMNS];
    int r1, c1, r2, c2;

    // asks for row and collumn input then calls FillData Function
    printf("Working for Matrix 1\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r1, &c1);
    FillData(Matrix1, r1, c1);

    // asks for row and collumn input then calls FillData Function
    printf("Working for Matrix 2\n");
    printf("Enter the number of rows and columns: ");
    scanf("%d%d", &r2, &c2);
    FillData(Matrix2, r2, c2);

    // calls and displays both matrixs 
    printf("Displaying Matrix 1:\n");
    Display(Matrix1, r1, c1);

    printf("Displaying Matrix 2:\n");
    Display(Matrix2, r2, c2);
    
    Multiply(Matrix1, r1, c1, Matrix2, r2, c2);
    
    return 0;
}

// function will take input for the matrix
void FillData(int Array[ROWS][COLUMNS], int r, int c)
{   
    printf("Enter data for %dx%d maxtrix: ", r, c);
    
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }
}
// will loop through and print the values in each matrix called
void Display(int Array[ROWS][COLUMNS], int r, int c)
{
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {
            printf("%d\t", Array[i][j]);
        }
        printf("\n");
    }
}

void Multiply(int Matrix1[ROWS][COLUMNS], int r1, int c1, int Matrix2[ROWS][COLUMNS], int r2, int c2)
{
    // the function will check if r1 is equal to c2 as it cannot multiply if c2 is longer
    if(r1 != c2)
    {
        printf("Not valid dimensions for multiplication");
        return;
    }
    // creating new matrix to hold new values
    int Product[ROWS][COLUMNS];

    // loops through the rows in Matrix1
    for(int i = 0; i < r1; i ++)
    {   
        // loops through the columns in matrix2
        for(int j = 0; j < c2; j++)
        {
            Product[i][j] = 0;
            // loops to add each value from both matrixs into Product
            for(int k = 0; k < c1; k++)
            {
                Product[i][j] += Matrix1[i][k] * Matrix2[k][j];
            }
        }
    }

    printf("Displaying Result Matrix:\n");
    
    Display(Product, r1, c2);
}