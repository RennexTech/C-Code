#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>   // _mkdir for Windows
#else
#include <sys/stat.h> // mkdir for Linux/macOS
#endif

#define TARGET_PASSWORD_LENGTH 5

// Clear input buffer to prevent leftover chars messing with input
void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// This mocks the "unrar extraction" by checking if the password matches.
// Return 0 if matched, 1 otherwise.
int mock_unrar_extract(const char* file_name, const char* path, const char* password, const char* dest_dir, const char* target_password) {
    return strcmp(password, target_password) == 0 ? 0 : 1;
}

// Generate a random password of length `length` from printable ASCII chars [33-'!' to 126-'~']
void generate_random_password(char* buffer, int length) {
    for (int i = 0; i < length; i++) {
        buffer[i] = (char)(33 + rand() % (126 - 33 + 1));
    }
    buffer[length] = '\0';
}

// Cross-platform directory creation with basic permissions (777 on UNIX)
int create_directory(const char* dir_path) {
#ifdef _WIN32
    return _mkdir(dir_path);
#else
    return mkdir(dir_path, 0777);
#endif
}

int main() {
    srand((unsigned int)time(NULL)); // Seed RNG once for fresh randomness

    char file_name_buffer[256];
    char path_buffer[256];
    char dest_dir_buffer[512];
    char current_password[TARGET_PASSWORD_LENGTH + 1];

    const char* target_password = "pass1"; // The secret sauce

    printf("--------------------------------------------------\n");
    printf("C Password Cracker Concept (Educational Demo)\n");
    printf("--------------------------------------------------\n");
    printf("Note: Trying to crack the password '%s' (hardcoded).\n", target_password);
    printf("--------------------------------------------------\n");

    printf("Enter the RAR file name (e.g., archive.rar): ");
    if (fgets(file_name_buffer, sizeof(file_name_buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading file name.\n");
        return 1;
    }
    file_name_buffer[strcspn(file_name_buffer, "\n")] = '\0';

    printf("Enter base path for temporary directory (e.g., C:\\temp or /tmp): ");
    if (fgets(path_buffer, sizeof(path_buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading path.\n");
        return 1;
    }
    path_buffer[strcspn(path_buffer, "\n")] = '\0';

    // Build the destination dir path in a cross-platform way
    snprintf(dest_dir_buffer, sizeof(dest_dir_buffer), "%s%s%s",
             path_buffer,
#ifdef _WIN32
             "\\",
#else
             "/",
#endif
             "temp_extracted");

    printf("Attempting to create temp directory: %s\n", dest_dir_buffer);
    if (create_directory(dest_dir_buffer) != 0) {
        fprintf(stderr, "Warning: Could not create directory '%s'. (May already exist or permission denied)\n", dest_dir_buffer);
    } else {
        printf("Temp directory ready.\n");
    }

    long long attempts = 0;

    printf("\nStarting password guessing...\n");
    while (1) {
        generate_random_password(current_password, TARGET_PASSWORD_LENGTH);
        attempts++;

        // Show progress every 100,000 attempts without flooding output
        if (attempts % 100000 == 0) {
            printf("Attempts: %lld - Trying: %s\r", attempts, current_password);
            fflush(stdout);
        }

        if (mock_unrar_extract(file_name_buffer, path_buffer, current_password, dest_dir_buffer, target_password) == 0) {
            printf("\n--------------------------------------------------\n");
            printf("Password found! Cracked after %lld attempts.\n", attempts);
            printf("Password: '%s'\n", current_password);
            printf("--------------------------------------------------\n");
            break;
        }
    }

    return 0;
}


/**
 * 
 * Next Level Ideas for You: 
 * 
 * Add command line args support for password, file name, and temp path instead of prompting — real CLI tool vibes.
 * 
 * Use a dictionary wordlist to generate guesses for smarter cracking.
 * 
 * Implement a timer or max attempts limit with status reporting.
 * 
 * Show ETA estimates based on attempt rate — so user doesn’t have to wait forever clueless.
 * 
 * Save attempt history to a file to resume later (if interrupted).
 * 
 * Use threads with pthread or Windows threads for faster cracking.
 * 
 * Wanna make it faster? Add multi-threading.
 * 
 * Wanna make it smarter? Add dictionaries & patterns.
 * 
 * Wanna make it cooler? Add UI with progress bars and ETA.
 * 
 */