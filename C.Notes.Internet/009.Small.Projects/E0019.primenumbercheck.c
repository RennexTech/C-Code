#include <stdio.h>
int main() {
    int i, n, isprime = 0;
    printf("Enter the number to check prime:");
    scanf("%d", &n);
    
    // We're checking for divisors from 2 up to the square root of the number.
    // The `i <= n / i` check is a cool little trick to avoid having to use `sqrt()`.
    // It's like finding a partner in a pair—if you find one, you've found both,
    // so you don't need to look any further.
    for (i = 2; i <= n / i; i++) {
        if (n % i == 0) {
            printf("Number is not prime\n");
            // As soon as we find one divisor, we know it's not a prime number,
            // so we set our flag and exit the loop immediately. No need to keep checking.
            isprime = 1;
            break;
        }
    }
    
    // We add a special check for 0 and 1 here, as they are not considered prime numbers.
    if (n <= 1) {
        isprime = 1;
    }

    if (isprime == 0) {
        printf("Number is prime\n");
    }
    return 0;
}

// Remember! Drop the talking with AI or planning shit, start it immediately, just do this...

// Write down what you want to do.. JS and react afterwards. 

// Okay, open one AI window say Gemini. 

// Get some few books pdfs online. Upload to gemini, ask it to decode which one is recent and best covering like 80% of that stuff.

// Go through all those books, I usually download 10+ books for a single subject eg JS and do that. 

// After the analysis, I know which ones to delete 99% only remain with one or two. 

// Open VSCode, code, ask AI for questions, move on. 