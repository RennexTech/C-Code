#include<stdio.h>

int main()
{
    // Declares a character array (a string) named `str` and initializes it with the word "India".
    // In C, a string is just an array of characters that ends with a special null terminator (`\0`).
    // Think of it as a row of connected boxes, each holding one letter, with a final "empty" box to signal the end.
    char str[] = "India";

    // This `for` loop is our core logic. It's a standard and efficient way to process a string.
    // Let's break down the loop's three parts:
    // 1. `int i = 0`: We start our counter `i` at 0, pointing to the first character.
    // 2. `str[i] != '\0'`: This is the condition. The loop keeps going as long as the character at `str[i]` is not the null terminator. When it finds the `\0`, the loop stops.
    // 3. `i++`: After each loop, we increment `i` to move to the next character in the array.
    for (int i = 0; str[i] != '\0'; i++)
    {
        // This line prints the character at the current position `i`.
        // `str[i]` accesses the value inside the box at position `i`.
        printf("Character = %c\t", str[i]);

        // This line prints the memory address of that character.
        // The `&` operator gives us the physical location of the box `str[i]`.
        // Notice how these addresses are sequential, proving that the characters are stored next to each other.
        printf("Address = %p\n", &str[i]);
    }

    return 0;
}

// WORDS OF WISDOM: Make sure you're not just reading these notes, ask AI for like 10 to 20 questions per subtopic, that's how you learn coding, by doing stuff.

// Understanding coding isn't about showing off a lot of lines, its building something functional based on your skills: beginner, intermediate, advanced or elite. 



