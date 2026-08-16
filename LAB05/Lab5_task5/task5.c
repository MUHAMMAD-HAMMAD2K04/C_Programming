#include "task5.h"
#include <math.h>

// Function to find average value of signal
float average(float signal[], int N)
{
    float sum = 0.0;
    int i;

    for (i = 0; i < N; i++)
    {
        sum += signal[i];
    }

    return sum / N;
}

// Function to detect zero crossings
int zeroCrossings(float signal[], int N)
{
    int count = 0, i;

    for (i = 1; i < N; i++)
    {
        if ((signal[i - 1] >= 0 && signal[i] < 0) ||
            (signal[i - 1] < 0 && signal[i] >= 0))
        {
            count++;
        }
    }

    return count;
}

// Function to detect glitches
// (Glitch = sudden large change between consecutive samples)
int glitches(float signal[], int N)
{
    int count = 0, i;
    float threshold = 0.5;  // You can adjust based on lab requirement

    for (i = 1; i < N; i++)
    {
        if (fabs(signal[i] - signal[i - 1]) > threshold)
        {
            count++;
        }
    }

    return count;
}

// Filtering using transfer function (FIR Convolution)
void filterSignal(float signal[], float h[], float output[], int N, int M)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        output[i] = 0.0;

        for (j = 0; j < M; j++)
        {
            if (i - j >= 0)
            {
                output[i] += signal[i - j] * h[j];
            }
        }
    }
}
