#include <stdio.h>

int main() {
    float a[5], mean = 0, median, mode = 0, sd = 0;
    int i, j, count, maxCount = 0;

    // Input 5 numbers
    printf("Enter 5 numbers:\n");
    for (i = 0; i < 5; i++) {
        scanf("%f", &a[i]);
        mean += a[i];
    }

    // Mean
    mean = mean / 5;

    // Sort (simple)
    for (i = 0; i < 4; i++) {
        for (j = i + 1; j < 5; j++) {
            if (a[i] > a[j]) {
                float temp = a[i];
                a[i] = a[j];
                a[j] = temp;
            }
        }
    }

    // Median
    median = a[2];

    // Mode
    for (i = 0; i < 5; i++) {
        count = 1;
        for (j = i + 1; j < 5; j++) {
            if (a[i] == a[j]) {
                count++;
            }
        }
        if (count > maxCount) {
            maxCount = count;
            mode = a[i];
        }
    }

    // Standard Deviation (without math.h)
    for (i = 0; i < 5; i++) {
        float diff = a[i] - mean;
        sd += diff * diff;
    }
    sd = sd / 5;  // variance (no sqrt for simplicity)

    // Output
    printf("Mean = %.2f\n", mean);
    printf("Median = %.2f\n", median);

    if (maxCount > 1)
        printf("Mode = %.2f\n", mode);
    else
        printf("No mode\n");

    printf("Variance  = %.2f\n", sd);

    return 0;
}
