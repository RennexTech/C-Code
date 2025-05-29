#include <stdio.h>   // Standard input/output library for printf, fgets
#include <stdbool.h>  // For boolean type (bool, true, false)
#include <string.h>   // For string comparison (strcmp) and string manipulation (strcspn)

/**
 * @brief Clears the standard input buffer.
 *
 * Read and discard characters from stdin until a newline or EOF.
 * This is necessary because leftover input can mess with subsequent input operations.
 */
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF); // Garbage cleanup after user input
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
    // Make sure buffers are big enough, otherwise hackers could overflow them (jk, but for real tho).
    char userName[80];  // User can input up to 80 chars for username
    char password[30];  // Password is limited to 30 chars (because security)
    bool isAuthenticated = false; // Flag to track if login is successful or not

    // --- Step 1: Get Username Input ---
    printf("Enter your first two names: ");
    // Using fgets to safely capture user input (vs scanf which is risky)
    if (fgets(userName, sizeof(userName), stdin) == NULL) {
        printf("Error reading username.\n");
        return 1; // Exit if error
    }
    // Strip the newline that fgets might add (just a housekeeping step)
    userName[strcspn(userName, "\n")] = '\0';

    // --- Step 2: Get Password Input ---
    printf("Enter your password: ");
    // Same thing with the password: fgets prevents buffer overflow
    if (fgets(password, sizeof(password), stdin) == NULL) {
        printf("Error reading password.\n");
        return 1; // Exit if error
    }
    // Strip that pesky newline again
    password[strcspn(password, "\n")] = '\0';

    // --- Step 3: Authenticate User ---
    // strcmp checks if strings match. If they do, it returns 0 (true).
    // Using '&&' to ensure both username and password match.
    if (strcmp(userName, correct_username) == 0 && strcmp(password, correct_password) == 0) {
        isAuthenticated = true; // True if username and password match
    }

    // --- Step 4: Display Login Result ---
    // If authenticated, show the welcome message; otherwise, show the fail message.
    if (isAuthenticated) {
        printf("\nWelcome to Rennex Techlabs software! 🎉\n");
    } else {
        printf("\nLogin failed. Please provide the correct credentials! 🔒\n");
    }

    return 0; // Exit the program cleanly
}
