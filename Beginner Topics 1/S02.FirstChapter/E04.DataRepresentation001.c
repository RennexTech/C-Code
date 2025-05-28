/**
 * We can totally avoid scanf and use getchar to get multiple characters from the user using 
 * getchar().
 * 
 */

#include <stdio.h>
#include <stdlib.h> 


#define MAX_WORD_LENGTH 20 // Setting a limit, like a character count for a tweet.

int main() {
    // This program shows how to grab multiple characters from the user,
    // one by one, using getchar(). It's like building a message character
    // by character, instead of just grabbing a whole block.

    char word[MAX_WORD_LENGTH + 1]; // +1 for the null terminator '\0', which marks the end of a C string.
                                    // Think of '\0' as the "end of message" signal.
    int i = 0;                      // Our counter, starting at zero like a fresh score.
    char ch;                        // A temporary box to hold each character we read.

    printf("Enter a short word (max %d characters): ", MAX_WORD_LENGTH);

    // This loop is like a diligent listener, grabbing characters until
    // you hit Enter or we run out of space in our 'word' box.
    while ((ch = getchar()) != '\n' && ch != EOF && i < MAX_WORD_LENGTH) {
        // 'ch = getchar()' reads one character and assigns it to 'ch'.
        // '!=' '\n'' checks if it's not the Enter key.
        // 'ch != EOF' checks if we haven't reached the end of input (like closing the terminal).
        // 'i < MAX_WORD_LENGTH' makes sure we don't overflow our 'word' array.

        word[i] = ch; // Store the character in our 'word' array.
        i++;          // Move to the next spot in the array.
    }

    // After the loop, we need to make sure our 'word' is a proper C string.
    // C strings *must* end with a null terminator ('\0').
    // It's like putting a period at the end of your sentence so everyone knows it's complete.
    word[i] = '\0'; // Add the null terminator at the current position 'i'.

    printf("You entered: %s\n", word); // Now we can print the whole word using %s.

    // If the user typed more characters than MAX_WORD_LENGTH,
    // there might still be leftover characters (including the newline)
    // in the input buffer. We need to clear them out for future inputs.
    // This is like clearing out the chat history so it doesn't mess up the next conversation.
    while (ch != '\n' && ch != EOF) {
        ch = getchar(); // Keep reading and discarding until newline or end-of-file.
    }

    printf("\n"); // Just a little space.

    printf("Enter another single character: ");
    char single_char = getchar(); // Now this getchar() will wait for new input, not the leftover newline.
    printf("You entered: %c\n", single_char);

    return 0; // Program peace out!
}
