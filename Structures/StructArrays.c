
#include <stdio.h>
#include <string.h>

#define MAX 100

// declare struct in gobal area of code, using book as the type
typedef struct Book
{
    char title[MAX];
    char author[MAX];
    float price;
    float pages;

} Book; // book is a type that can declare variables for struct

int main()
{   
    // Array of struct will store 100 Book struct
    Book books[MAX];
    int n, x;
    printf("How many books do you want: ");
    scanf("%d", &n);

    // Use loop to add information to each struct in the array
    for(int i = 0; i < n; i++)
    {
        while((x = getchar() != '\n') && x != EOF);

        printf("Enter the title of the book #%d: ", i+1);
        scanf("%[^\n]s", books[i].title);

        while((x = getchar() != '\n') && x != EOF);
            
        printf("Enter the author of the book #%d: ", i+1);
        scanf("%[^\n]s", books[i].author);


        printf("Enter the price & pages for book #%d: ", i+1);
        scanf("%f %f", &books[i].price, &books[i].pages);
        printf("======\n");
    }

    printf("Your bookshelf:\n");
    for(int i = 0; i < n; i++)
    {
        printf("Book #%d: ", i+1);
        printf("%s %s, %.2f %.0f\n", books[i].title, books[i].author, books[i].price, books[i].pages);
        printf("======\n");
    }

    int count = 0;
    char search[MAX];

    while((x = getchar() != '\n') && x != EOF);

    printf("Enter an author to search for: ");
    scanf("%[^\n]s", search);

    for(int i = 0; i < n; i++)
    {
        if(strcmp(search, books[i].author) == 0)
        {
            printf("%s %s %.2f %f\n", books[i].title, books[i].author, books[i].price, books[i].pages);
            count++;
        }
    }

    if(count == 0)
    {
        printf("No books found by this author.\n");
    }

    return 0;
}

