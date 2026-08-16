#include "task2.h"

float dotProduct(float x[], float y[], int N)
{
    float sum = 0.0;
    int i;

    for (i = 0; i < N; i++)
    {
        sum += x[i] * y[i];
    }

    return sum;
}

