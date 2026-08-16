#include <stdio.h>

int main()
{
    int n;
    unsigned char byte;
    unsigned char checksum = 0;  // Initialize checksum to 0

    // Input number of bytes
    printf("Enter number of bytes: ");
    scanf("%d", &n);

    // Input bytes one by one
    for (int i = 1; i <= n; i++)
    {
        printf("Enter byte %d (0-255): ", i );
        scanf("%hhu", &byte);   // %hhu for unsigned char (byte)
        
        // Generate checksum using XOR
        checksum = checksum ^ byte;
    }

    // Display checksum
    printf("Generated Checksum (XOR): %u\n", checksum);

    return 0;
}
