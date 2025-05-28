/**
 * 
 * int is how you declare you want an integer variable. 
 * 
 * Like saying: 'Yo compiler, I need a number — no decimals, just raw, whole number.' 
 * 
 * Real life: int age = 24; // That's you. No floating points. 
 * 
 * Memory-wise? 4 bytes of memory space (usually), living on the stack rent-free.
 * 
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("17. int\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("int is how you declare you want an integer variable. Like saying: 'Yo compiler, I need a number — no decimals, just raw, whole number.' Real life: int age = 24; Memory-wise? 4 bytes of memory space (usually), living on the stack rent-free.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int number_of_apples = 5; // A whole number
    int user_age = 25;        // Your age, no decimals
    int year = 2024;          // The current year

    printf("You have %d apples.\n", number_of_apples);
    printf("Your age is %d years.\n", user_age);
    printf("The current year is %d.\n", year);
    printf("Size of an int: %zu bytes (usually)\n", sizeof(int));
    sleep(5);
    return 0;
}