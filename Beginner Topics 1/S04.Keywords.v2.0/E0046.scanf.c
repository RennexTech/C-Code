#include <stdio.h>   // For printf, scanf, getchar - Input and output functions
#include <string.h>  // For strlen - helps us manipulate strings (like trimming newlines)
#include <stdbool.h> // For bool, true, false - makes logic cleaner and more readable
#include <unistd.h>  // For sleep() - lets us pause between outputs for clarity

/**
 * ==============================
 *      scanf: The Input Game
 *   Beginner to Intermediate 🎮
 * ==============================
 *
 * Think of scanf like a club bouncer – it decides what data gets into your program.
 * But not all data enters smoothly. This guide levels you up from basic to more pro
 * scanf techniques so you don't get caught slippin'.
 *
 * --------------------------------------------
 * LEVEL 1: Basic scanf - The Quick Entry 🚀
 * --------------------------------------------
 * - scanf is perfect for grabbing simple inputs like integers or single words.
 *
 * Format Specifiers:
 *   - %d : Integer input ("digit")
 *   - %s : String input, stops at space/tab/newline
 *
 * The '&' Operator:
 *   - Use & with variables like int to give scanf the address to store input.
 *   - Don't use & with arrays like char name[] because array names are pointers already.
 *
 * Buffer Overflow Warning:
 *   - Always limit string input like %49s for char name[50] to avoid overflow.
 *
 * --------------------------------------------
 * LEVEL 2: Robust scanf - Pro Bouncer Moves 💪
 * --------------------------------------------
 * - Check scanf's return values to verify success (scanf returns number of items read).
 *
 * Clearing the Buffer:
 *   - Input often leaves behind a newline ('\n') in the buffer that breaks later reads.
 *   - Use clear_input_buffer() to flush leftover junk.
 *
 * Reading Full Lines:
 *   - Use fgets instead of scanf("%s") when you need to capture strings with spaces.
 *   - fgets reads until newline or max size.
 *
 * Trimming Newline:
 *   - fgets includes the newline character. Trim it for clean outputs or comparisons.
 */

/**
 * Clears the standard input buffer to prevent leftover characters from breaking future input.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

int main() {
    printf("=============================================================\n");
    printf("  scanf: The Input Game - Beginner to Intermediate Vibes 🎮\n");
    printf("=============================================================\n");
    sleep(1);

    // --- Level 1: Basic scanf ---
    printf("\n--- Level 1: Basic scanf (Quick Entry) ---\n");
    printf("Simple one-word inputs. Easy stuff.\n");
    sleep(1);

    int age_simple;
    char name_simple[50]; // Room for 49 characters + null terminator

    printf("Enter your age (e.g., 25): ");
    scanf("%d", &age_simple);
    clear_input_buffer();

    printf("Enter your first name (e.g., John): ");
    scanf("%49s", name_simple); // Prevent buffer overflow
    clear_input_buffer();

    printf("Hello, %s! You are %d years old. (Simple Scan)\n", name_simple, age_simple);
    sleep(2);

    // --- Level 2: Robust scanf ---
    printf("\n--- Level 2: Robust scanf (Pro Bouncer Moves) ---\n");
    printf("Handling tricky inputs like a boss.\n");
    sleep(1);

    int age_robust;
    char full_name[100]; // Plenty of space for full names

    printf("Enter your age (e.g., 30): ");
    int scanned_age = scanf("%d", &age_robust);

    if (scanned_age != 1) {
        printf("---------------------------------------------\n");
        printf("ERROR: Invalid age input. Not a number! 🚫\n");
        printf("---------------------------------------------\n");
        clear_input_buffer();
        return 1;
    }
    clear_input_buffer();

    printf("Enter your FULL name (e.g., Jane Doe): ");
    if (fgets(full_name, sizeof(full_name), stdin) == NULL) {
        printf("---------------------------------------------\n");
        printf("ERROR: Couldn't read your full name. 😬\n");
        printf("---------------------------------------------\n");
        return 1;
    }

    // Remove trailing newline from fgets
    size_t len = strlen(full_name);
    if (len > 0 && full_name[len - 1] == '\n') {
        full_name[len - 1] = '\0';
    }

    printf("---------------------------------------------\n");
    printf("What up, %s! You are %d years old. (Robust Scan)\n", full_name, age_robust);
    printf("---------------------------------------------\n");
    sleep(2);

    printf("\n=============================================================\n");
    printf("That's a wrap on scanf! You're now equipped to handle C inputs like a pro. ✨\n");
    printf("=============================================================\n");
    sleep(1);

    return 0;
}
