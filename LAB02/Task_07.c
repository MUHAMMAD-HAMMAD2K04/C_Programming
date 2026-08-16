#include <stdio.h>

int main() {
    int playerRow, playerCol;
    int obstacleRow, obstacleCol;
    char direction;

    // Input player and obstacle positions
    printf("Enter player position (row column): ");
    scanf("%d %d", &playerRow, &playerCol);

    printf("Enter obstacle position (row column): ");
    scanf("%d %d", &obstacleRow, &obstacleCol);

    // Input move direction
    printf("Enter move direction (U=Up, D=Down, L=Left, R=Right): ");
    scanf(" %c", &direction);

    // Compute new position
    int nextRow = playerRow;
    int nextCol = playerCol;

    if (direction == 'U' || direction == 'u') nextRow += 1;      // Up
    else if (direction == 'D' || direction == 'd') nextRow -= 1; // Down
    else if (direction == 'R' || direction == 'r') nextCol += 1; // Right
    else if (direction == 'L' || direction == 'l') nextCol -= 1; // Left
    else {
        printf("Invalid direction!\n");
        return 0;
    }

    // Check boundaries (1 to 4)
    if (nextRow < 1 || nextRow > 4 || nextCol < 1 || nextCol > 4) {
        printf("Move goes out of the grid!\n");
    }
    // Check for obstacle
    else if (nextRow == obstacleRow && nextCol == obstacleCol) {
        printf("Collision! You hit the obstacle.\n");
    }
    else {
        printf("Move successful. New position: (%d,%d)\n", nextRow, nextCol);
    }

    return 0;
}
