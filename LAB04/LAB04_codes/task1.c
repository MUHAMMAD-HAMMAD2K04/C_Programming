/*Take an input sentence (maximum length N = 100) and perform the following
operations on the sentence.
a. Length of the sentence
b. Sentence in lowercase
c. Sentence in uppercase
d. Number of words in the sentence
e. Number of vowels
f. Frequency of the vowels*/

#include <stdio.h>

int main() {
    char sentence[100];
    int length = 0, i = 0, count = 1;
    int vowels = 0;
    int freqA = 0, freqE = 0, freqI = 0, freqO = 0, freqU = 0;

    printf("Enter the sentence: ");
    fgets(sentence, sizeof(sentence), stdin);

    // Uppercase conversion + length calculation
    while (sentence[i] != '\0' && sentence[i] != '\n') {
        if (sentence[i] >= 97 && sentence[i] <= 122) {
            printf("%c", sentence[i] - 32);
        } else {
            printf("%c", sentence[i]);
        }
        length = length + 1;
        i++;
    }

    printf("\n");

    // Lowercase conversion
    int j = 0;
    while (sentence[j] != '\0' && sentence[j] != '\n') {
        if (sentence[j] >= 65 && sentence[j] <= 90) {
            printf("%c", sentence[j] + 32);
        } else {
            printf("%c", sentence[j]);
        }
        j++;
    }

    // Part (d) - Number of words
    int k = 0;
    while (sentence[k] != '\0' && sentence[k] != '\n') {
        if (sentence[k] == ' ') {
            count++;
        }
        k++;
    }

    // Part (e) & (f) - Vowel count and frequency
    int m = 0;
    while (sentence[m] != '\0' && sentence[m] != '\n') {
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
    printf("\nThe length of the string is: %d\n", length);
    printf("Number of words in the sentence: %d\n", count);
    printf("Number of vowels: %d\n", vowels);

    printf("Frequency of vowels:\n");
    printf("A/a: %d\n", freqA);
    printf("E/e: %d\n", freqE);
    printf("I/i: %d\n", freqI);
    printf("O/o: %d\n", freqO);
    printf("U/u: %d\n", freqU);

    return 0;
}
