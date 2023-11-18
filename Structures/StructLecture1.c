#include <stdio.h>
#define MAX 50

// declare struct in gobal area of code
struct Book
{
    char title[MAX];
    char author[MAX];
    float price;
    float pages;

} b1, b2; // creates variables each containing book struct

int main()
{   
    char x;
    // Will save in the order inputed, Java book to title, Java author to author etc
    struct Book b3 = {"Java book", "Java author", 50.5, 200};
    printf("Details of b3:\n Title: %s Author: %s Pages: %.2f Price: %.2f\n", b3.title, b3.author, b3.pages, b3.price);

    struct Book b4;
    printf("Enter title for b4: ");
    scanf("%[^\n]s", b4.title);

    while((x = getchar() != '\n') && x != EOF);

        printf("Enter author for b4: ");
        scanf("%[^\n]s", b4.author);
        printf("Enter price for b4: ");
        scanf("%f", &b4.price);
        printf("Enter pages for b4: ");
        scanf("%f", &b4.pages); 

    printf("Details of b3:\n Title: %s Author: %s Pages: %.2f Price: %.2f\n", b4.title, b4.author, b4.pages, b4.price);



    return 0;
}