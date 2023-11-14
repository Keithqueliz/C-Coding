#include <stdio.h>
#include <ctype.h>
#include <string.h>
#define MAX 30

int main()
{   
    // opens file and creates the output file
    FILE *input, *output;
    input = fopen("input.txt", "r");
    output = fopen("output.txt", "w");
    char in[MAX], out[MAX];

    // ints to count the # of chars, digits and vowels
    int charCounter = 0, digits = 0, vowels = 0;

    // begin by taking the first character of the file
    char ch;
    ch = fgetc(input);

    // loop untill the ch is at the EOF
    for(int i = 0; ch != EOF ; i++)
    {   
        // converts ch into Upper case to pass the test cases
        ch = toupper(ch);

        // if ch is not a newline it will be counted in the charcounter
        if(ch != '\n')
        {
            charCounter++;
        } 
        // tests if ch is equal to any upper case vowels
        if(ch == 'A' || ch == 'E' || ch == 'I' || ch == 'O' || ch == 'U')
        {
            vowels++;
        }
        // tests if ch is a digit
        if(isdigit(ch) == 1)
        {
            digits++;
        }
        // finally ch is put into the output file then printed, then the next character is saved into ch
        fputc(ch, output);
        printf("%c", ch);
        ch = fgetc(input);
    }

    printf("\nNumber of characters: %d\n", charCounter);
    printf("Number of vowels: %d\n", vowels);
    printf("Number of digits: %d\n", digits);

    // closes both files 
    fclose(input);
    fclose(output);

    return 0;
}