#include <stdio.h>
#define SIZE 200
void dataInput(int Array[SIZE], int x);
int isPrime(int prime);
void PrimeMatching(int Array1[SIZE], int size1, int Array2[SIZE], int size2);
void smallestNum(int Array[SIZE], int x);
void largestNum(int Array[SIZE], int x);

int main()
{
    int ArrayN[SIZE];
    int ArrayM[SIZE];
    int n, m;

    printf("Enter n and m: ");
    scanf("%d%d", &n, &m);

    printf("Enter data for first list: ");
    dataInput(ArrayN, n);

    printf("Enter data for second list: ");
    dataInput(ArrayM, m);
    PrimeMatching(ArrayN, n, ArrayM, m);
    smallestNum(ArrayM, m);
    largestNum(ArrayM, m);

    return 0;
}

void dataInput(int Array[SIZE], int x)
{
    for(int i = 0; i < x; i++)
    {
        scanf("%d", &Array[i]);
    }
}

int isPrime(int prime)
{
    int test = 1;

    for(int i = 2; i < prime; i++)
    {
        if(prime % i == 0)
        {
            test = 0;
        }
    }   

    return test;
}

void PrimeMatching(int Array1[SIZE], int size1, int Array2[SIZE], int size2)
{
    int count = 0;

    printf("Common prime numbers are: ");

    for(int i = 0; i < size1; i++)
    {   
        if(isPrime(Array1[i]) == 1)
        {
            for(int j = 0; j < size2; j++)
            {
                if(Array1[i] == Array2[j])
                {   
                    printf("%d ", Array2[j]);
                    count++;
                    break;
                }
            }
        }
    }

    printf("\nCommon count is: %d\n", count);

}

void smallestNum(int Array[SIZE], int x)
{
    int smallest = Array[0];

    for(int i = 0; i < x; i++)
    {
        if(Array[i] < smallest)
        {
            smallest = Array[i];
        }
    }

    printf("Smallest number in second list is: %d\n", smallest);
}

void largestNum(int Array[SIZE], int x)
{
    int largest = Array[0];

    for(int i = 0; i < x; i++)
    {
        if(Array[i] > largest)
        {
            largest = Array[i];
        }
    }

    printf("Largest number in second list is: %d\n", largest);
}