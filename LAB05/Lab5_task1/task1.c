#include <stdio.h>


// Uppercase conversion + length calculation
int toUpperAndLength(char sentence[])
{
    int i=0, length = 0;

        while (sentence[i] != '\0' && sentence[i] != '\n') {
        if (sentence[i] >= 97 && sentence[i] <= 122) {
            printf("%c", sentence[i] - 32);
        } else {
            printf("%c", sentence[i]);
        }
        length = length + 1;
        i++;
    }
return length;

}
 // Lowercase conversion
void toLower(char sentence[])
{
int j = 0;
    while (sentence[j] != '\0' && sentence[j] != '\n') {
        if (sentence[j] >= 65 && sentence[j] <= 90) {
            printf("%c", sentence[j] + 32);
        } else {
            printf("%c", sentence[j]);
        }
        j++;
    }
}

// Part (d) - Number of words
void word_count(char sentence[])
{
    int k = 0, count = 1;
    while (sentence[k] != '\0' && sentence[k] != '\n') 
    {
        if (sentence[k] == ' ') 
        {
            count++;
        }
        k++;
    }
    printf("\nNumber of words in the sentence: %d\n", count);
}

    // Part (e) & (f) - Vowel count and frequency
void Vowel_and_Freq(char sentence[])
{    
    int m = 0, vowels = 0;
    int freqA = 0, freqE = 0, freqI = 0, freqO = 0, freqU = 0;

    while (sentence[m] != '\0' && sentence[m] != '\n') 
    {
        if (sentence[m] == 'a' || sentence[m] == 'A') {
            vowels++;
            freqA++;
        }
        else if (sentence[m] == 'e' || sentence[m] == 'E') {
            vowels++;
            freqE++;
        }
        else if (sentence[m] == 'i' || sentence[m] == 'I') {
            vowels++;
            freqI++;
        }
        else if (sentence[m] == 'o' || sentence[m] == 'O') {
            vowels++;
            freqO++;
        }
        else if (sentence[m] == 'u' || sentence[m] == 'U') {
            vowels++;
            freqU++;
        }
        m++;
    }
    // Printing results
    
    printf("Number of vowels: %d\n", vowels);
    printf("Frequency of vowels:\n");
    printf("A/a: %d\n", freqA);
    printf("E/e: %d\n", freqE);
    printf("I/i: %d\n", freqI);
    printf("O/o: %d\n", freqO);
    printf("U/u: %d\n", freqU);


}
