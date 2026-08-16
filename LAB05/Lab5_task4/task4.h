#ifndef MATMUL_H
#define MATMUL_H

float dotProduct(float a[], float b[], int N);
void transpose(float B[][100], float BT[][100], int N, int K);
void matrixMultiply(float A[][100], float B[][100], float C[][100], int M, int N, int K);

#endif
