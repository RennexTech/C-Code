/**
 * 
 * The const keyword means 'hands off!😤' — once you set a value, it’s locked. 
 * 
 * You can read it, vibe with it, print it, but you can’t change it. 
 * 
 * It’s like putting a sign that says ‘DO NOT TOUCH’ on a variable. 
 * 
 * Great for keeping things safe and avoiding dumb mistakes.
 * 
 * Code Example:
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("5. const\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'const' keyword means 'hands off!😤' — once you set a value, it’s locked. You can read it, vibe with it, print it, but you *can’t* change it. It’s like putting a sign that says ‘DO NOT TOUCH’ on a variable. Great for keeping things safe and avoiding dumb mistakes.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    const float PI = 3.14159; // PI is a constant, cannot be changed
    const int MAX_SCORE = 100; // Max score for a game, fixed

    printf("The constant value of PI is: %f\n", PI);
    printf("The maximum possible score is: %d\n", MAX_SCORE);

    // Try to uncomment the line below and compile! It will throw an error.
    // PI = 3.0; // ERROR: assignment of read-only variable 'PI'

    printf("Attempting to change PI (will cause error if uncommented):\n");
    printf("PI = 3.0; // This line would cause a compile-time error! 🛑\n");
    sleep(5);
    return 0;
}