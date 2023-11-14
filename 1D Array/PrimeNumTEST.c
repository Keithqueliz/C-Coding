#include <stdio.h>
#define SIZE 200
void PrimeMatching(int arrayN[], int n, int arrayM[], int m);
int isPrime(int prime);
void SmallestandLargest(int arrayM[], int m);

int main()
{
    // asking user for n and m
    int n, m;
    int arrayN[SIZE], arrayM[SIZE];

    printf("Enter n and m: ");
    scanf("%d%d", &n, &m);

    int i, listN, listM;
    //creating for loop to save vales into arrays
    printf("Enter data for first list: ");
    for(i = 0; i < n; i++)
    {
        scanf("%d", &listN);
        arrayN[i] = listN;
    }

    printf("Enter data for second list: ");
    for(i = 0; i < m; i++)
    {
        scanf("%d", &listM);
        arrayM[i] = listM;
    }
    //calls both functions needed
    PrimeMatching(arrayN, n, arrayM, m);
    SmallestandLargest(arrayM, m);

    return 0;
}
// function will determine if value passed is a prime number and return a '1' or '0'
int isPrime(int prime)
{
    int i;
    int primeNum = 1;
    // the for loop starts at 2 as prime numbers do not include 1
    for(i = 2; i < prime; i ++)
    {
        if(prime%i == 0)
            primeNum = 0;
    }
    return primeNum;
}
// function will take two arrays, run the second array within the first one to compare values
// Once a common number is found, it will be inputed into the isPrime funtion
void PrimeMatching(int arrayN[], int n, int arrayM[], int m)
{
    int index, key, primeNum = 0;
    int common_count = 0;

    printf("Common prime numbers are: ");
    // first for loop runs, then second loop will run till complete in order to locate common values 
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j ++)
        {
            if(arrayM[j] == arrayN[i])
            {
                primeNum = isPrime(arrayN[i]);
                if(primeNum == 1)
                {   
                    // key is used to prevent double counting of common numbers
                    if(arrayN[i] != key)
                    {
                        // the common count will increase by one, while it prints the value
                        common_count++;
                        printf("%d ", arrayN[i]);
                        key = arrayN[i];
                    }
                }
            }
        }

    }

    printf("\nCommon count: %d\n", common_count);
}
// function will find the smallest and largest values by comparing values from index[0]
void SmallestandLargest(int arrayM[], int m)
{
    int i;
    int smallest = arrayM[0], largest = arrayM[0];

    for(i = 0; i < m; i ++)
    {
        if(arrayM[i] > largest)
            largest = arrayM[i];
        else if(arrayM[i] < smallest)
            smallest = arrayM[i];
    }

    printf("Smallest number in the second list: %d\n", smallest);
    printf("Largest number in the second list: %d\n", largest);
}