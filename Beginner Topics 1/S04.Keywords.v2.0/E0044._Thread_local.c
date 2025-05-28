/**
 *
 * _Thread_local means each thread gets its own copy of this variable.
 *
 * Like a hotel room key — every guest (thread) has their own copy, even though it's the same room type.
 *
 * Prevents shared state issues in multithreaded code.
 *
 */

#include <stdio.h>
#include <threads.h>

_Thread_local int thread_counter = 0;

int thread_func(void* arg) {
    thread_counter++;
    printf("Thread %s counter: %d\n", (char*)arg, thread_counter);
    return 0;
}

int main() {
    printf("--------------------------------------------\n");
    printf("44. _Thread_local\n");
    printf("--------------------------------------------\n");
    printf("'_Thread_local' gives each thread its own version of a variable. No sharing, no clashes.\n");
    printf("--------------------------------------------\n");

    thrd_t t1, t2;
    thrd_create(&t1, thread_func, "A");
    thrd_create(&t2, thread_func, "B");

    thrd_join(t1, NULL);
    thrd_join(t2, NULL);

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>   // For printf
// #include <threads.h> // For thrd_t, thrd_create, etc. (requires C11 <threads.h>)
#include <unistd.h>  // For sleep

/**
 * * _Thread_local is for multi-threading: 'This variable is my personal locker, no one else's!' 
 * * Each thread gets its *own private copy* of this variable. 
 * * No sharing, no conflicts. 
 * * Super useful when threads need their own unique data without stepping on each other's toes. 
 * * It's like giving every worker their own private toolbox on a shared construction site.
 * */

// Declaring a thread-local variable
// Each thread that accesses this variable will have its own unique copy.
_Thread_local int thread_specific_counter = 0;

// A simple function that would be run by multiple threads (conceptual here)
void process_task_concept(int thread_id) {
    printf("  [Thread %d] Initial counter: %d\n", thread_id, thread_specific_counter);
    sleep(1);
    thread_specific_counter++; // This increments *this thread's* copy
    printf("  [Thread %d] Counter after increment: %d\n", thread_id, thread_specific_counter);
}

int main() {
    printf("--------------------------------------------\n");
    printf("44. _Thread_local (C11) (Conceptual Demo)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("For multi-threading: 'This variable is my personal locker, no one else's!' Each thread gets its *own private copy* of this variable. No sharing, no conflicts.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Demonstrating _Thread_local (conceptually, without actual threads here):\n");
    printf("Imagine Thread 1 starts...\n");
    process_task_concept(1); // Simulating Thread 1's execution
    sleep(1);

    printf("\nImagine Thread 2 starts...\n");
    process_task_concept(2); // Simulating Thread 2's execution (it gets its own counter)
    sleep(1);

    printf("\nImagine Thread 1 runs again...\n");
    process_task_concept(1); // Thread 1's counter continues from where it left off
    sleep(1);

    printf("Note: The true power of '_Thread_local' is seen when you have multiple threads running concurrently. Each thread would have its own independent 'thread_specific_counter'. This example just shows the concept.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
