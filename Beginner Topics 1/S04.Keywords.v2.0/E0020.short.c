/**
 * 
 * short is like int but on a strict diet – smaller range, smaller memory footprint. 
 * 
 * It's perfect for when you're counting things that won't go super high (like the number of people in a small room, or a low score in a game) 
 * 
 * and you're trying to save every precious byte of memory. Less bulk, still counts!
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("21. short\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'short' is like 'int' but on a strict diet – smaller range, smaller memory footprint... Less bulk, still counts!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    short small_count = 150;     // A number within a smaller range
    short student_score = 80;    // A score not exceeding 32,767 (typical max)
    short num_chairs = 12;

    printf("Small Count: %d\n", small_count);
    printf("Student Score: %d\n", student_score);
    printf("Number of chairs: %d\n", num_chairs);
    printf("Size of a short: %zu bytes (usually 2 bytes, smaller than int!)\n", sizeof(short));
    // Try assigning a very large number to 'small_count', e.g., 40000, and see what happens (overflow!)
    // small_count = 40000; // This might cause an overflow warning/error or unexpected value
    sleep(5);
    return 0;
}