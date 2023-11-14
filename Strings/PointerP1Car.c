#include <stdio.h>
void drive(double* odomPtr, double* fuelPtr, double mpg, double distance);

int main()
{
    double odomPtr, fuelPtr, mpg, distance;

    printf("Enter odometer reading, fuel gauge reading and mpg: ");
    scanf("%lf%lf%lf", &odomPtr, &fuelPtr, &mpg);

    while(1)
    {
        printf("\nEnter the distance you want to drive: ");
        scanf("%lf", &distance);

        drive(&odomPtr, &fuelPtr, mpg, distance);
        
        if(fuelPtr <= 0)
        {   
            printf("Current reading odometer = %.2lf, fuel = %.2lf\n", odomPtr, 0.00);
            printf("No more fuel!\n");
            break;
        }
        else
        {
            printf("\nCurrent reading odometer = %.2lf, fuel = %.2lf\n", odomPtr, fuelPtr);
        }

    }
}

void drive(double* odomPtr, double* fuelPtr, double mpg, double distance)
{
    if(distance / mpg < *fuelPtr)
    {
        *fuelPtr -= (distance/mpg);
        *odomPtr += distance;
    }

    else if (distance / mpg >= *fuelPtr)
    {
        *odomPtr += (*fuelPtr * mpg);
        *fuelPtr = 0.00;
    }
}

