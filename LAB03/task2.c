#include <stdio.h>

int main()
{
    int Number, temp;
    int arr[32];
    int i;

    printf("Enter a decimal number: ");
    scanf("%d", &Number);

    // Decimal to Hexadecimal
    temp = Number;
    i = 0;

    if (temp == 0)
    {
        printf("Hexadecimal: 0\n");
    }
    else
    {
        while (temp > 0)
        {
            arr[i] = temp % 16;
            temp = temp / 16;
            i++;
        }

        printf("Hexadecimal: ");
        for (int j = i - 1; j >= 0; j--)
        {
            if (arr[j] < 10)
                printf("%d", arr[j]);
            else
                printf("%c", arr[j] + 55); // 10->A, 11->B ...
        }
        printf("\n");
    }

    // Decimal to Octal
    temp = Number;
    i = 0;

    if (temp == 0)
    {
        printf("Octal: 0\n");
    }
    else
    {
        while (temp > 0)
        {
            arr[i] = temp % 8;
            temp = temp / 8;
            i++;
        }

        printf("Octal: ");
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", arr[j]);
        }
        printf("\n");
    }

    // Decimal to Binary
    temp = Number;
    i = 0;

    if (temp == 0)
    {
        printf("Binary: 0\n");
    }
    else
    {
        while (temp > 0)
        {
            arr[i] = temp % 2;
            temp = temp / 2;
            i++;
        }

        printf("Binary: ");
        for (int j = i - 1; j >= 0; j--)
        {
            printf("%d", arr[j]);
        }
        printf("\n");
    }

    return 0;
}
