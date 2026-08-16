#include <stdio.h>
#include "task5.h"

#define N 10   // Fixed signal size
#define M 3    // Transfer function size

int main()
{
    float signal[N], h[M], filtered[N];
    int i;

    // Input signal
    printf("Enter %d samples of the signal:\n", N);
    for (i = 0; i < N; i++)
    {
        printf("signal[%d]: ", i);
        scanf("%f", &signal[i]);
    }

    // Input transfer function (filter coefficients)
    printf("\nEnter %d transfer function coefficients:\n", M);
    for (i = 0; i < M; i++)
    {
        printf("h[%d]: ", i);
        scanf("%f", &h[i]);
    }

    // Compute average
    float avg = average(signal, N);

    // Compute zero crossings
    int zc = zeroCrossings(signal, N);

    // Compute glitches
    int g = glitches(signal, N);

    // Filtering
    filterSignal(signal, h, filtered, N, M);

    // Display results
    printf("\nAverage value of signal = %.3f\n", avg);
    printf("Number of Zero Crossings = %d\n", zc);
    printf("Number of Glitches = %d\n", g);

    printf("\nFiltered Signal:\n");
    for (i = 0; i < N; i++)
    {
        printf("%.3f ", filtered[i]);
    }
    printf("\n");

    return 0;
}
