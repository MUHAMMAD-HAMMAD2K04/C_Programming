#include <stdio.h>
#include "task6.h"

#define H 3
#define W 3

int main()
{
    int image[H][100][3];
    float gray[H][100];
    float filtered[H][100];
    int i, j, k, type;

    // Input RGB Image
    printf("Enter RGB values for image (%dx%d):\n", H, W);
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            printf("Pixel[%d][%d] (R G B): ", i, j);
            for (k = 0; k < 3; k++)
            {
                scanf("%d", &image[i][j][k]);
            }
        }
    }

    // Input pixel type to detect
    printf("\nEnter pixel type to count (0=Black, 1=White, 2=Yellow): ");
    scanf("%d", &type);

    // Count pixel types
    countPixelType(image, H, W, type);

    // Convert to grayscale
    rgbToGray(image, gray, H, W);

    printf("\nGrayscale Image:\n");
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            printf("%.2f ", gray[i][j]);
        }
        printf("\n");
    }

    // Apply convolution filter
    convolve(gray, filtered, H, W);

    printf("\nFiltered Image (After Convolution):\n");
    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            printf("%.2f ", filtered[i][j]);
        }
        printf("\n");
    }

    return 0;
}

