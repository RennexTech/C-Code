#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

// Cross-platform directory creation handling:
// Windows uses _mkdir from <direct.h>,
// Linux/macOS use mkdir from <sys/stat.h>
#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

#define TARGET_PASSWORD_LENGTH 5

// Prototypes for neatness & forward declaration
void clear_input_buffer();
int mock_unrar_extract(const char* file_name, const char* path, const char* password, const char* dest_dir, const char* target_password);
void generate_random_password(char* buffer, int length);
int create_directory(const char* dir_path);

void clear_input_buffer() {
    // Sometimes input reads get messy with leftover characters.
    // This eats everything until the next newline to keep input clean.
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// The heart of the demo: simulating password verification
// The "unrar extraction" succeeds ONLY if password matches target_password exactly
int mock_unrar_extract(const char* file_name, const char* path, const char* password, const char* dest_dir, const char* target_password) {
    // strcmp returns 0 if strings are equal — that’s how we detect a match
    if (strcmp(password, target_password) == 0) {
        return 0; // success code
    }
    return 1; // failure code
}

// This function generates a random password guess of fixed length
// It picks characters from the printable ASCII range 33 ('!') to 126 ('~')
// This ensures every guess is a random, visible character password
void generate_random_password(char* buffer, int length) {
    for (int i = 0; i < length; i++) {
        buffer[i] = (char)(33 + (rand() % (126 - 33 + 1)));
    }
    buffer[length] = '\0'; // null-terminate string (super important!)
}

// Creates a directory on disk if it doesn't already exist
// Returns 0 on success, non-zero otherwise
// Handles platform-specific calls
int create_directory(const char* dir_path) {
#ifdef _WIN32
    return _mkdir(dir_path);
#else
    return mkdir(dir_path, 0777); // 0777 = full permissions (rwxrwxrwx)
#endif
}

int main() {
    // Seed RNG once at start with current time to ensure "randomness"
    srand((unsigned int)time(NULL));

    char file_name_buffer[256];
    char path_buffer[256];
    char dest_dir_buffer[512];
    char current_password[TARGET_PASSWORD_LENGTH + 1];

    // This is the "correct password" the cracker tries to find
    // Change this to anything you want to test different scenarios
    const char* target_password = "pass1";

    printf("--------------------------------------------------\n");
    printf("C Password Cracker Concept (Educational Demo)\n");
    printf("--------------------------------------------------\n");
    printf("Heads up! We're gonna try cracking the password '%s'.\n", target_password);
    printf("No real hacking here, just demo vibes.\n");
    printf("--------------------------------------------------\n");

    // Get user input for the "file name"
    if (fgets(file_name_buffer, sizeof(file_name_buffer), stdin) == NULL) {
        fprintf(stderr, "Oops! Error reading file name.\n");
        return 1;
    }
    // Remove trailing newline (very important!)
    file_name_buffer[strcspn(file_name_buffer, "\n")] = '\0';

    // Get user input for the temp directory path
    if (fgets(path_buffer, sizeof(path_buffer), stdin) == NULL) {
        fprintf(stderr, "Oops! Error reading path.\n");
        return 1;
    }
    path_buffer[strcspn(path_buffer, "\n")] = '\0';

    // Build full path for extraction temp dir:
    // Cross-platform path separator
    snprintf(dest_dir_buffer, sizeof(dest_dir_buffer), "%s%s%s", path_buffer,
#ifdef _WIN32
             "\\",
#else
             "/",
#endif
             "temp_extracted");

    printf("Setting up temp directory at: %s\n", dest_dir_buffer);
    if (create_directory(dest_dir_buffer) != 0) {
        fprintf(stderr, "Heads up: Couldn't create '%s'. Maybe it exists or permission denied.\n", dest_dir_buffer);
    } else {
        printf("Temp directory created or already exists.\n");
    }

    long long pswd_attempts = 0; // To handle crazy big number of tries

    printf("\nStarting the password guessing game...\n");

    // Brute force loop: keep guessing until success
    while (1) {
        generate_random_password(current_password, TARGET_PASSWORD_LENGTH);
        pswd_attempts++;

        // Show progress every 100,000 attempts without flooding the console
        if (pswd_attempts % 100000 == 0) {
            printf("Attempts: %lld — Trying: %s\r", pswd_attempts, current_password);
            fflush(stdout); // Force print immediately
        }

        // Test if guess matches the target password
        if (mock_unrar_extract(file_name_buffer, path_buffer, current_password, dest_dir_buffer, target_password) == 0) {
            printf("\n--------------------------------------------------\n");
            printf("Boom! Password cracked after %lld attempts!\n", pswd_attempts);
            printf("The secret password is: '%s'\n", current_password);
            printf("--------------------------------------------------\n");
            break; // Exit the infinite loop — mission complete
        }
    }

    return 0;
}

/**
 * 
 * Bonus Wisdom Nuggets for Your Brain:
 * 
 * Why is the password length fixed?
 * 
 * Because brute forcing longer passwords exponentially blows up attempts — 5 chars vs 8 chars is a huge difference. Your demo keeps it short so you can see it work quickly.
 * 
 * Why random printable ASCII?
 * 
 * Because real-world passwords mix letters, digits, symbols — not just numbers or letters. This simulates a more realistic "guess space" than just digits.
 * 
 * Why mock the extraction?
 * 
 * Actually unrar and trying real extraction is complicated — and OS-dependent. Plus, real password cracking takes hella time and code. This mock lets you focus on the brute-force logic without distractions.
 * 
 * Could this be improved?
 * 
 * Heck yes. Real password crackers use smarter methods — dictionary attacks, heuristics, GPU acceleration. Your code is the foundation: random guesses until lucky.

 */
