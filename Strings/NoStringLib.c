#include <stdio.h>
#include <string.h>

#define MAX 100

int lengthFunction(char *str)
{
    int length = 0;

    for(int i = 0; str[i] != '\0'; i++)
    {
        length++;
    }

    printf("The lenght of the string is %d\n", length);

    return length;
}

void compareString(char *str1, char *str2)
{
    int i = 0;
    while(str1[i] != '\0' || str2[i] != '\0')
    {
        if(str1[i] == str2[i])
        {
            i++;
        }
        else
            break;
    }

    if(str1[i] == '\0' & str2[i] == '\0')
    {
        printf("Both strings are the same\n");
    }
    else
    {
        printf("Strings are different\n");
    }
}

void stringLower(char *str)
{   
    for(int i = 0; str[i] != '\0'; i ++)
    {
        if(str[i] >= 'A' & str[i] <= 'Z')
        {
            str[i] = str[i] + 32;
        }
    }
}

void stringCopy(char *from, char *to)
{   
    int i;

    for(i = 0; from[i] != '\0'; i++)
    {
        to[i] = from[i];
    }

    to[i + 1] = '\0';
    printf("The copy of your string is %s\n", to);
}

void reverseString(char *str, int length)
{   
    char temp[MAX];

    temp[length] = '\0';
    for(int i = 0; i < length; i++)
    {   
        temp[length - 1 - i] = str[i];
    }

    printf("The reverse of your string is %s\n", temp);
}

int main()
{   
    char str1[MAX], str2[MAX];
    printf("Enter your name: ");
    scanf("%[^\n]s", str1);
    printf("Your name is %s \n", str1);

    char x;
    while((x = getchar()) != '\n' & x != EOF);

    printf("Enter another name to compare: ");
    scanf("%[^\n]s", str2);

    stringLower(str1);
    stringLower(str2);
    int lenght = lengthFunction(str1);
    compareString(str1, str2);

    char str3[MAX];
    stringCopy(str1, str3);

    reverseString(str1, lenght);

    return 0;
}