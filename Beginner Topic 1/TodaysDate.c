#include <stdio.h>
#include <time.h>


/*

We use time(NULL) to get the current time in seconds since the epoch (January 1, 1970).

We then use localtime(&currentTime) to convert the current time to a struct tm containing various components of the date and time.

We extract the day, month, and year components from the struct tm and format them using printf to display the date in the "MM/DD/YYYY" format.

*/

int main()
{
    //Get the current time
    time_t currentTime; //This is part of the time.h header
    struct tm *localTime; //What does this struct contain? we'll find out
    currentTime = time(NULL);
    localTime = localtime(&currentTime);

    int day = localTime -> tm_mday;
    int month = localTime -> tm_mon + 1; // Adding 1 because months are 0-based
    int year = localTime -> tm_year + 1900; // Years since 1900
    printf("Today's date is: %02d/%02d/%04d\n", month, day, year);
    return 0;
}
