#include <stdio.h>
int main() {
    /* Write a program to print all prime numbers from 1 to 99 */
    int i, j;
    
    // This outer loop is our number scout. It goes from 2 up to 99,
    // picking one number at a time to see if it's worthy of being a prime.
    for (i = 2; i <= 99; i++) {
        // This inner loop is the number's test. We check if it's divisible
        // by any number smaller than itself, starting from 2.
        for (j = 2; j <= i; j++) {
            // The moment we find a divisor, we know it's not a prime number.
            // There's no point in continuing the test, so we `break` out of the inner loop.
            if (i % j == 0) {
                break;
            }
        }
        
        // After the inner loop, we check if the test was a success.
        // If the inner loop completed without `break`ing, it means it never found a divisor,
        // so `i` is still equal to `j`, and the number is a prime.
        if (i == j) {
            printf("%d is prime number \n", i);
        }
    }
    return 0;
}