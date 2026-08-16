#include <stdio.h>
#include "task4.h"

int main()
{
    int M, N, K, i, j;

    // Input dimensions
    printf("Enter number of rows of A (M): ");
    scanf("%d", &M);

    printf("Enter number of columns of A / rows of B (N): ");
    scanf("%d", &N);

    printf("Enter number of columns of B (K): ");
    scanf("%d", &K);

    // Safety check
    if (M <= 0 || N <= 0 || K <= 0 || M > 100 || N > 100 || K > 100)
    {
        printf("Invalid matrix size!\n");
        return 1;
    }

    float A[100][100], B[100][100], C[100][100];

    // Input Matrix A (M x N)
    printf("\nEnter elements of matrix A (%d x %d):\n", M, N);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < N; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%f", &A[i][j]);
        }
    }

    // Input Matrix B (N x K)
    printf("\nEnter elements of matrix B (%d x %d):\n", N, K);
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%f", &B[i][j]);
        }
    }

    // Perform Matrix Multiplication
    matrixMultiply(A, B, C, M, N, K);

    // Display Result Matrix C (M x K)
    printf("\nResult Matrix C = A * B (%d x %d):\n", M, K);
    for (i = 0; i < M; i++)
    {
        for (j = 0; j < K; j++)
        {
            printf("%.2f ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
