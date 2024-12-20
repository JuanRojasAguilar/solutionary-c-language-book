#include <stdio.h>

#define LOWERLIMIT 0
#define UPPERLIMIT 300
#define STEP 20

float farenheitToCelsius(float f);

int main()
{
    int fahr;

    for (fahr = LOWERLIMIT; fahr <= UPPERLIMIT; fahr = fahr + STEP)
        printf("%3d %6.1f\n", fahr, farenheitToCelsius(fahr));
    return 0;
}

float farenheitToCelsius(float farenheit)
{
    return (5.0/9.0) * (farenheit - 32.0);
}
