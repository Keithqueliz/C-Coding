#include <stdio.h>
#include <string.h>

#define MAX 50

// declare struct in gobal area of code, using book as the type
typedef struct Book
{
    char title[MAX];
    char author[MAX];
    float price;
    float pages;

} book; // book is a type that can declare variables for struct

int main()
{   
    char x;
    // Will save in the order inputed, Java book to title, Java author to author etc
    book b3 = {"Java book", "Java author", 50.5, 200};
    printf("Details of b3:\n Title: %s Author: %s Pages: %.2f Price: %.2f\n", b3.title, b3.author, b3.pages, b3.price);

    book b4;
    printf("Enter title for b4: ");
    scanf("%[^\n]s", b4.title);

    // use while loop get char to ensure inputs do not include new lines
    while((x = getchar() != '\n') && x != EOF);

        printf("Enter author for b4: ");
        scanf("%[^\n]s", b4.author);
        printf("Enter price for b4: ");
        scanf("%f", &b4.price);
        printf("Enter pages for b4: ");
        scanf("%f", &b4.pages); 

    // In order to change the String values, use strcpy
    strcpy(b4.title, b3.title);
    strcpy(b4.author, "New Java author");
    b4.price = 200.5;

    printf("Details of b4:\n Title: %s Author: %s Pages: %.2f Price: %.2f\n", b4.title, b4.author, b4.pages, b4.price);

    // Can copy contents of a struct, it will be a copy not a reference
    b1 = b4;
    printf("Details of b1:\n Title: %s Author: %s Pages: %.2f Price: %.2f\n", b1.title, b1.author, b1.pages, b1.price);

    return 0;
}