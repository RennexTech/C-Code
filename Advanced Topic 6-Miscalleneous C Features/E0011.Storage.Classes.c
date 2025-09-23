#include <stdio.h>

/*
 * This program is a hands-on guide to C's storage classes.
 * We will demonstrate the behavior of 'auto', 'register', 'static',
 * and 'extern' using a series of functions.
 *
 * Think of your program's memory as a hotel. Different variables
 * get different types of accommodations based on their storage class.
 */


// --- Section 1: The 'extern' Guest ---
//
// extern is a shared family member. They don't live in this file, but
// we know they exist somewhere else. This is a promise that a global variable
// named 'shared_data' exists in another file and we want to use it here.
// You can't initialize it here, because you're just declaring its existence.
extern int shared_data;

// In a real-world scenario, you would have another file like `globals.c`
// with this line in it:
// `int shared_data = 500;`
// For this single-file demo, we will define it later to show how it works.
int shared_data;


// --- Section 2: The 'auto' and 'register' Guests ---
//
// These are the temporary guests who get a room for the duration of
// the function call. When the function ends, they check out, and their
// "stuff" (data) is gone.
//
// `auto` is the default storage class, so you rarely see it typed out.
// `register` is a special request for a super-fast room right next to
// the CPU's front desk.
void temporary_guests_demo() {
    printf("--- Temporary Guests Demo (auto and register) ---\n");
    // 'auto' is the default, so we don't need to write `auto int temp_count`.
    // It's like booking a standard room.
    int auto_count = 0;
    
    // The `register` keyword is a request to the compiler to store this variable
    // in a CPU register for blazing fast access. It's like asking for a VIP
    // suite right next to the processor. The compiler might ignore this request
    // if all registers are busy, but it's a strong hint.
    register int register_count = 0;

    auto_count++;
    register_count++;

    // They are created and destroyed every time the function is called.
    printf("auto_count: %d, register_count: %d\n", auto_count, register_count);
    printf("When this function ends, these variables will be gone.\n\n");
}


// --- Section 3: The 'static' Residents ---
//
// These are the long-term residents. Their room (memory) is allocated
// once and they stay there for the entire duration of the program, even
// after the function they are in finishes. Their value is preserved.
// This is what `static` (local) is all about.
void static_resident_demo() {
    printf("--- Static Resident Demo (static local) ---\n");
    
    // This variable gets its room once and its value is remembered.
    // Its initial value is guaranteed to be 0 (Zero).
    static int persistent_counter = 0;
    
    // Each time you call this function, the counter goes up from its last value.
    persistent_counter++;
    
    printf("Persistent Counter: %d\n", persistent_counter);
    printf("The value will be remembered for the next time this function is called.\n\n");
}

// --- Section 4: The Shared Family (static global and extern) ---
//
// Now let's talk about the variables that can be shared across multiple
// functions or even multiple files.
//
// `static` (global) is a resident who lives in this specific building
// but is not allowed to be introduced to residents in other buildings.
// Its scope is limited to this file.
//
// `extern` is a resident in another building that we have a reference to.
// We can use their name and their data in our building.

// This 'global_counter' is shared among all functions in this file.
// It's like a shared resource on the ground floor.
int global_counter = 0;

// This `static` global is local to this file only.
// Other files can't see it, even if they try to declare an `extern` for it.
// It's like a private staff room.
static int private_data = 100;

// This function will show how global and extern variables are handled.
void shared_family_demo() {
    printf("--- Shared Family Demo (global and extern) ---\n");
    
    // We can access this global variable from anywhere in this file.
    global_counter++;
    
    // We can access this external variable because we declared it with `extern`.
    shared_data++;
    
    printf("global_counter is now: %d\n", global_counter);
    printf("shared_data from another file is now: %d\n", shared_data);
    printf("private_data (static global) is: %d\n", private_data);
    printf("\n");
}


int main() {
    // We will call the demo functions to show their behavior.
    
    printf("--- First Round of Function Calls ---\n");
    temporary_guests_demo();
    static_resident_demo();
    shared_family_demo();
    
    printf("--- Second Round of Function Calls ---\n");
    printf("Watch what happens to the values...\n");
    temporary_guests_demo(); // The `auto` and `register` guests are back to 0.
    static_resident_demo();  // The `static` resident's counter continues to rise.
    shared_family_demo();    // The shared variables continue to increment.

    // A final check of the global variables to confirm their state.
    printf("--- Final Global Check ---\n");
    printf("Final global_counter: %d\n", global_counter);
    printf("Final shared_data: %d\n", shared_data);
    
    return 0;
}
