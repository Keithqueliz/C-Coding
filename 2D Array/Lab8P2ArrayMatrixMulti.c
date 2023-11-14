#include <stdio.h>

#define MAXROW 10
#define MAXCOL 10

void fillData(int array[MAXROW][MAXCOL], int *row, int *col);
void Display(int array[MAXROW][MAXCOL], int *row, int *col);
void Multiply(int array1[MAXROW][MAXCOL], int *row1, int *col1, int array2[MAXROW][MAXCOL], int *row2, int *col2);

int main()
{
    int array1[MAXROW][MAXCOL];
    int array2[MAXROW][MAXCOL];
    int row1, row2, col1, col2;

    printf("Working on Matrix 1\n");
    fillData(array1, &row1, &col1);

    printf("Working on Matrix 2\n");
    fillData(array2, &row2, &col2);

    printf("Displaying Matrix 1:\n");
    Display(array1, &row1, &col1);

    printf("Displaying Matrix 2:\n");
    Display(array2, &row2, &col2);

    printf("Displaying Result Matrix:\n");
    Multiply(array1, &row1, &col1, array2, &row2, &col2);

    return 0;
}

void fillData(int array[MAXROW][MAXCOL], int *row, int *col)
{
    printf("Enter number of rows and columns: ");
    scanf("%d%d", row, col);
    printf("Enter data for %dx%d matrix:\n", *row, *col);

    for(int i = 0; i < *row; i++)
    {
        for(int j = 0; j < *col; j++)
        {
            scanf("%d", &array[i][j]);
        }
    }
}

void Display(int array[MAXROW][MAXCOL], int *row, int *col)
{
    for(int i = 0; i < *row; i++)
    {
        for(int j = 0; j < *col; j++)
        {
            printf("%d\t", array[i][j]);
        }

        printf("\n");
    }
}

void Multiply(int array1[MAXROW][MAXCOL], int *row1, int *col1, int array2[MAXROW][MAXCOL], int *row2, int *col2)
{   
    if(*row1 == *col2)
    {
        int product[MAXROW][MAXCOL];
        int sum = 0;

        // loop while go through the rows of row1
        for(int i = 0; i < *row1; i++)
        {   
            // loop goes through the columns of col2
            for(int j = 0; j < *col2; j++)
            {   
                // loop will go through either co1 or row1 since they should be equal
                for(int k = 0; k < *col1; k++)
                {
                    sum += array1[i][k] * array2[k][j];
                }

                product[i][j] = sum;
                sum = 0;
            }
         }

         Display(product, row1, col2);
    }

    else
    {
        printf("Not valid dimensions for multiplication\n");
    }
}