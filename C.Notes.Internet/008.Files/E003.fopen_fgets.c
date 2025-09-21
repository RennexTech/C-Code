#include <stdio.h>

int main()
{
    FILE *file_pointer = NULL;
    char str[10]; // Increased the buffer size for safety.

    // Open the file in read mode ("r").
    file_pointer = fopen("Myfile.txt", "r");

    if (file_pointer == NULL)
    {
        printf("Error: Could not open the file.\n");
        return 1;
    }

    // `fgets()` reads a line from the file. It takes three arguments:
    // 1. The buffer to store the string (`str`).
    // 2. The maximum number of characters to read (`sizeof(str)` to prevent overflow).
    // 3. The file pointer (`file_pointer`).
    fgets(str, sizeof(str), file_pointer);

    printf("The string is: %s\n", str);

    fclose(file_pointer);

    return 0;
}