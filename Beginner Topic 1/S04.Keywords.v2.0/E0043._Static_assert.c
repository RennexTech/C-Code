/**
 *
 * _Static_assert is like a compiler-level safety net: it checks a condition **at compile time**.
 *
 * If it fails, your code won’t even compile — like a bouncer saying “you ain’t getting in with those shoes.”
 *
 * Perfect for validating assumptions before runtime.
 *
 */

#include <stdio.h>

_Static_assert(sizeof(int) == 4, "int must be 4 bytes");

int main() {
    printf("--------------------------------------------\n");
    printf("43. _Static_assert\n");
    printf("--------------------------------------------\n");
    printf("'_Static_assert' checks something at compile time. If false, your code won’t even build. 🔒\n");
    printf("--------------------------------------------\n");

    printf("All static assertions passed. You're safe to proceed.\n");
    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>   // For printf
#include <assert.h>  // For _Static_assert
#include <unistd.h>  // For sleep

/**
 * * _Static_assert is your compile-time bouncer! 
 * * It lets you check conditions *before* your code even runs. 
 * * If the condition is false, the compiler throws an error and refuses to build. 
 * * Perfect for catching dumb mistakes early, like 'Is an int always 4 bytes on this system?' 
 * * It's like a pre-flight check for your code, ensuring everything is good before takeoff.
 * */

// This _Static_assert will check a condition at compile time.
// If the condition is false, the compiler will stop and show the error message.
// This example checks if 'int' is 4 bytes. (It might be different on your system, e.g., 8 bytes on some 64-bit systems)
_Static_assert(sizeof(int) == 4, "Error: 'int' is not 4 bytes on this system! Check your compiler/platform.");

// You can have multiple static asserts
_Static_assert(sizeof(char) == 1, "Error: 'char' is not 1 byte!");

// Example of an assert that would FAIL (uncomment to see compile error!)
// _Static_assert(sizeof(long) == 100, "Error: 'long' is NOT 100 bytes! This assert will fail compilation.");

int main() {
    printf("--------------------------------------------\n");
    printf("43. _Static_assert (C11)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Your compile-time bouncer! It lets you check conditions *before* your code even runs. If the condition is false, the compiler throws an error and refuses to build. Perfect for catching dumb mistakes early.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Code reached here, meaning all _Static_asserts passed during compilation! ✅\n");
    sleep(1);
    printf("Size of int on this system: %zu bytes\n", sizeof(int));
    printf("Size of char on this system: %zu bytes\n", sizeof(char));
    sleep(1);

    printf("Note: If you uncomment the failing _Static_assert, your code won't even compile. It's a powerful tool for ensuring assumptions about your environment or data types are correct.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
