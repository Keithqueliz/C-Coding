#include <stdio.h>
#define MAXROW 100
#define MAXCOLUMN 100
void printLLTriangle(int Array[MAXROW][MAXCOLUMN], int r, int c);
void displayMatrix(int Array[MAXROW][MAXCOLUMN], int r, int c);
void findMaxPerRow(int Array[MAXROW][MAXCOLUMN], int r, int c);
void inputMatrix(int Array[MAXROW][MAXCOLUMN], int r, int c, int count);
void printURTriangle(int Array[MAXROW][MAXCOLUMN], int r, int c);
void printLLTriangle(int Array[MAXROW][MAXCOLUMN], int r, int c);
void addMatrix(int Matrix1[MAXROW][MAXCOLUMN], int Matrix2[MAXROW][MAXCOLUMN], int resultMatrix[MAXROW][MAXCOLUMN], int r, int c);
int sumSurrounding(int Array[MAXROW][MAXCOLUMN], int r, int c, int i, int j);

int main()
{   
    int r, c;
    int Matrix1[MAXROW][MAXCOLUMN];
    int Matrix2[MAXROW][MAXCOLUMN];
    int resultMatrix[MAXROW][MAXCOLUMN];

    // asks user for the number of rows and columns for both matrixs
    printf("Enter number of rows and columns: ");
    scanf("%d%d", &r, &c);

    // calls input function to add values for matrix 1
    int count = 1;
    printf("Input for matrix 1: \n");
    inputMatrix(Matrix1, r, c, count);

    // calls input function again to add values for matrix 2
    count++;
    printf("Input for matrix 2: \n");
    inputMatrix(Matrix2, r, c, count);

    // calls functions twice to print matrix 1 & 2
    printf("\nprinting matrix 1:\n");
    displayMatrix(Matrix1, r, c);
    printf("printing matrix 2:\n");
    displayMatrix(Matrix2, r, c);

    // calls the remaining functions that will print from the function itself
    findMaxPerRow(Matrix1, r, c);
    printLLTriangle(Matrix1, r, c);
    printURTriangle(Matrix1, r, c);
    addMatrix(Matrix1, Matrix2, resultMatrix, r, c);

    // prints the results from the add matrix function
    printf("\nmatrix 1 + matrix 2 is:\n");
    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)\
        {
            printf("%4d", resultMatrix[i][j]);
        }

        printf("\n");
    }

    int i, j;
    // loop to continue to take input for i & j while it is not less than 0
    while(i >= 0 && j >= 00)
    {   
        int sum;

        printf("enter i and j for calculating sum of surrounding:\n");
        scanf("%d%d", &i, &j);

        if(i < 0 || j < 0)
        {
            printf("Exit\n");
        }
        else
        {
            sum = sumSurrounding(Matrix1, r, c, i, j);
            printf("sum of surrounding is %d\n", sum);
        }
    }

    return 0;
}

// function will take the input for a matrix using nested loops
void inputMatrix(int Array[MAXROW][MAXCOLUMN], int r, int c, int count)
{   
    int data;
    for(int i = 0; i < r; i++)
    {   
        printf("data for matrix%d[%d][0] to matrix%d[%d][%d] ", count, i, count, i, c - 1);
        for(int j = 0; j < c; j++)
        {
            scanf("%d", &data);
            Array[i][j] = data;
        }
    }
}
// This function takes a 2D array, number of rows, and number of columns as a parameter, then prints the matrix in a well-formatted way.
void displayMatrix(int Array[MAXROW][MAXCOLUMN], int r, int c)
{
	for(int i = 0; i < r; i++ )
	{
		for(int j = 0; j < c; j++)
		{
			printf("%4d", Array[i][j]);
		}

        printf("\n");
	}
} 
/* function will set a 'max' at any point within the function (0.0), then compare every value and if
it locates a larger value it will save it under 'max' until another value is found to be larger*/
void findMaxPerRow(int Array[MAXROW][MAXCOLUMN], int r, int c)
{   
    int max = Array[0][0];

    printf("\nprinting max per row for matrix 1:\n");

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {   // if the (i,j) values is larger it will be saved for later
            if(Array[i][j] > max)
            {
                max = Array[i][j];
            }
        }
        
        printf("max of row %d is %d\n", i, max);

        max = 0;
    }
}
// then prints the upper right triangle numbers and display the remaining numbers as zero
void printURTriangle(int Array[MAXROW][MAXCOLUMN], int r, int c)
{   
    printf("\nprinting upper right triangle for matrix 1:\n");

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j ++)
        {
            // if i is <= it will print as the value is in the upper right, if not it will print 0
            if(i <= j)
            {
                printf("%4d", Array[i][j]);
            }
            else
                printf("%4d", 0);
        }

        printf("\n");
    }
}
 // prints the lower-left triangle numbers and display the remaining numbers as zero
void printLLTriangle(int Array[MAXROW][MAXCOLUMN], int r, int c)
{   
    printf("\nprinting lower left triangle of matrix 1:\n");

    for(int i = 0; i < r; i ++)
    {
        for(int j = 0; j < c; j++)
        {   // if i is >= j, it means the value falls under the lower left triangle, if its over, it will print 0
            if(i >= j)
            {
                printf("%4d", Array[i][j]);
            }
            else    
            printf("%4d", 0);
        }

        printf("\n");
    }
}
// the function adds the first two matrix and stores the result in the third matrix.
void addMatrix(int Matrix1[MAXROW][MAXCOLUMN], int Matrix2[MAXROW][MAXCOLUMN], int resultMatrix[MAXROW][MAXCOLUMN], int r, int c)
{
    int result;

    for(int i = 0; i < r; i++)
    {
        for(int j = 0; j < c; j++)
        {   // saves Matrix 1 + 2 into result
            result = Matrix1[i][j] + Matrix2[i][j];
            // saves result into the i, j of the result matrix
            resultMatrix[i][j] = result;
        }
    }
}
// the function sum-up all the adjacent numbers of position [i][j] and returns the result
int sumSurrounding(int Array[MAXROW][MAXCOLUMN], int r, int c, int i, int j)
{
   int sum = 0;
    // loops through the matrix rows and collumns, around the i, j 
    for(int x = i - 1; x <= i + 1; x++)
    {
        for(int y = j - 1; y <= j + 1; y++)
        {   // to not count the i,j point, if the value of x and y is equal to those of i and j it will be skipped
            if (x >= 0 && x < r && y >= 0 && y < c && !(x == i && y == j))
            {
                sum += Array[x][y];
            }
        }
    }
    
    return sum;
}