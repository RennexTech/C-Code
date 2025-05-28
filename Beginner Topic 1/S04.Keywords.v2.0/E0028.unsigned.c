/**
 * 
 * unsigned is like telling your number, 'Hey, you're a positive-vibes-only kind of number!' 
 * 
 * It means this variable can only hold zero or positive whole numbers. 
 * 
 * The cool part? Since it doesn't need to save space for negative signs, 
 * 
 * it can store positive numbers that are twice as big as a regular signed integer! 
 * 
 * Think of it as a number line that starts at zero and only goes to the right. 
 * 
 * Perfect for counting things that can't be negative, like the number of likes on your post.
 * 
 */

#include <stdio.h>
#include <limits.h> // For INT_MAX, UINT_MAX to show ranges
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("29. unsigned\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'unsigned' is like telling your number, 'Hey, you're a **positive-vibes-only** kind of number!'... It can store positive numbers that are twice as big as a regular 'signed' integer!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    unsigned int likes_on_post = 100000; // Can't have negative likes!
    unsigned short pixel_count = 65000; // Large positive number for short range

    printf("Likes on my post: %u\n", likes_on_post); // Use %u for unsigned int
    printf("Pixel count: %hu\n", pixel_count);    // Use %hu for unsigned short

    printf("\nComparison:\n");
    printf("Max value of signed int: %d\n", INT_MAX);
    printf("Max value of unsigned int: %u\n", UINT_MAX); // Roughly double the signed max!

    // Uncommenting the line below will cause a warning/error or unexpected behavior
    // unsigned int negative_likes = -5; // ERROR: assignment of negative value to unsigned type
    printf("Trying to assign a negative value to unsigned int (will cause warning/error if uncommented): \n");
    printf("unsigned int negative_likes = -5; // This is a NO-GO! 🚫\n");

    sleep(5);
    return 0;
}