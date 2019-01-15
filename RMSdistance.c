/* CS 153 PROGRAM ASSIGNMENT #10

Program that calculates the RMS value from two
frequency input files and then prints 
out the RMS distance for each file.

Mark Schuberth 
 
11/27/2018 */

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

/* sum each individual frequency and  */
/* then subtract the difference and square root */
int main(int argc, char *argv[])
{
 FILE *input1, *input2;
 double freqOne[26], freqTwo[26], diff, result, RMSdist;
 double sum = 0.0;
 int i, j;
 char c;
 
 /* reads in each frequency file */
 input1 = fopen(argv[1], "r");
 input2 = fopen(argv[2], "r");
 
 /* check if there is an error opening file */
 if(input1 == NULL)
 {
  perror(argv[1]);
  exit(EXIT_FAILURE);
 }
 
 /* check if there is an error opening file */
 if(input2 == NULL)
 {
  perror(argv[2]);
  exit(EXIT_FAILURE);
 }
  
 /* need to put austinfreq.txt into freqOne[] */
 for(i = 0; i < 26; i++)
 {
  /* scans input file and parses char from double */
  fscanf(input1, "%*c %lf\n", &freqOne[i]);
 }
 /* need to put twainfreq.txt into freqTwo[] */
 for(j = 0; j < 26; j++)
 {
  /* scans input file and parses char from double */
  fscanf(input2, "%*c %lf\n", &freqTwo[j]);
 }
 /* need to find diff of each frequency and calc with file[52] */
 for(i = 0; i < 26; i++)
 {
  diff = freqOne[i] - freqTwo[i];
  result = diff * diff;
  sum += result;
 }
 /* square root of the sum divided by number of elements */
 RMSdist = sqrt(sum/26);
 
 /* prints the result of the RMS distance */
 printf("RMS distance is = %lf\n", RMSdist);
 
 /* closes input files once the program is finished */
 fclose(input1);
 fclose(input2);
 
 return 0;
}