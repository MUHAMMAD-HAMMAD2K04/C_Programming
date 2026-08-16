//Take a 3-digit number from the user and print out the digit at unit, 10th and 100th place.

#include <stdio.h>

int main() {
    int number;
    int unit, tens, hundreds;

    // Take input from user
    printf("Enter a 3-digit number: ");
    scanf("%d", &number);

    // Extract digits
    unit = number % 10;
    tens = (number / 10) % 10;
    hundreds = number / 100;

    // Display results
    printf("Hundreds place digit: %d\n", hundreds);
    printf("Tens place digit: %d\n", tens);
    printf("Units place digit: %d\n", unit);

    return 0;
}
