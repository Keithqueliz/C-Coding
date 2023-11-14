#include <stdio.h>
void getData(char arr[], int *n, int counters[26]);
void displayStat(int *c, int total_char);
void reverse(char a[], int size);
void char_swap(char *x, char *y);
void displayArr(char *a, int size);
#define MAXCHAR 50

int main() 
{
  int counters[26];
  char myArr[MAXCHAR]; //MAXCHAR was hash defined to 50
  int i, total_char;

  for(i=0; i<26; i++)
       counters[i] = 0;
 
  getData(myArr, &total_char, counters);
  displayArr(myArr, total_char);
  printf("\n");
  displayStat(counters, total_char);
  reverse(myArr, total_char);
  printf("Array reversed.\n");
  displayArr(myArr, total_char);

  return 0;
}

/*This function takes an empty array, reference to an integer, and an counters array. 
The function prompts the user on how many characters the user will input and put that number in the referenced variable pointed by n. */
void getData(char arr[], int *n, int counter[26])
{   
    int total;
    printf("How many characters? :");
    scanf("%d", &total);

    *n = total;

    for(int i = 0; i < *n; i++)
    {
        printf("Enter character %d: ", i + 1);
        scanf("%s", &arr[i]);

        int ch = arr[i];

        if(ch >= 'A' && ch <= 'Z')
        {
            ch = ch + 32;
        }

        if(ch >= 'a' && ch <= 'z')
        {
            counter[ch - 'a']++;
        }
    }
}

/* This function takes the counters array and displays the count 
and percentage of each letter in the alphabet*/
void displayStat(int *c, int total_char)
{   
    for(int i = 0; i < 26; i++)
    {   
        printf("%c %d %.2f\n", 'a' + i, c[i], (100.0 * c[i]) / total_char);
    }
}

/* This function takes a character array and the total number of elements in that array. 
Then the function reverses that array.*/
void reverse(char a[], int size)
{   
    int i = 0;

    for(; i < size / 2; i++)
    {
        char_swap(&a[i], &a[size - i - 1]);
    }
}

/* This function takes references to two-character variables, and swap them. 
You will use it during the reversing process. */
void char_swap(char *x, char *y)
{
    char temp;

    temp = *x;
    *x = *y;
    *y = temp;
}

// This function takes a character array and displays it.
void displayArr(char *a, int size)
{
    printf("The char array: ");

    for(int i = 0; i < size; i++)
    {
        printf("%c ", a[i]);
    }
}
