/**
 * 
 * Check: The do keyword kicks off a do-while loop — it’s like saying, 
 * 
 * 'I’m gonna run this code at least once, then keep going as long as the vibe (condition) is right.' 
 * 
 * Unlike other loops that check first, this one checks after the action, so it never misses the first round. 
 * 
 * Perfect for when you gotta do the thing before deciding if you should repeat it.
 * 
 */

 #include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("8. do\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'do' keyword kicks off a do-while loop — it’s like saying, 'I’m gonna run this code at least once, then keep going as long as the vibe (condition) is right.' Unlike other loops that check first, this one checks *after* the action, so it never misses the first round. Perfect for when you gotta do the thing before deciding if you should repeat it.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int countdown = 3;

    printf("Starting countdown with a do-while loop:\n");
    do {
        printf("T-minus %d...\n", countdown);
        countdown--;
        sleep(1);
    } while (countdown > 0); // Condition checked AFTER the first run

    printf("Blast off! 🚀\n");

    // Example where condition is false initially but still runs once:
    int zero_count = 0;
    printf("\nNow, a loop where the condition is false initially:\n");
    do {
        printf("This ran at least once, even though zero_count is %d.\n", zero_count);
        zero_count++;
    } while (zero_count > 5); // This condition is false (0 > 5 is false)

    printf("Loop finished.\n");
    sleep(5);
    return 0;
}