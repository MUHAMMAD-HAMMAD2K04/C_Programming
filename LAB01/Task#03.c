#include <stdio.h>

int main()
{
    char last_Name_Char = 'd';   // Last character of name
    char last_CNIC_Char = '1';   // Last digit of CNIC

    /* Printing Name:Muhammad Hammad */
    
    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
  
  77,   // M 
  117,  // u
  104,  // h
  97,   // a
  109,  // m
  109,  // m
  97,   // a
  last_Name_Char,   // d
  32,   // space
  72,   // H
  97,   // a
  109,  // m
  109,  // m
  97,   // a
  last_Name_Char); // d

    /* Printing CNIC: 41303-8529418-1 */

    printf("%c%c%c%c%c%c%c%c%c%c%c%c%c%c%c\n",
  52,  // 4
  49,  // 1
  51,  // 3
  48,  // 0
  51,  // 3
  45,  // -
  56,  // 8
  53,  // 5
  50,  // 2
  57,  // 9
  52,  // 4
  49,  // 1
  56,  // 8
  45,  // -
  last_CNIC_Char); // 1

    return 0;
}
