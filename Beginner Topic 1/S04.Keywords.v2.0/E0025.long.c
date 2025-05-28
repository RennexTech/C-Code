/**
 * 
 * long is like int's bigger, buff cousin. 
 * 
 * You know how int is great for regular whole numbers? 
 * 
 * Well, long is for when your numbers get absolutely massive – like trying to count every single pixel 
 * 
 * on your 8K monitor, or maybe the total number of gigabytes on all your hard drives combined. 
 * 
 * If a regular int box isn't big enough, you use long so your number doesn't overflow and 
 * 
 * crash your program's dreams. It grabs more memory bytes to fit those colossal values. 
 * 
 * For example, if you were storing a really huge number of long_distance_calls, 
 * 
 * you'd use long: long really_big_number_of_calls = 2000000000L; // That 'L' tells C it's a long number!
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("18. long\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'long' is like int's bigger, buff cousin... It grabs more memory bytes to fit those colossal values.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    long population_of_earth = 8000000000L; // Use 'L' for long integer literals
    long distance_to_moon_km = 384400L;
    long large_file_size_bytes = 5000000000LL; // Use 'LL' for long long if even bigger!

    printf("Estimated Earth Population: %ld\n", population_of_earth);
    printf("Distance to Moon (km): %ld\n", distance_to_moon_km);
    printf("Large File Size (bytes): %lld (using long long for even bigger numbers)\n", large_file_size_bytes);
    printf("Size of a long: %zu bytes (usually 8 bytes, bigger than int!)\n", sizeof(long));
    printf("Size of a long long: %zu bytes\n", sizeof(long long));
    sleep(5);
    return 0;
}