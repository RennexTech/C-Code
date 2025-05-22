#include <stdio.h>   // Standard input/output library for printf, fgets
#include <stdbool.h> // For boolean type (bool, true, false)
#include <string.h>  // For string comparison (strcmp) and string manipulation (strcspn)

// --- Function Prototypes ---
void clear_input_buffer();

/**
 * @brief Clears the standard input buffer.
 *
 * Reads and discards characters from stdin until a newline or EOF.
 * Prevents leftover characters from affecting subsequent input calls.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Correct username and password for authentication.
const char correct_username[] = "Nick Nicky";
const char correct_password[] = "Programming123";

/**
 * @brief Main function for a simple console login system.
 *
 * Demonstrates basic user input, string comparison, and boolean logic
 * for authentication. In C, 'bool' (from <stdbool.h>) represents
 * true/false, where 0 is false and any non-zero value is true.
 */
int main()
{
    // Variables to store user input.
    // Ensure buffers are large enough to prevent overflow.
    char userName[80];
    char password[30];
    bool isAuthenticated = false; // Flag to track authentication status

    // --- Get Username Input ---
    printf("Enter your first two names: ");
    // fgets reads a line safely, preventing buffer overflow.
    // It includes the newline character if there's space.
    if (fgets(userName, sizeof(userName), stdin) == NULL) {
        printf("Error reading username.\n");
        return 1; // Indicate error
    }
    // Remove the trailing newline character that fgets might include.
    userName[strcspn(userName, "\n")] = '\0';

    // --- Get Password Input ---
    printf("Enter your password: ");
    // For password, fgets is also safer than scanf("%s").
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading password.\n");
        return 1; // Indicate error
    }
    // Remove the trailing newline character.
    password[strcspn(password, "\n")] = '\0';

    // --- Authenticate User ---
    // strcmp returns 0 if strings are identical.
    // Use '&&' for logical AND: both conditions must be true.
    if (strcmp(userName, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        isAuthenticated = true; // Set flag to true if credentials match
    }

    // --- Display Login Result ---
    if (isAuthenticated) {
        printf("\nWelcome to Rennex Techlabs software!\n");
    } else {
        printf("\nLogin failed. Please provide the right credentials!\n");
    }

    return 0; // Indicates successful program execution
}

