#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main()
{
    int gridSize = 4; // 4x4 grid
    int xt, yt;       // Treasure location

    // Initialize random number generator
    srand(time(0));

    // Generate random treasure location (1 to 4 for both x and y)
    xt = (rand() % gridSize) + 1;
    yt = (rand() % gridSize) + 1;

    printf("Searching for treasure...\n");

    // Search the grid
    for (int x = 1; x <= gridSize; x++)
    {
        for (int y = 1; y <= gridSize; y++)
        {
            // Check if current location matches treasure
            if (x == xt && y == yt)
            {
                printf("Hurrah!, I have found the hidden treasure at (%d,%d)\n", x, y);
                return 0; // Exit after finding
            }
        }
    }

    return 0;
}
