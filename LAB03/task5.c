#include <stdio.h>

int main()
{
    int x, y;
    char direction;

    // Taking initial position
    printf("Enter initial position (x y) between 1 and 4: ");
    scanf("%d %d", &x, &y);

    // Validate starting position
    if (x < 1 || x > 4 || y < 1 || y > 4)
    {
        printf("Invalid starting position!\n");
        return 0;
    }

    while (1)
    {
        // Take direction every time (not just once)
        printf("Enter direction (U for Up, D for Down, L for Left, R for Right): ");
        scanf(" %c", &direction);

        // Move only ONE step
        if (direction == 'U' || direction == 'u')
        {
            y--;
        }
        else if (direction == 'D' || direction == 'd')
        {
            y++;
        }
        else if (direction == 'L' || direction == 'l')
        {
            x--;
        }
        else if (direction == 'R' || direction == 'r')
        {
            x++;
        }
        else
        {
            printf("Invalid direction! Try again.\n");
            continue;
        }

        // Check if boundary reached
        if (x < 1)
        {
            x = 1;
            printf("The player has reached the boundary at (%d,%d)\n", x, y);
            break;
        }
        else if (x > 4)
        {
            x = 4;
            printf("The player has reached the boundary at (%d,%d)\n", x, y);
            break;
        }
        else if (y < 1)
        {
            y = 1;
            printf("The player has reached the boundary at (%d,%d)\n", x, y);
            break;
        }
        else if (y > 4)
        {
            y = 4;
            printf("The player has reached the boundary at (%d,%d)\n", x, y);
            break;
        }
        else
        {
            // Still inside grid, show new position and ask again
            printf("Current position: (%d,%d)\n", x, y);
        }
    }

    return 0;
}
