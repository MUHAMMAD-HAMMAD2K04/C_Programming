#include <stdio.h>

int main()
{
    float a, b, c;
    float x_extrema, y_extrema;

    // Taking coefficients input
    printf("Enter coefficient a: ");
    scanf("%f", &a);

    printf("Enter coefficient b: ");
    scanf("%f", &b);

    printf("Enter coefficient c: ");
    scanf("%f", &c);

    // Calculate extrema point (x)
    x_extrema = -b / (2 * a);

    // Calculate y value at extrema
    y_extrema = a * x_extrema * x_extrema + b * x_extrema + c;

    // Display result
    printf("\nExtrema Point (x) = %.2f\n", x_extrema);
    printf("Extrema Value f(x) = %.2f\n", y_extrema);

    return 0;
}
