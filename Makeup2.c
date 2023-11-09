#include <stdio.h>
void printPattern(int maxLetter);

int main() {
    int maxLetter;
    printf("Enter the max letter count: ");
    scanf("%d", &maxLetter);

    printPattern(maxLetter);

    return 0;
}

void printPattern(int maxLetter) {
    
    char currentChar = 'A';
    int spaces = maxLetter;

    for (int i = 1; i <= maxLetter; i++) {
        // Print letters to the left of center
        for (int j = maxLetter; j > i; j--) {
            printf("%c", currentChar);
            currentChar++;
        }

        // Print spaces
        for (int k = 3; k <= i * 2; k++) {
            printf(" ");
        }
        

        // Print letters to the right of center
        if (i < maxLetter) {
            currentChar--;
            for (int l = maxLetter; l > i; l--) {
                printf("%c", currentChar);
                currentChar--;
            }
            currentChar = 'A';
        }

        spaces--;
        printf("\n");
    }
}