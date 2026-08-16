#include "task3.h"

// Reusable dot product function
float dotProduct(float row[], float x[], int N)
{
    float sum = 0.0;
    int i;

    for (i = 0; i < N; i++)
    {
        sum += row[i] * x[i];
    }

    return sum;
}

// Matrix-vector multiplication: y = A * x
void matVecMultiply(float A[][100], float x[], float y[], int M, int N)
{
    int i;

    for (i = 0; i < M; i++)
    {
        // Each y[i] = dot product of row i of A with vector x
        y[i] = dotProduct(A[i], x, N);
    }
}
