/*
Cricket Statistics - There is cricket fever out there everywhere in Pakistan. Consider
Babar Azam statistics for the last few world cups. Take the number of matches he has
played in world cups. Now take the runs scored by Babar Azam in each match along
with the balls he faced. At the end your program should print the following for Babar
Azam:
● strike rate,
● batting average
● minimum score
● maximum score
● number of centuries*/

#include <stdio.h>

int main(){

int Number_of_matches, Runs_in_a_match, Balls_faced, Total_Runs,Number_of_times_out;
float Strike_Rate=0, Batting_average=0;
int Min_score = 0, Max_score = 196, Number_of_centuries = 9;

printf("Enter the Number of matches Played by Babar Azam: ");
scanf("%d",&Number_of_matches);

printf("\nEnter the  Runs scored by Babar Azam in a match: ");
scanf("%d",&Runs_in_a_match);

printf("\nEnter the Balls faced by Babar Azam in a match: ");
scanf("%d",&Balls_faced);

printf("\nEnter the Total Runs Scored by Babar Azam: ");
scanf("%d",&Total_Runs);

printf("\nEnter the Number of times Babar Azam out in his career: ");
scanf("%d",&Number_of_times_out);

Strike_Rate = ((float)Runs_in_a_match/Balls_faced) * 100;

Batting_average = ((float)Total_Runs/Number_of_times_out);

printf("\nStrike Rate of Babar Azam: %f",Strike_Rate);

printf("\nBatting Average of Babar Azam: %f",Batting_average);

printf("\nMinimum Runs Scored by Babar Azam: %d",Min_score);

printf("\nMaximum Runs Scored by Babar Azam: %d",Max_score);

printf("\nNumber of centuries Scored by Babar Azam: %d",Number_of_centuries);

return 0;
}
