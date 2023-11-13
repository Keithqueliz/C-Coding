#include <stdio.h>
#define MAX 100

int main()
{
    FILE *inputf, *outputf;
    inputf = fopen("comment.txt", "r");
    outputf = fopen("commentout.txt", "w");

    char str[100];

    char ch = getc(inputf);

    while(ch != EOF)
    {   
        if(ch == '/*')
        {
            fscanf(inputf, "%c", &str);
        }

        fprintf(outputf, "%c", ch);
    }    

    fclose(inputf);
    fclose(outputf);

    return 0;
}