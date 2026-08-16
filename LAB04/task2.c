#include <stdio.h>

int main()
{
    int N, i;
    float a, b;

    // Input size of vectors
    printf("Enter the size of vectors (N): ");
    scanf("%d", &N);

    float x[N], y[N], result[N];

    // Input scalars
    printf("Enter scalar a: ");
    scanf("%f", &a);

    printf("Enter scalar b: ");
    scanf("%f", &b);

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

    // Compute ax + by
    for (i = 0; i < N; i++)
    {
        result[i] = a * x[i] + b * y[i];
    }

    // Display result vector
    printf("\nResult vector (a*x + b*y):\n");
    for (i = 0; i < N; i++)
    {
        printf("%.2f ", result[i]);
    }

    printf("\n");
    return 0;
}
