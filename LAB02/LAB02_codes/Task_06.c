#include <stdio.h>

int main() {
    int x1, y1, x2, y2, x3, y3;
    int a2, b2, c2;

    // Input points
    printf("Enter point 1 (x1 y1): ");
    scanf("%d %d", &x1, &y1);
    printf("Enter point 2 (x2 y2): ");
    scanf("%d %d", &x2, &y2);
    printf("Enter point 3 (x3 y3): ");
    scanf("%d %d", &x3, &y3);

    // Calculate squared distances
    a2 = (x2 - x1)*(x2 - x1) + (y2 - y1)*(y2 - y1);
    b2 = (x3 - x2)*(x3 - x2) + (y3 - y2)*(y3 - y2);
    c2 = (x1 - x3)*(x1 - x3) + (y1 - y3)*(y1 - y3);

    // Check for right-angled triangle
    if (a2 + b2 == c2 || b2 + c2 == a2 || a2 + c2 == b2) {
        printf("The points form a right-angled triangle.\n");
    } else {
        printf("The points do NOT form a right-angled triangle.\n");
    }

    return 0;
}
