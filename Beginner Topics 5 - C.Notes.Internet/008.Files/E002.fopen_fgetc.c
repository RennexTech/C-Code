#include <stdio.h>

int main()
{
    FILE *file_pointer = NULL;
    char character;

    // Open the file in read mode ("r").
    file_pointer = fopen("Myfile.txt", "r");

    // It's always a good idea to check if the file was opened.
    if (file_pointer == NULL)
    {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    // `fgetc()` reads a single character from the file and returns it.
    character = fgetc(file_pointer);

    printf("The character I read was: %c\n", character);

    // Close the file.
    fclose(file_pointer);

    return 0;
}