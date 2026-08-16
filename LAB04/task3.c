#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int arr[10];
    int i, j;

    // Seed for random number generation
    srand(time(0));

    // Initialize array with random numbers from 1 to 20
    for (i = 0; i < 10; i++)
    {
        arr[i] = (rand() % 20) + 1;
    }

    // Display histogram
    printf("Element\tValue\tHistogram\n");

    for (i = 0; i < 10; i++)
    {
        printf("%d\t%d\t", i, arr[i]);

        // Print stars equal to the value
        for (j = 0; j < arr[i]; j++)
        {
            printf("*");
        }
        printf("\n");
    }

    return 0;
}
