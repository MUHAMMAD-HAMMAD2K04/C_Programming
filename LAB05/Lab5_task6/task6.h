#ifndef IMAGE_H
#define IMAGE_H

void countPixelType(int img[][100][3], int H, int W, int type);
void rgbToGray(int img[][100][3], float gray[][100], int H, int W);
void convolve(float gray[][100], float output[][100], int H, int W);

#endif

