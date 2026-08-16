#include <stdio.h>
#include "task2.h"

int main()
{
    int N, i;

    // Input size of vectors
    printf("Enter the size of vectors (N): ");
    scanf("%d", &N);

    float x[N], y[N];
    float result;

    // Input vector x
    printf("Enter elements of vector x:\n");
    for (i = 0; i < N; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    // Input vector y
    printf("Enter elements of vector y:\n");
    for (i = 0; i < N; i++)
    {
        printf("y[%d]: ", i);
        scanf("%f", &y[i]);
    }

    // Function call to compute dot product
    result = dotProduct(x, y, N);

    // Display result
    printf("\nDot Product (x^T y) = %.2f\n", result);

    return 0;
}

