#include "task4.h"

// Reusable Dot Product Function
float dotProduct(float a[], float b[], int N)
{
    float sum = 0.0;
    int i;

    for (i = 0; i < N; i++)
    {
        sum += a[i] * b[i];
    }

    return sum;
}

// Transpose of Matrix B (NxK -> KxN)
void transpose(float B[][100], float BT[][100], int N, int K)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = 0; j < K; j++)
        {
            BT[j][i] = B[i][j];
        }
    }
}

// Matrix Multiplication using Dot Product: C = A * B
void matrixMultiply(float A[][100], float B[][100], float C[][100], int M, int N, int K)
{
    int i, j;
    float BT[100][100];  // Transpose of B

    // Transpose B to reuse dot product easily
    transpose(B, BT, N, K);

    for (i = 0; i < M; i++)
    {
        for (j = 0; j < K; j++)
        {
            // C[i][j] = dot product of A[i] and BT[j]
            C[i][j] = dotProduct(A[i], BT[j], N);
        }
    }
}
