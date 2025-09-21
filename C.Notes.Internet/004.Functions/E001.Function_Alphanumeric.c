// This program counts the total number of alphanumeric characters in a string.

#include <stdio.h>
#include <ctype.h> // We need this header for the `isalnum()` function.

// Function prototype for `ttl_alphanumeric`.
// It takes a string as input and returns the count of alphanumeric characters.
int ttl_alphanumeric(char *input_string);

int main()
{
    // Our string. Let's make it a bit more interesting with numbers and symbols
    // to properly test the `isalnum()` function.
    char my_string[50] = "thenayan1khade23@!$";

    // Call the function and store the returned count.
    int count = ttl_alphanumeric(my_string);

    // Print the final result.
    printf("\nNumber of alphanumerics in \"%s\" is: %d\n", my_string, count);

    return 0;
}

// This function calculates the number of alphanumeric characters.
// `input_string` is a pointer to the first character of the string.
// Think of it as a person (the pointer) walking down a line of characters.
int ttl_alphanumeric(char *input_string)
{
    int counter = 0; // Our counter, starting at zero.
    int i = 0;       // Our index, also starting at zero.

    // The `while` loop checks each character. It keeps going until it hits
    // the null terminator (`\0`), which marks the end of the string.
    while (input_string[i] != '\0')
    {
        // `isalnum()` is a standard library function. It's like a tiny inspector
        // that checks a character. It returns a non-zero value if the character
        // is an alphabet (A-Z, a-z) or a number (0-9). Otherwise, it returns zero.
        if (isalnum(input_string[i]))
        {
            // If the inspector gives a thumbs-up, we add one to our counter.
            counter++;
        }

        // We move the person (our index `i`) to the next character in the line.
        i++;
    }

    // We return the final count.
    return counter;
}


// Always break complex problems into tiny, simple steps.