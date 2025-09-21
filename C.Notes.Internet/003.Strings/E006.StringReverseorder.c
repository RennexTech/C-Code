#include<stdio.h>
#include<string.h> // We include this for the `strlen()` function.

int main()
{
    // Declares a character array `str` with a capacity of 50.
    // This is where we'll store the string the user enters.
    char str[50];
    int len;

    // Prompts the user to enter a string.
    printf("Enter a string: ");
    
    // `gets()` reads a line of text from the keyboard and stores it in `str`.
    // NOTE: `gets()` is considered unsafe and is deprecated because it can lead
    // to buffer overflows if the user enters a string longer than 49 characters.
    // A safer alternative is `fgets(str, 50, stdin)`.
    gets(str);

    // This `for` loop prints the string in reverse.
    // 1. `len = strlen(str) - 1`: We start our loop counter at the last character's index.
    // `strlen()` gives us the total number of characters, so we subtract 1 to get the last index.
    // 2. `len >= 0`: The loop continues as long as `len` is not less than zero.
    // 3. `len--`: After each character is printed, we decrement `len` to move backward through the string.
    for (len = strlen(str) - 1; len >= 0; len--)
    {
        // Prints the character at the current index `len`.
        printf("%c", str[len]);
    }

    return 0;
}

// Discomfort is the gateway to high mental functioning. 

// Fasting, No entertainment, remove your ethernet cable and code offline. 

// Go outside and sit on the city bench and chill without music in your ears. 

// Go outside without earphones or headphones. Just walk. Wear some sunglasses.

// Sunglasses save you mental energy spent on looking at people. 

// You can walk while thiking about your code without thinking what they think when looking at you thinking🤣

// This is Nick's manual for human optimization😂