#include <stdio.h>    // For stuff like printing messages and getting user input (printf, scanf)
#include <stdlib.h>   // For the essentials: memory stuff, random numbers, etc.
#include <string.h>   // To handle strings — copying, measuring length, trimming newlines, you name it
#include <time.h>     // To get that sweet, sweet randomness seed (otherwise you get the same lame passwords every time)
#include <sys/stat.h> // To make directories on Linux/macOS (like "mkdir" command)
#include <errno.h>    // To catch and explain errors (like when mkdir throws a tantrum)

// Windows is special, so it needs its own mkdir header
#ifdef _WIN32
#include <direct.h>   // Windows version of mkdir, '_mkdir'
#endif

#define PASSWORD_MAX_LENGTH 11 // 10 characters for the password + 1 for the string terminator '\0'

// This is a fake "try to unzip with this password" function.
// Imagine it like trying keys on a locked treasure chest. Only "correct" opens it.
// Returns 0 if you guess right, else something else.
int unrar_extract(const char *archive_filename, const char *archive_base_path, const char *password, const char *destination_directory) {
    if (strcmp(password, "correct") == 0) {
        return 0; // Jackpot! You found the right password.
    }
    return 1; // Nope, wrong key. Keep trying.
}

int main() {
    // Let's declare some strings for stuff we'll get from the user or create:
    char *file_name = NULL;
    char *archive_path = NULL;
    char *password = NULL;
    char *dest_dir = NULL;
    int pswd_attempt_count = 0; // Counter for how many passwords we've tried so far

    const size_t MAX_INPUT_BUFFER = 256; // Max length for filenames and paths

    // Allocate memory so we don't crash the program when we store user input
    file_name = (char *)malloc(MAX_INPUT_BUFFER);
    if (file_name == NULL) {
        perror("Oops! Couldn't grab memory for the file name");
        return 1;
    }

    archive_path = (char *)malloc(MAX_INPUT_BUFFER);
    if (archive_path == NULL) {
        perror("Memory fail for archive path");
        free(file_name);
        return 1;
    }

    // Get the file name from the user — like "myarchive.rar"
    printf("Tell me the archive file name (e.g., 'myarchive.rar'): ");
    if (fgets(file_name, MAX_INPUT_BUFFER, stdin) == NULL) {
        perror("Input error on file name");
        free(file_name);
        free(archive_path);
        return 1;
    }
    file_name[strcspn(file_name, "\n")] = '\0'; // Get rid of that annoying newline

    // Now ask where that archive lives on your computer
    printf("Where's the archive hiding? Give me the path (e.g., 'C:\\Archives'): ");
    if (fgets(archive_path, MAX_INPUT_BUFFER, stdin) == NULL) {
        perror("Input error on archive path");
        free(file_name);
        free(archive_path);
        return 1;
    }
    archive_path[strcspn(archive_path, "\n")] = '\0'; // No newlines allowed

    // Time to make a temporary "playground" folder to unzip stuff to
    dest_dir = (char *)malloc(strlen(archive_path) + strlen("\\temp") + 1);
    if (dest_dir == NULL) {
        perror("Memory fail for temp directory path");
        free(file_name);
        free(archive_path);
        return 1;
    }

    strcpy(dest_dir, archive_path);

    // Add a backslash if the path doesn't already have one — consistency matters
    if (strlen(dest_dir) > 0 && dest_dir[strlen(dest_dir) - 1] != '\\' && dest_dir[strlen(dest_dir) - 1] != '/') {
        strcat(dest_dir, "\\");
    }
    strcat(dest_dir, "temp");

    // Create that temp directory — it's like building a secret base for your password cracking ops
#ifdef _WIN32
    if (_mkdir(dest_dir) != 0) {
        if (errno != EEXIST) {
            perror("Failed to create the temp folder. Are you sure you have permissions?");
            free(file_name);
            free(archive_path);
            free(dest_dir);
            return 1;
        }
    }
#else
    if (mkdir(dest_dir, 0755) != 0) {
        if (errno != EEXIST) {
            perror("Failed to create the temp folder. Did you forget sudo?");
            free(file_name);
            free(archive_path);
            free(dest_dir);
            return 1;
        }
    }
#endif

    // Seed that random number generator — without this, you'll keep guessing the same "passwords"
    srand((unsigned int)time(NULL));

    printf("Alright, let’s crack this bad boy open. Grab some popcorn, it might take a hot minute...\n");
    printf("We're trying passwords up to %d characters long. No promises, but we'll try our best!\n", PASSWORD_MAX_LENGTH - 1);

    while (1) {
        // Grab some memory to hold the next password guess
        password = (char *)malloc(PASSWORD_MAX_LENGTH);
        if (password == NULL) {
            perror("Memory meltdown on password buffer");
            break; // Can't keep guessing without memory, so bail out
        }

        // Make a random password guess — this is basically like throwing spaghetti at the wall
        for (int i = 0; i < PASSWORD_MAX_LENGTH - 1; i++) {
            // Random printable ASCII char between ' ' (space) and '~' (tilde)
            password[i] = (char)(rand() % (126 - 32 + 1)) + 32;
        }
        password[PASSWORD_MAX_LENGTH - 1] = '\0'; // Always null-terminate strings like a boss

        pswd_attempt_count++;

        // Every 10,000 tries, let’s update the scoreboard — so you don’t fall asleep wondering
        if (pswd_attempt_count % 10000 == 0) {
            printf("Tried %d passwords so far... latest guess: '%s' \r", pswd_attempt_count, password);
            fflush(stdout); // Make sure this prints right now
        }

        // Now try to open the archive with this password guess
        int ret = unrar_extract(file_name, archive_path, password, dest_dir);

        if (ret == 0) {
            // Boom! We got it — password found!
            printf("\nHeck yeah! Password cracked after %d tries. The secret password is: '%s'\n", pswd_attempt_count, password);
            break;
        }

        // Clean up the password memory before trying again — don’t leak memory like a busted pipe
        free(password);
        password = NULL;
    }

    // Wrap up by freeing everything else before we peace out
    free(file_name);
    free(archive_path);
    if (password != NULL) free(password);
    free(dest_dir);

    return 0;
}
