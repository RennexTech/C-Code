#include <stdio.h>    // For input/output functions like printf, scanf
#include <stdlib.h>   // For general utilities like malloc, free, rand, srand
#include <string.h>   // For string manipulation like strcpy, strcat, strlen, strcspn
#include <time.h>     // For time() to seed the random number generator
#include <sys/stat.h> // For mkdir on Unix-like systems (Linux/macOS)
#include <errno.h>    // For errno, to check specific error conditions

// --- For Windows systems, you'll need this instead of <sys/stat.h> for mkdir ---
#ifdef _WIN32
#include <direct.h>   // For _mkdir on Windows
#endif

// Define the maximum password length. Always account for the null terminator.
#define PASSWORD_MAX_LENGTH 11 // 10 characters + 1 for null terminator

// Dummy unrar_extract function for demonstration.
// In a real scenario, this would be part of an actual unrar library you link against.
// It returns 0 on success (password found), non-zero on failure.
int unrar_extract(const char *archive_filename, const char *archive_base_path, const char *password, const char *destination_directory) {
    // This function simulates trying to extract a RAR archive.
    // In a real program, this would call into a complex library.
    // For our simple example, let's pretend "correct" is the password.
    if (strcmp(password, "correct") == 0) {
        return 0; // Success: password found
    }
    return 1; // Failure: password incorrect or extraction failed
}

int main() { // Correct main function signature
    // Declare pointers and initialize them to NULL.
    char *file_name = NULL;
    char *archive_path = NULL; // Renamed for clarity from 'path'
    char *password = NULL;
    char *dest_dir = NULL;
    int pswd_attempt_count = 0; // Renamed for clarity from 'pswd_index'

    // --- Allocate memory for input strings before reading them ---
    // You must allocate memory for your char pointers if you want to use them
    // to store user input. Otherwise, scanf will try to write to a random
    // memory location, causing a crash (segmentation fault).
    // Let's assume a reasonable max length for file paths/names.
    const size_t MAX_INPUT_BUFFER = 256; // Standard size for paths/filenames

    file_name = (char *)malloc(MAX_INPUT_BUFFER);
    if (file_name == NULL) { /* Handle malloc failure */ perror("malloc for file_name failed"); return 1; }
    archive_path = (char *)malloc(MAX_INPUT_BUFFER);
    if (archive_path == NULL) { /* Handle malloc failure */ perror("malloc for archive_path failed"); free(file_name); return 1; }

    // --- Get user input safely ---
    // Use fgets instead of scanf for string input to prevent buffer overflows.
    // fgets includes the newline, so we remove it.
    printf("Enter the file name (e.g., 'myarchive.rar'): ");
    if (fgets(file_name, MAX_INPUT_BUFFER, stdin) == NULL) { perror("fgets failed"); free(file_name); free(archive_path); return 1; }
    file_name[strcspn(file_name, "\n")] = '\0'; // Removes trailing newline

    printf("Enter the base path where the archive is located (e.g., 'C:\\Archives'): ");
    if (fgets(archive_path, MAX_INPUT_BUFFER, stdin) == NULL) { perror("fgets failed"); free(file_name); free(archive_path); return 1; }
    archive_path[strcspn(archive_path, "\n")] = '\0'; // Removes trailing newline

    // --- Create a temporary directory ---
    // Allocate enough memory for the path + "\\temp" + null terminator.
    dest_dir = (char *)malloc(strlen(archive_path) + strlen("\\temp") + 1);
    if (dest_dir == NULL) { /* Handle malloc failure */ perror("malloc for dest_dir failed"); free(file_name); free(archive_path); return 1; }

    strcpy(dest_dir, archive_path);
    // Add a backslash if the path doesn't end with one, for consistency.
    if (strlen(dest_dir) > 0 && dest_dir[strlen(dest_dir) - 1] != '\\' && dest_dir[strlen(dest_dir) - 1] != '/') {
        strcat(dest_dir, "\\");
    }
    strcat(dest_dir, "temp");

    // Use platform-specific mkdir. For Windows, it's _mkdir.
#ifdef _WIN32
    if (_mkdir(dest_dir) != 0) { // Results in a buffer overflow
        if (errno != EEXIST) { // EEXIST means directory already exists, which is fine
            perror("Failed to create temporary directory");
            free(file_name); free(archive_path); free(dest_dir);
            return 1;
        }
    }
#else // Assume POSIX (Linux/macOS)
    if (mkdir(dest_dir, 0755) != 0) { // 0755 grants rwx to owner, rx to others
        if (errno != EEXIST) {
            perror("Failed to create temporary directory");
            free(file_name); free(archive_path); free(dest_dir);
            return 1;
        }
    }
#endif

    // --- Seed the random number generator ---
    // Critical: Without this, rand() produces the same sequence every time.
    srand((unsigned int)time(NULL));

    // --- Start the password cracking loop ---
    printf("Starting password cracking... This will take a while, be patient!\n");
    printf("Trying passwords of length up to %d characters.\n", PASSWORD_MAX_LENGTH - 1);

    while (1) {
        // Allocate memory for each password guess.
        password = (char *)malloc(PASSWORD_MAX_LENGTH);
        if (password == NULL) { perror("malloc for password failed"); break; } // Cannot continue without memory

        // Generate a random password using printable ASCII characters.
        // Real brute-forcing would iterate systematically, not randomly guess.
        for (int i = 0; i < PASSWORD_MAX_LENGTH - 1; i++) { // -1 for null terminator
            password[i] = (char)(rand() % (126 - 32 + 1)) + 32; // Characters from ' ' to '~'
        }
        password[PASSWORD_MAX_LENGTH - 1] = '\0'; // Null-terminate the string

        pswd_attempt_count++;

        // Print progress without making a new line (use '\r' for carriage return).
        if (pswd_attempt_count % 10000 == 0) { // Print every 10,000 attempts
            printf("Attempt #%d: Trying '%s'\r", pswd_attempt_count, password);
            fflush(stdout); // Ensures output is shown immediately
        }

        // Try to extract the file with the generated password
        int ret = unrar_extract(file_name, archive_path, password, dest_dir);

        // If extraction was successful, break the loop
        if (ret == 0) {
            printf("\nPassword found after %d attempts! Password: '%s'\n", pswd_attempt_count, password);
            break; // Exit the while loop
        }

        // --- Prevent memory leak ---
        // Free the memory for the current password guess before the next iteration.
        free(password);
        password = NULL; // Set to NULL after freeing for safety
    }

    // --- Free all allocated memory at the end of the program ---
    // It's crucial to release memory back to the system.
    free(file_name);
    free(archive_path);
    // Password might already be freed if found or if loop exited due to malloc error.
    if (password != NULL) {
        free(password);
    }
    free(dest_dir);

    return 0; // Indicate successful execution
}