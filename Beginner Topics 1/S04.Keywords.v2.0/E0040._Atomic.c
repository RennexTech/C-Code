/**
 *
 * _Atomic is your built-in guard dog for multi-threaded code.
 *
 * It ensures a variable is accessed atomically — meaning no other thread can sneak in while one is updating it.
 *
 * Perfect for counters, flags, and anything shared across threads without using full locks.
 *
 */

#include <stdio.h>
#include <stdatomic.h>

int main() {
    printf("--------------------------------------------\n");
    printf("40. _Atomic\n");
    printf("--------------------------------------------\n");
    printf("'_Atomic' makes a variable thread-safe without needing a mutex. Great for flags, counters, etc.\n");
    printf("--------------------------------------------\n");

    _Atomic int visitors = 0;

    visitors++;
    visitors++;

    printf("Visitors count: %d (updated atomically)\n", visitors);

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================


#include <stdio.h>    // For printf
#include <stdatomic.h> // For _Atomic (requires C11 or later)
#include <unistd.h>   // For sleep

/**
 * * _Atomic is for multi-threading: 'Yo, this variable is a shared toy, but only ONE thread can touch it at a time!' 
 * * It ensures operations on this variable are indivisible, preventing chaos when multiple parts of your program try to update it simultaneously. 
 * * Crucial for concurrency, but needs a multi-threading setup to truly demo its power.
 * * Think of it as a single-person swing set in a playground with many kids.
 * */

int main() {
    printf("--------------------------------------------\n");
    printf("40. _Atomic (C11)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("This is for multi-threading: 'Yo, this variable is a shared toy, but only ONE thread can touch it at a time!' It ensures operations on this variable are indivisible, preventing chaos when multiple parts of your program try to update it simultaneously. Crucial for concurrency, but needs multi-threading setup to truly demo.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    // Declaring an atomic integer
    // In a real multi-threaded program, multiple threads could try to increment this
    _Atomic int shared_counter = 0;

    printf("Initial shared counter: %d\n", shared_counter);
    sleep(1);

    // Incrementing an atomic variable is guaranteed to be safe from race conditions
    // even if multiple threads try to do it at the same time.
    shared_counter++; // This operation is atomic
    printf("Shared counter after one increment: %d\n", shared_counter);
    sleep(1);

    shared_counter += 5; // This operation is also atomic
    printf("Shared counter after adding 5: %d\n", shared_counter);
    sleep(1);

    printf("Note: The true power of '_Atomic' is seen in multi-threaded programs where multiple parts of your code run simultaneously. It prevents data corruption. This simple example just shows its declaration.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
