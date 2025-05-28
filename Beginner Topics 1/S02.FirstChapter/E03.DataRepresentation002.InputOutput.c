#include <stdio.h>  
#include <stdlib.h> // We're not really using this one right now, it's just vibing in the corner like an unneeded app on your phone.

/**
 * 
 * This is our main event, where all the cool stuff happens.
 * 
 */

int main() {
    // Dropping a text on the screen. printf() lives in the stdio.h header file
    printf("Hello world!\n");

    // --- Time to get some input using this tiny box that can only hold 1 character.
    char ch_input_1;
    printf("Enter the first character: "); // Throw a prompt

    ch_input_1 = getchar(); // This line is chilling, waiting for you to type ONE character and hit Enter. Reads a single character from stdin.
    printf("You entered: %c\n", ch_input_1); // Flexing what you just typed back at you.


    // Okay, this part is super important, don't skip it!
    // When you hit 'Enter' after typing your first character, that 'Enter'
    // itself is also a character (a 'newline' character). 'getchar()' snagged
    // your character, but the 'Enter' is still hanging around in the input 'buffer',
    // like that one unread notification.
    // If we don't clear it, the *next* 'getchar()' would just grab that leftover 'Enter'
    // instead of waiting for *you* to type something new. It'd be like someone
    // else's leftover vibe messing up your next interaction.
    getchar(); // So, we use another 'getchar()' to literally throw away that leftover 'Enter' key.

    char ch_input_2; // Another tiny box for another single character.
    printf("Enter the second character: "); // Asking for another char, like a follow-up question.

    ch_input_2 = getchar(); // Grabbing that second character, now that the path is clear.
    printf("You entered: %c\n", ch_input_2); // Displaying the second character you gave us.

    // --- Now, let's print something more complex, like a detailed caption! ---
    int num = 42; // We've got a number here, like a 'like' count or a score.

    // 'printf' here is like making a custom post. We're mixing regular text
    // with our number ('num'). '%d' is like a placeholder that tells 'printf',
    // "Yo, put a whole number right here!"
    printf("The answer is: %d\n", num);

    return 0; // Everything went smoothly! It's like saying "task complete" or "mission accomplished."
}