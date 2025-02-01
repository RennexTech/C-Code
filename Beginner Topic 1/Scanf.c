#include <stdio.h>

/*

Version 2 of the code, we use scanf != 1 so that it can check if it successfully receives an integer, and nothing else
So, when we write scanf("%d", &day) != 1, it means we are checking if scanf didn't successfully read an integer (i.e., it returns a value not equal to 1), which implies that it encountered an error or didn't read the expected input.
If scanf returns 1, it means it successfully read an integer, and the condition is false, so the program proceeds as expected.
If scanf returns something other than 1, it means there was an issue with the input (e.g., the user entered a non-integer value), and the program prints an error message and returns a non-zero exit code to indicate an error.
In summary, != 1 is a way to check for errors in input reading using scanf. If it's not equal to 1, it indicates an error or unexpected input, and appropriate error handling is performed.
There should not be a space between ! and = in the condition. It should be !=, not ! =

*/


int date() //its not using commandline to take input so don't include int argument count and character array of arrays (int argc, char *argv[])
{
    int day, month, year;

    printf("Enter today's date(numbers only): \n");
    if(scanf("%d", &day) != 1)
    {
        printf("Invalid input for day.\n");
        return 1;
    }

    printf("Enter this month(numbers only): \n");
    if(scanf("%d", &month) != 1)
    {
        printf("Invalid input for the month!\n");
        return 1;
    }


    if(month > 12 || month <= 0)
    {

        printf("Month cannot be more than 12 in a year.");
    }
    else{
        switch(month)
        {
        case 1:
            printf("January.");
            break;
        case 2:
            printf("February.");
            break;
        case 3:
            printf("March.");
            break;
        case 4:
            printf("April.");
            break;
        case 5:
            printf("May.");
            break;
        case 6:
            printf("June.");
            break;
        case 7:
            printf("July.");
            break;
        case 8:
            printf("August.");
            break;
        case 9:
            printf("September.");
            break;
        case 10:
            printf("October.");
            break;
        case 11:
            printf("November.");
            break;
        case 12:
            printf("December.");
            break;
        default:
            printf("Hey, you didn't give me a month number! Gerrarahia!");
        }

        printf("\n");

        printf("Enter this year(Numbers only): \n");
        if(scanf("%d", &year) != 1)
        {
            printf("Invalid input for the year!");
            return 1;
        }

        printf("Today is on %d-%d-%d\n", day, month, year);
    }
}

/* The default won't be triggered, so you can modify the code to be this way.

else {
        printf("Hey, you didn't give me a valid month number (1 to 12)! Gerrarahia!\n");
    }

Or even use else if
*/

