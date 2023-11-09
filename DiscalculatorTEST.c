#include <stdio.h>
#include <math.h>

int main()
{
    double x1, y1, x2, y2;

    printf("Enter the location for point one: ");
    scanf("%lf%lf", &x1, &y1);
    printf("Enter the location for point two: ");
    scanf("%lf%lf", &x2, &y2);

    double diffx = x1 - x2;
    double diffy = y1 - y2;
    double powx = pow(diffx, 2);
    double powy = pow(diffx, 2);
    double product = sqrt(powx + powy);

    printf("The distance between the two points is: %f", product);


    return 0;
}