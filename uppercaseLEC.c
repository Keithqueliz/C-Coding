#include <stdio.h>
#define MAX 50
char changeChar(char ch);
void makeUpper(char *s);

int main()
{   
    char str[MAX + 1];

    printf("Enter a string: ");
    scanf("%[^\n]s", str);

    makeUpper(str);

    printf("The string in upper case is: %s", str);

    return 0;
}

void makeUpper(char *s)
{
    for(int i = 0; s[i]!= '\0'; i++)
    {
        s[i] = changeChar(s[i]);
    }


}

char changeChar(char ch)
{
    if(ch >= 'a' && ch <= 'z')
    {
        return ch - 32;
    }
    else
        return ch;
}