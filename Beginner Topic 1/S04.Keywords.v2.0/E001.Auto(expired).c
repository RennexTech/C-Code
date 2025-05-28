/**
 * This keyword is essentially telling the compiler, "Yo, these variables are temporary on the stack." 
 * 
 * The compiler usually replies, "Bruh, don't worry, I'll clean them up. I went to Harvard for that stuff 😂." 
 * 
 * Don't use auto today, it's pretty much expired unless you're in the 1980s. 
 * 
 * Modern compilers already know local variables are temporary, and they vanish when the function exits.
 * 
 */

#include <stdio.h> // For the mic (printf)
#include <time.h>  // For chilling between prints (sleep)
#include <unistd.h> // For sleep on Unix-like systems (Linux, macOS)

int main() {
    printf("--------------------------------------------\n");
    printf("1. auto\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Essentially telling the compiler, 'Yo, these variables are temporary on the stack.', and compiler replies, 'Bruh, don't worry I'll clean them up. I went to Harvard for that stuff😂'. Don't use auto, its already expired unless you're in the 1980s, compiler already knows local variables are temporary. When main exits, they are destroyed.\n");
    printf("\n");

    // Analogy: Writing auto in C in 2025 is like sending an email and saying:
    // "Hey, I just wanted to let you know am emailing you...", huh?
    // The compiler already knows, unless you're in a 1980s PC. Auto is obsolete😴.

    auto int first_number = 20; // 'auto' is optional here; local variables are auto by default.
    int second_number = 30;    // Same thing, just without 'auto'.

    printf("First Number (with auto): %d\n", first_number);
    printf("Second Number (without auto): %d\n", second_number);

    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}