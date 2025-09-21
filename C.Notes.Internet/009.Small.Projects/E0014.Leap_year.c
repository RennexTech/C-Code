#include <stdio.h>
int main() {
    int year;
    printf("Enter Year \n");
    scanf("%d", &year);
    
    // The rule for a leap year is kind of like a set of VIP passes.
    // To get in, you first have to be divisible by 4.
    // But there's a special rule for years that are also divisible by 100.
    // They get their own check. This nested `if` statement handles that special case.
    if (year % 100 != 0) {
        if (year % 4 == 0) {
            printf("Leap Year \n");
        } else {
            printf("Not Leap Year \n");
        }
    } else {
        // If a year is a century year (like 1900 or 2000), it has to be
        // divisible by 400 to get the VIP pass.
        if (year % 400 == 0) {
            printf("Leap Year \n");
        } else {
            printf("Not Leap Year \n");
        }
    }
    return 0;
}