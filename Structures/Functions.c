#include <stdio.h>
#include <string.h>

#define MAX 100

// declare struct in gobal area of code, using book as the type
typedef struct Book
{
    char title[MAX];
    char author[MAX];
    float price;
    int pages;

} Book; // book is a type that can declare variables for struct

// first way of passing struct to function
void printv1(char *t, char *a, float price, int pages)
{
    printf("%s %s %.2f %d\n", t, a , price, pages);
}

// Second version using pass by value
void printV2(Book b) 
{
    printf("%s %s %.2f %d\n", b.title, b.author, b.price, b.pages);
}

// function to return book
Book getBook()
{
    Book b2 = {"A book", "A author", 30.5, 200};
    return b2;
}

void Increaseprice(Book *b)
{
    b -> price += 100;
}

int main()
{   
    Book b = getBook();
    printV2(b);

    Increaseprice(&b);
    printV2(b);

    // Size of tells the size in bytes of the struct size
    printf("Size of a book is %lu\n", sizeof(b));

    // You can delcare struct contents like array
    Book b1 = {"C book", "C author", 30.5, 200};

    printv1(b1.title, b1.author, b1.price, b1.pages);
    printV2(b1);

    return 0;
}

