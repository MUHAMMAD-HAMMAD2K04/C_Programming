#include <stdio.h>

int main()
{
    float credit_Hours_Course1, credit_Hours_Course2, credit_Hours_Course3;
    float grade_Points_Course1, grade_Points_Course2, grade_Points_Course3;
    float total_Credit_Hours, total_Grade_Points, semester_GPA;

    // Input for Course 1
    printf("Enter credit hours of Course 1: ");
    scanf("%f", &credit_Hours_Course1);

    printf("Enter grade points of Course 1 (4.0, 3.5, 3.0, etc): ");
    scanf("%f", &grade_Points_Course1);

    // Input for Course 2
    printf("Enter credit hours of Course 2: ");
    scanf("%f", &credit_Hours_Course2);

    printf("Enter grade points of Course 2 (4.0, 3.5, 3.0, etc): ");
    scanf("%f", &grade_Points_Course2);

    // Input for Course 3
    printf("Enter credit hours of Course 3: ");
    scanf("%f", &credit_Hours_Course3);

    printf("Enter grade points of Course 3 (4.0, 3.5, 3.0, etc): ");
    scanf("%f", &grade_Points_Course3);

    // GPA Calculation
    total_Credit_Hours = credit_Hours_Course1 + credit_Hours_Course2 + credit_Hours_Course3;
    total_Grade_Points = (credit_Hours_Course1 * grade_Points_Course1) +
                       (credit_Hours_Course2 * grade_Points_Course2) +
                       (credit_Hours_Course3 * grade_Points_Course3);

    semester_GPA = total_Grade_Points / total_Credit_Hours;

    printf("\nYour Semester GPA = %.2f\n", semester_GPA);

    return 0;
}
