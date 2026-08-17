#include <stdio.h>
#include <unistd.h>  // for sleep()

int main()
{
    int N;          // Number of minutes
    int minute, second;

    // Take input from user
    printf("Enter number of minutes: ");
    scanf("%d", &N);

    // Validate input
    if (N <= 0)
    {
        printf("Invalid input! Enter a positive number of minutes.\n");
        return 0;
    }

    // Stopwatch counting
    for (minute = 0; minute < N; minute++)
    {
        for (second = 0; second <= 59; second++)
        {
            // Display in MM : SS format (2-digit)
            printf("%02d : %02d\n", minute, second);

            // Delay of 1 second to simulate real stopwatch
            sleep(1);
        }
    }

    return 0;
}
