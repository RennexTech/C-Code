#include <stdio.h>

int main()
{
    FILE *file_pointer = NULL;

    // Open the file in read/write mode ("r+"). This mode allows you to
    // read and write to a file. The file must already exist.
    file_pointer = fopen("Myfile.txt", "r+");

    if (file_pointer == NULL)
    {
        printf("Error: Could not open the file. Make sure it exists.\n");
        return 1;
    }
    
    // `fputc()` writes a single character to the file at the current position.
    // It will overwrite the existing content at the beginning of the file.
    fputc('o', file_pointer);

    // `fputs()` writes a string to the file at the current position.
    // The string "This is nayan" will be written immediately after the 'o'.
    fputs("\nThis is nayan\n", file_pointer);

    // Close the file.
    fclose(file_pointer);

    printf("Content successfully written to Myfile.txt\n");

    return 0;
}