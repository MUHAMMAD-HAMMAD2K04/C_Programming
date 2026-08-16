#include "task6.h"
#include <stdio.h>

// Function to detect pixel types
// type: 0 = black, 1 = white, 2 = yellow
void countPixelType(int img[][100][3], int H, int W, int type)
{
    int i, j, count = 0;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            int R = img[i][j][0];
            int G = img[i][j][1];
            int B = img[i][j][2];

            if (type == 0 && R == 0 && G == 0 && B == 0) // Black
                count++;
            else if (type == 1 && R == 255 && G == 255 && B == 255) // White
                count++;
            else if (type == 2 && R == 255 && G == 255 && B == 0) // Yellow
                count++;
        }
    }

    if (type == 0)
        printf("Number of Black pixels: %d\n", count);
    else if (type == 1)
        printf("Number of White pixels: %d\n", count);
    else if (type == 2)
        printf("Number of Yellow pixels: %d\n", count);
}

// RGB to Grayscale conversion
void rgbToGray(int img[][100][3], float gray[][100], int H, int W)
{
    int i, j;

    for (i = 0; i < H; i++)
    {
        for (j = 0; j < W; j++)
        {
            int R = img[i][j][0];
            int G = img[i][j][1];
            int B = img[i][j][2];

            // Standard grayscale formula
            gray[i][j] = 0.299 * R + 0.587 * G + 0.114 * B;
        }
    }
}

// 2D Convolution with 3x3 Mean Filter
void convolve(float gray[][100], float output[][100], int H, int W)
{
    int i, j, m, n;
    float H_filter[3][3] = {
        {1.0/9, 1.0/9, 1.0/9},
        {1.0/9, 1.0/9, 1.0/9},
        {1.0/9, 1.0/9, 1.0/9}
    };

    // Ignore borders (simple valid convolution)
    for (i = 1; i < H - 1; i++)
    {
        for (j = 1; j < W - 1; j++)
        {
            output[i][j] = 0.0;

            for (m = -1; m <= 1; m++)
            {
                for (n = -1; n <= 1; n++)
                {
                    output[i][j] += gray[i + m][j + n] * H_filter[m + 1][n + 1];
                }
            }
        }
    }
}
