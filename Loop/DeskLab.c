#include <stdio.h>
#include <math.h>
#include <stdlib.h>
int sizeCheck(int lRoom, int wRoom, int lDesk, int wDesk);

int main()
{
    int lRoom, wRoom, lDesk, wDesk;

    printf("Enter the length and width of the room: ");
    scanf("%d%d", &lRoom, &wRoom);
    printf("Enter the length and width of the desk: ");
    scanf("%d%d", &lDesk, &wDesk);

    int check = sizeCheck(lRoom, wRoom, lDesk, wDesk);

    if(check == 1)
        printf("The desk will fit in the room.");
    else 
        printf("The desk will not fit in the room.");

    return 0;
}

int sizeCheck(int lRoom, int wRoom, int lDesk, int wDesk)
{
    if(lDesk <= lRoom || lDesk <= wRoom)
    {
        if(wDesk <= wRoom || wDesk <= lRoom)
             return 1;
    }
    
    else
        return 0;

}
