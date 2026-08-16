#include <stdio.h>
#include "task1.h"

int main()
{
    char sentence[100];

 printf("Enter a sentence: ");
 fgets(sentence, 100, stdin);
 
 toLower(sentence);

 printf("\n");

 int len = toUpperAndLength(sentence);
 printf("\n Enter the value of Length %d", len);
 
 word_count(sentence);

 Vowel_and_Freq(sentence);


return 0;
}
