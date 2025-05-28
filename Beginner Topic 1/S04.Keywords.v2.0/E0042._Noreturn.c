/**
 *
 * _Noreturn is a promise: “This function will never come back.”
 *
 * It’s used for things like exit(), fatal errors, or infinite loops — stuff that terminates the program or never ends.
 *
 * Helps compilers optimize and issue warnings when needed.
 *
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdnoreturn.h>

_Noreturn void fatal_error(const char* message) {
    printf("FATAL ERROR: %s\n", message);
    exit(1); // Ends the program, never returns
}

int main() {
    printf("--------------------------------------------\n");
    printf("42. _Noreturn\n");
    printf("--------------------------------------------\n");
    printf("'_Noreturn' means the function doesn’t return. Useful for error handling or exit routines.\n");
    printf("--------------------------------------------\n");

    fatal_error("Something went terribly wrong!");

    // Code below won't be executed
    printf("You’ll never see this message.\n");
    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>       // For printf
#include <stdlib.h>      // For exit()
#include <stdnoreturn.h> // For _Noreturn
#include <unistd.h>      // For sleep

/**
 * * _Noreturn is a warning sign for the compiler: 
 * * 'This function? It's a one-way trip! It will NEVER return to where it was called.' 
 * * Think of `exit()` or `abort()`. 
 * * It helps the compiler optimize and catch errors if you accidentally expect it to return. 
 * * Once you call it, the program is done, no coming back to the calling point.
 * */

// This function is marked as _Noreturn because it will terminate the program
_Noreturn void critical_error_exit(int error_code) {
    printf("--- Critical Error Detected! 🚨 ---\n");
    printf("Error Code: %d\n", error_code);
    printf("Initiating emergency shutdown. Program will now exit. 💥\n");
    sleep(2); // Give time for message to display
    exit(error_code); // This function *never* returns to main
}

int main() {
    printf("--------------------------------------------\n");
    printf("42. _Noreturn (C11)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("This function? It's a one-way trip! It will NEVER return to where it was called.' Think of `exit()` or `abort()`. It helps the compiler optimize and catch errors if you accidentally expect it to return.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Starting normal program flow...\n");
    sleep(1);
    printf("Doing some important calculations...\n");
    sleep(1);

    // Uncomment the line below to see _Noreturn in action!
    // The program will terminate immediately after this call.
    printf("\nAbout to call a _Noreturn function (program will end here if uncommented):\n");
    // critical_error_exit(1); // Uncomment this line to run the exit function

    printf("If you see this, the _Noreturn function was NOT called (or it's a conceptual demo).\n");
    printf("Program finished normally.\n");

    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
