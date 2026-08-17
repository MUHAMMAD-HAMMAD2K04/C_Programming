#include <stdio.h>
#include <stdlib.h>   // For rand() and srand()
#include <time.h>     // For time() to seed random generator

int main() {
    int Limit = 100;
    
    // Seed the random number generator
    srand(time(0));
    
    // Generate random number between 0 and Limit-1
    int N = rand() % Limit;
    int guess;

    printf("Guess the number between 0 and %d!\n", Limit - 1);

    // Using for loop (infinite loop) for guessing
    for (;;) {
        printf("Enter your guess: ");
        scanf("%d", &guess);

        if (guess < N) {
            printf("The number is greater than %d. Try again.\n", guess);
        } else if (guess > N) {
            printf("The number is less than %d. Try again.\n", guess);
        } else {
            printf("Congratulations! You guessed the correct number: %d\n", N);
            break;  // Exit the loop when guessed correctly
        }
    }

    return 0;
}
