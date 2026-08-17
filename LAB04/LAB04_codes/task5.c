#include <stdio.h>
#include <math.h>

int main()
{
    int N, i;
    float threshold;

    printf("Enter number of samples: ");
    scanf("%d", &N);

    float v[N];

    // Input signal samples
    for(i = 0; i < N; i++)
    {
        printf("Enter v[%d]: ", i);
        scanf("%f", &v[i]);
    }

    // Input threshold for glitch detection
    printf("Enter glitch detection threshold: ");
    scanf("%f", &threshold);

    // Detect glitches
    printf("\nGlitches detected at indices:\n");
    for(i = 1; i < N; i++)
    {
        if(fabs(v[i] - v[i-1]) > threshold)
        {
            printf("Glitch at sample %d (sudden change)\n", i);
        }
    }

    return 0;
}
