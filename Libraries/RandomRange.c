#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <time.h>
void distance(int x, int y, int r);

int main()
{
    int x, y, r;

    printf("Enter Center x, y coordinates and the radius of the cirle: ");
    scanf("%d%d%d", &x, &y, &r);

    distance(x, y, r);

    return 0;
}

void distance(int x, int y, int r)
{
    srand(time(0));

    int randX = 1 + rand()% (x + r + 3);
    int randY = 1 + rand()% (x + r + 3);

    printf("The generated coordinate is: (%d, %d)\n", randX, randY);

    double powX = pow((x - randX), 2);
    double powY = pow((y - randY), 2);
    double dis = sqrt(powX + powY);

    if(dis < r)
        printf("The point is inside the circle");
    else if(dis == r)
        printf("The point is on the circle");
    else
        printf("The point is outside the circle");

}