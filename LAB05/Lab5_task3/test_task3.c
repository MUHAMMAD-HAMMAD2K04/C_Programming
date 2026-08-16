#include <stdio.h>
#include "task3.h"

int main()
{
    int M, N, i, j;

    // Input matrix dimensions
    printf("Enter number of rows (M): ");
    scanf("%d", &M);

    printf("Enter number of columns (N): ");
    scanf("%d", &N);

    // Safety check
    if (M <= 0 || N <= 0 || M > 100 || N > 100)
    {
        printf("Invalid matrix size!\n");
        return 1;
    }

    float A[100][100], x[100], y[100];

    // Input matrix A (MxN)
    printf("\nEnter elements of matrix A (%d x %d):\n", M, N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Input vector x (Nx1)
    printf("\nEnter elements of vector x (%d x 1):\n", N);
    for (i = 0; i < N; i++)
    {
        printf("x[%d]: ", i);
        scanf("%f", &x[i]);
    }

    // Perform matrix-vector multiplication
    matVecMultiply(A, x, y, M, N);

    // Display result vector y (Mx1)
    printf("\nResult vector y = A*x:\n");
    for (i = 0; i < M; i++)
    {
        printf("y[%d] = %.2f\n", i, y[i]);
    }

    return 0;
}
