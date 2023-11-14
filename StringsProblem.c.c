#include <stdio.h>
#include <ctype.h>
#define MAX_LENGTH 101 //maximum string length will be 100 + 1 for '\0'

int getLength(char s[]);
int is_equal(char s1[], char s2[]);
void str_copy(char dest[], char source[]);
void str_reverse(char s[]);
int is_palindrome(char s[]);
void capitalize_word(char *str);
void swap(char *a, char *b);

int main()
{   
    char s1[MAX_LENGTH];
    char s2[MAX_LENGTH];
    char x;

    printf("Enter a string: ");
    scanf("%[^\n]s", s1);

    while((x = getchar() != '\n') && x != EOF); //loop to discard \n from last input and not to skip the next input

    printf("Enter another string: ");
    scanf("%[^\n]s", s2);

    printf("\nThe length of your first string is %d\n", getLength(s1));
    printf("The length of your second string is %d\n", getLength(s2));

    if(is_equal(s1, s2) == 1)
    {
        printf("You entered two equal strings.\n");
    }
    else
    {
        printf("Your strings are different.\n");
    }
    
    if(is_palindrome(s1))
    {
        printf("%s is a palindrome string\n", s1);
    }
    else
    {
        printf("%s is not a palindrome string\n", s1);

    }

    capitalize_word(s1);
    printf("Capitalized s1 is %s ", s1);

    return 0;
}

// this function takes a string and returns the length of the string
int getLength(char s[])
{
    int length = 0;

    // for loop will continue untill s[i] hits the terminator at '\0'
    for(int i = 0; s[i] != '\0'; i++)
    {
        length++;
    }

    return length;

}

// this function takes two strings and returns 1 if both strings contains exact same characters. Otherwise, it returns 0
int is_equal(char s1[], char s2[])
{   
    int i = 0;
    // while loop will continue as long as s1[i] and s2[i] are equal
    while(s1[i] == s2[i])
    {   
        // if they are not equal the loop will break and move on
        if(s1[i] == '\0' || s2[i] == '\0')
        break;

        else
            i++;
    }

    // confirms if strings are truly equal by comparing their terminator position
    if(s1[i] == '\0' && s2[i] == '\0')
        return 1;
    else
        return 0;
}
// This function takes two strings as parameters and copies the source string to the destination string.
void str_copy(char dest[], char source[])
{  
    for(int i = 0; source[i] != '\0'; i++)
    {
        dest[i] = source[i];
    }
    
    dest[getLength(source)] = '\0';
}

// This function takes a string in the parameter and reverses the string. 
void str_reverse(char s[])
{   
    int length = getLength(s) - 1;
    
    for(int i = 0; i < length / 2 - 1; i++)
    {   
        swap(&s[i], &s[length - i]);
    }

    s[getLength(s)] = '\0';
    
}

/* A string is known as palindrome if the reverse of the string is 
the same as the original string. You must have to utilize str_copy, 
str_reverse, and is_equal functions to make your decision in this function.*/
int is_palindrome(char s[])
{
    char copy[MAX_LENGTH];
    str_copy(copy, s);
    str_reverse(copy);
    return is_equal(s, copy);
}

/*This function takes a string and updates the first character of each word to 
upper case and the remaining characters to lower case.*/
void capitalize_word(char *str)
{
    for(int i = 0; str[i] != '\0'; i++)
    {   
        if(str[i] == ' ')
        {   
            i++;

            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
        }
        else if(i == 0)
        {
            if(str[i] >= 'a' && str[i] <= 'z')
            {
                str[i] -= 32;
            }
        }
        else if(str[i] >= 'A' && str[i] <= 'Z')
            {
                str[i] += 32;
            }
    }
}

// This function takes the references of two characters and swaps them
void swap(char *a, char *b)
{   
    char temp;

    temp = *a;
    *a = *b;
    *b = temp;
}