#include <stdio.h>

int main()
{
    // A file pointer is a special variable that stores the memory address of the file
    // that your program is interacting with. It's like a handle to the file.
    FILE *file_pointer = NULL;

    // This is the string we want to write to the file.
    // Note: I've corrected the spelling of "produced".
    char content_string[] = "This content was produced by Nick.";

    // `fopen()` opens a file. It takes two arguments:
    // 1. The filename ("Myfile.txt").
    // 2. The mode ("w" for write).
    // The "w" mode means:
    // - If the file exists, its current content will be completely erased.
    // - If the file does not exist, it will be created.
    file_pointer = fopen("Myfile.txt", "w");

    // It's a critical best practice to check if the file was opened successfully.
    // `fopen()` returns `NULL` if there's an error (e.g., no write permissions).
    if (file_pointer == NULL)
    {
        printf("Error: Could not open the file for writing.\n");
        return 1; // Return a non-zero value to signal an error.
    }

    // `fprintf()` is similar to `printf()`, but it writes formatted output to a file.
    // The first argument is the file pointer.
    fprintf(file_pointer, "%s", content_string);

    // After you're done, you **must** close the file using `fclose()`.
    // This flushes any buffered data to the file and releases the resources.
    fclose(file_pointer);

    printf("Content successfully written to Myfile.txt\n");

    return 0;
}