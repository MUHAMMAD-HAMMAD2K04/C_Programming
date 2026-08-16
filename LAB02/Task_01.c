#include <stdio.h>

int main() {
    int month, day;

    // Input from user
    printf("Enter month (1-12): ");
    scanf("%d", &month);
    printf("Enter day (1-31): ");
    scanf("%d", &day);

    // Check public holidays 
    // Format: month/day
    if         ((month == 1 && day == 1))      // New Year's Day
    printf("Yes, It's a public holiday. It's New Year's Day");
    else if    ((month == 3 && day == 23))     // Pakistan Day
    printf("Yes, It's a public holiday. It's Pakistan Day");
    else if    ((month == 5 && day == 1))      // Labour Day
    printf("Yes, It's a public holiday. It's Labour Day");
    else if    ((month == 8 && day == 14))     // Independence Day
    printf("Yes, It's a public holiday. It's Independence Day");
    else if    ((month == 12 && day == 25))    //Quaid-e-Azam Holiday
    printf("Yes, It's a public holiday. It's Quaid-e-Azam Holiday");
    else 
    printf("No Public Holiday");
    

    return 0;
}
