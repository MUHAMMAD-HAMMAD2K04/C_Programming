#include <stdio.h>

int main()
{
    int M, N, K;
    int i, j, k;

    // Taking matrix dimensions
    printf("Enter number of rows of A (M): ");
    scanf("%d", &M);

    printf("Enter number of columns of A / rows of B (N): ");
    scanf("%d", &N);

    printf("Enter number of columns of B (K): ");
    scanf("%d", &K);

    // Declaring matrices
    int A[M][N], B[N][K], C[M][K];

    // Input Matrix A
    printf("\nEnter elements of Matrix A (%d x %d):\n", M, N);
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < N; j++)
        {
            printf("A[%d][%d]: ", i, j);
            scanf("%d", &A[i][j]);
        }
    }

    // Input Matrix B
    printf("\nEnter elements of Matrix B (%d x %d):\n", N, K);
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < K; j++)
        {
            printf("B[%d][%d]: ", i, j);
            scanf("%d", &B[i][j]);
        }
    }

    // Matrix Multiplication C = A * B
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < K; j++)
        {
            C[i][j] = 0; // Initialize result matrix element
            for(k = 0; k < N; k++)
            {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }

    // Display Result Matrix C
    printf("\nResultant Matrix C = A x B (%d x %d):\n", M, K);
    for(i = 0; i < M; i++)
    {
        for(j = 0; j < K; j++)
        {
            printf("%d ", C[i][j]);
        }
        printf("\n");
    }

    return 0;
}
