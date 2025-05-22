#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <string.h>

#ifdef _WIN32
#include <direct.h>
#else
#include <sys/stat.h>
#endif

#define TARGET_PASSWORD_LENGTH 5

void clear_input_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

// Mocks unrar extraction, returns 0 on password match.
int mock_unrar_extract(const char* file_name, const char* path, const char* password, const char* dest_dir, const char* target_password) {
    if (strcmp(password, target_password) == 0) {
        return 0;
    }
    return 1;
}

// Generates random printable ASCII password.
void generate_random_password(char* buffer, int length) {
    for (int i = 0; i < length; i++) {
        buffer[i] = (char)(33 + (rand() % (126 - 33 + 1)));
    }
    buffer[length] = '\0';
}

// Creates directory if it doesn't exist.
int create_directory(const char* dir_path) {
#ifdef _WIN32
    return _mkdir(dir_path);
#else
    return mkdir(dir_path, 0777);
#endif
}

int main() {
    srand((unsigned int)time(NULL));

    char file_name_buffer[256];
    char path_buffer[256];
    char dest_dir_buffer[512];
    char current_password[TARGET_PASSWORD_LENGTH + 1];

    const char* target_password = "pass1";

    printf("--------------------------------------------------\n");
    printf("C Password Cracker Concept (Educational Demo)\n");
    printf("--------------------------------------------------\n");
    printf("Note: This will try to 'crack' the hardcoded password '%s'.\n", target_password);
    printf("--------------------------------------------------\n");

    printf("Enter the RAR file name (e.g., archive.rar): ");
    if (fgets(file_name_buffer, sizeof(file_name_buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading file name.\n");
        return 1;
    }
    file_name_buffer[strcspn(file_name_buffer, "\n")] = '\0';

    printf("Enter the base path for temporary directory (e.g., C:\\temp or /tmp): ");
    if (fgets(path_buffer, sizeof(path_buffer), stdin) == NULL) {
        fprintf(stderr, "Error reading path.\n");
        return 1;
    }
    path_buffer[strcspn(path_buffer, "\n")] = '\0';

    // Construct destination path
    snprintf(dest_dir_buffer, sizeof(dest_dir_buffer), "%s%s%s", path_buffer,
#ifdef _WIN32
             "\\",
#else
             "/",
#endif
             "temp_extracted");

    printf("Attempting to create temporary directory: %s\n", dest_dir_buffer);
    if (create_directory(dest_dir_buffer) != 0) {
        fprintf(stderr, "Warning: Could not create directory '%s'. (May already exist or permission issue)\n", dest_dir_buffer);
    } else {
        printf("Temporary directory created successfully.\n");
    }

    long long pswd_attempts = 0;

    printf("\nStarting password guessing...\n");
    while (1) {
        generate_random_password(current_password, TARGET_PASSWORD_LENGTH);
        pswd_attempts++;

        // Update progress on the same line
        if (pswd_attempts % 100000 == 0) {
            printf("Attempts: %lld - Trying: %s\r", pswd_attempts, current_password);
            fflush(stdout);
        }

        // Check password
        if (mock_unrar_extract(file_name_buffer, path_buffer, current_password, dest_dir_buffer, target_password) == 0) {
            printf("\n--------------------------------------------------\n");
            printf("Password found! After %lld attempts.\n", pswd_attempts);
            printf("Cracked Password: '%s'\n", current_password);
            printf("--------------------------------------------------\n");
            break;
        }
    }

    return 0;
}
