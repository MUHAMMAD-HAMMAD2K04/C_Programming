#ifndef SIGNAL_H
#define SIGNAL_H

float average(float signal[], int N);
int zeroCrossings(float signal[], int N);
int glitches(float signal[], int N);
void filterSignal(float signal[], float h[], float output[], int N, int M);

#endif

