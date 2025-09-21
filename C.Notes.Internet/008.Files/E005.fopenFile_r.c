#include <stdio.h>

int main()
{
    FILE *file_pointer = NULL;
    
    // The buffer size is small, making it vulnerable to buffer overflows if the string in the file is too long.
    char string[34]; 

    // Open the file in read mode ("r").
    file_pointer = fopen("Myfile.txt", "r");

    if (file_pointer == NULL)
    {
        printf("Error: Could not open the file.\n");
        return 1;
    }
    
    // `fscanf()` reads formatted input from a file. It stops reading at whitespace.
    // This makes it easy to read words, but risky for full lines or large strings.
    fscanf(file_pointer, "%s", string);

    printf("The content of the file's first word is: %s\n", string);
    
    // Close the file.
    fclose(file_pointer);

    return 0;
}

// This function can be unsafe because it doesn't have a built-in way to prevent buffer overflows if the input string is larger than the buffer.