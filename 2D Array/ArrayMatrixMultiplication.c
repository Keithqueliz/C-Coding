#include <stdio.h>
#define ROWS 10
#define COLUMNS 10
void FillData(int Array[ROWS][COLUMNS], int *row, int *col);
void Display(int Array[ROWS][COLUMNS], int row, int col);

int main()
{
    int Array1[ROWS][COLUMNS];
    int Array2[ROWS][COLUMNS];
    int row1, col1;
    int row2, col2;

    printf("Working for Matrix 1\n");
    FillData(Array1, &row1, &col1);

    printf("Working for Matrix 2\n");
    FillData(Array2, &row2, &col2);

    printf("Displaying Matrix 1:\n");
    Display(Array1, row1, col1);

    printf("\nDisplaying Matrix 2:\n");
    Display(Array2, row2, col2);

    return 0;
}

void FillData(int Array[ROWS][COLUMNS], int *row, int *col)
{   
    printf("Enter number of rows and columns: ");
    scanf("%d%d", row, col);
    printf("Enter data for %d*%d matrix: ", *row, *col);

    for(int i = 0; i < *row; i++)
    {
        for(int j = 0; j < *col; j++)
        {
            scanf("%d", &Array[i][j]);
        }
    }
}

void Display(int Array[ROWS][COLUMNS], int row, int col)
{
    for(int i = 0; i < row; i++)
    {
        for(int j = 0; j < col; j++)
        {
            printf("%4d", Array[i][j]);
        }

        printf("\n");
    }
}

void Multiply(int Array1[ROWS][COLUMNS], int row1, int col1, int Array2[ROWS][COLUMNS], int row2, int col2)
{
    int Sum[ROWS][COLUMNS];

    for(int i = 0; i < )
}