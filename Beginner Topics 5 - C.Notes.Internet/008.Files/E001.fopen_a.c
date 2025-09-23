#include <stdio.h>

int main()
{
    // A file pointer is a special variable that points to a file in your system.
    // It's like a handle that allows your program to interact with the file.
    FILE *file_pointer = NULL;

    // This is the string we want to write to the file.
    char content_string[] = "\nThis content was produced by Nayan.";

    // `fopen()` opens the file. It takes two arguments:
    // 1. The filename (`"Myfile.txt"`).
    // 2. The mode (`"a"` for append). If the file doesn't exist, it will be created.
    // The function returns a pointer to the file, which we store in `file_pointer`.
    file_pointer = fopen("Myfile.txt", "a");

    // We check if the file was opened successfully. `fopen()` returns `NULL` on failure.
    if (file_pointer == NULL)
    {
        printf("Error: Could not open the file.\n");
        return 1; // Return a non-zero value to indicate an error.
    }

    // `fprintf()` is like `printf()`, but it writes to a file instead of the console.
    // The first argument is the file pointer. The rest of the arguments are just like `printf()`.
    fprintf(file_pointer, "%s", content_string);

    // It's crucial to close the file after you're done with it to free up resources.
    fclose(file_pointer);

    printf("Content successfully appended to Myfile.txt\n");

    return 0;
}