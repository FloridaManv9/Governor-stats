#include <stdio.h>
#include <stdlib.h>

/*
 * COP 3515 – Fall Semester 2020 *
 *
 * Homework #1: Helping The Governor Out *
 *
 * (Matthew Signore)
 */

int main() {
    FILE *file;

    /* These are the variables that are used */

    char string[50];
    char string2[40];
    char gender;
    char testchar;

    int malecount = 0;
   int femalecount = 0;
   int malepositivecount = 0;
   int femalepositvecount = 0;
   int malenegativecount = 0;
   int femalenegativecount= 0;
   int malenegativeagecount = 0;
   int femalenegativeagecount = 0;

   int maleweightsum = 0;
   int femaleweightsum = 0;

   float averageinfected = 0;

   char age[2];
    int ageint = 0;
   int maleagesum = 0;
   int femaleagesum = 0;
   int youngestAge = 50;
   int oldestAge = 50;

char height[3] = {0,0,'\n'};
int heightint = 0;

char weight[4] = {0,0,0,'\n'};
int weightint = 0;

float bmi = 0;
float malebmisum = 0;
float femalebmisum = 0;

int obesefemalesp = 0;
int obesemalesp = 0;
int eightyplusobese = 0;

int under30malecount = 0;
int thirtyptosixtymalecount = 0;
int sixtypplusmalecount = 0;

float under30malesum = 0;
float thirtytosixtymalesum = 0;
float sixtyplusmalesum = 0;

int under30femalecount = 0;
int thirtyptosixtyfemalecount = 0;
int sixtyplusfemalecount = 0;

float under30femalesum = 0;
float thirtytosixtyfemalesum = 0;
float sixtyplusfemalesum = 0;



    file = fopen("C:\\Users\\polan\\CLionProjects\\homerwork1\\data.txt", "r");



    while  (fgets(string, 50, file))  {
            /* This scans the strings of the data file and fills the character arrays for gender, age, weight, and height */
        gender = string[0];
        age[0] = string[2];
        age[1] = string[3];
        ageint = atoi(age);




        weight[0] = string[9],
        weight[1] = string[10],
        weight[2] = string[11];

        weightint = atoi(weight);

        height[0] = string[6];
        height[1] = string[7];

        heightint = atoi(height);

        bmi = (((float)weightint / ((float)heightint * (float)heightint)) * (float)703);


            /* The results of the covid test */
        testchar = string[13];


        if (gender == 77) { /* If gender is male */
            malecount++;
        }
        else if (gender == 70){ /* If gender is female */
            femalecount++;
        }


        if (testchar == '+'){ /* If the result is positive */
            if ((bmi >= 30) && (ageint >= 80)) {
                eightyplusobese++;
            }
            if (ageint < youngestAge){
                youngestAge = ageint;
            }
            if (ageint > oldestAge){
                oldestAge = ageint;
            }
            if (gender == 77){ /* Sorting the results for positive males and their age bracket */
                if (ageint < 30){
                    under30malesum = bmi + under30malesum;
                    under30malecount++;
                }
                else if ((ageint > 30) && (ageint < 60)){
                    thirtytosixtymalesum = bmi + thirtytosixtymalesum;
                    thirtyptosixtymalecount++;
                }
                else if (ageint > 60){
                    sixtyplusmalesum = bmi + sixtyplusmalesum;
                    sixtypplusmalecount++;
                }
                if (bmi >= 30){
                    obesemalesp++;
                }
                malebmisum = malebmisum + bmi;
                maleweightsum = weightint + maleweightsum;
                maleagesum = ageint + maleagesum;
                malepositivecount++;

            }
            else if (gender == 70){ /* Sorting the results for positive females and their age bracket */
                if (ageint < 30){
                    under30femalesum = bmi + under30femalesum;
                    under30femalecount++;
                }
                else if ((ageint > 30) && (ageint < 60)){
                    thirtytosixtyfemalesum = bmi + thirtytosixtyfemalesum;
                    thirtyptosixtyfemalecount++;
                }
                else if (ageint > 60){
                    sixtyplusfemalesum = bmi + sixtyplusfemalesum;
                    sixtyplusfemalecount++;
                }
                if(bmi >= 30 ){
                    obesefemalesp++;
                }
                femaleweightsum = weightint + femaleweightsum,
                femaleagesum = ageint + femaleagesum,
                femalebmisum = femalebmisum + bmi,
                                     femalepositvecount++;}
        }
            /* If the result is negative, adding the negative male count */
        else if (gender == 77){malenegativecount++,
                               malenegativeagecount = ageint + malenegativeagecount;
        }
        else if(gender == 70) {
            /* If the result is negative, adding the negative female count */
            femalenegativecount++,
                    femalenegativeagecount = ageint + femalenegativeagecount;
        }






    }
/* Calculating the average amount of the population that is infected */
    averageinfected = ((float)malepositivecount + (float)femalepositvecount)/ ((float)malecount +(float)femalecount);


    /* All the print statements that print the specified information */

    printf("\n");
    printf("The amount of Positive male cases is ");
    printf("%d", malepositivecount);
    printf("\n");

    printf("The amount of Positive female cases is ");
    printf("%d", femalepositvecount);
    printf("\n");

    printf("The average age of positive males is ");
    printf("%d", maleagesum / malepositivecount);
    printf(" while the average negative age is ");
    printf("%d", malenegativeagecount / malenegativecount);
    printf("\n");

    printf("The average age of positive females is ");
    printf("%d", femaleagesum / femalepositvecount);
    printf(" while the average negative age is ");
    printf("%d", femalenegativeagecount / femalenegativecount);
    printf("\n");

    printf("The oldest positive case is ");
    printf("%d", oldestAge);
    printf(" while the youngest is ");
    printf("%d", youngestAge);
    printf("\n");

    printf("The average weight of males who tested positive is ");
    printf("%d", maleweightsum / malepositivecount);
    printf(" and their average BMI is ");
    printf("%f", malebmisum / (float)malepositivecount);
    printf("\n");

    printf("The average weight for positive females is ");
    printf("%d", femaleweightsum / femalepositvecount);
    printf(" and their average BMI is ");
    printf("%f", femalebmisum / (float)femalepositvecount);
    printf("\n");

    printf("The number of obese Floridians who tested positive are ");
    printf("%d", obesemalesp);
    printf(" males and ");
    printf("%d", obesefemalesp);
    printf(" females, and ");
    printf("%d", eightyplusobese);
    printf(" of them were over 80 or older");
    printf("\n");

    printf("The average BMI for positive cases was distributed into different age groups and gender.");
    printf("\n");
    printf("For males under 30, this was ");
    printf("%f", (float)under30malesum / (float)under30malecount);
    printf(" and ");
    printf("%f", (float)under30femalesum / (float)under30femalecount);
    printf(" for females");

    printf("\n");
    printf("For males between 30 and 60, this was ");
    printf("%f", (float)thirtytosixtymalesum / (float)thirtyptosixtymalecount);
    printf(" and ");
    printf("%f", (float)thirtytosixtyfemalesum / (float)thirtyptosixtyfemalecount);
    printf(" for females");

    printf("\n");
    printf("Lastly for males over 60, this was ");
    printf("%f", (float)sixtyplusmalesum / (float)sixtypplusmalecount);
    printf(" and ");
    printf("%f", (float)sixtyplusfemalesum / (float)sixtyplusfemalecount);
    printf(" for females");

    printf("\n");
    printf("\n");
    printf("Overall, this cases study showed that an average of ");
    printf("%f", averageinfected * 100);
    printf("%%");
    printf(" of people tested positive for the virus");





/* End of Program */


    return 0;
}
