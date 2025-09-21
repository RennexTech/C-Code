#include<stdio.h>

int main()
{
    // We're declaring a character array (a string) named `str` and initializing it with the word "India".
    // C automatically adds a null terminator (`\0`) at the end of this string to mark its end.
    // Think of this as a row of connected boxes, each holding a letter. The last box is special; it's empty, signifying "this is the end."
    char str[] = "India";

    // We're declaring a character pointer `p` and pointing it to the beginning of our string `str`.
    // The name of an array, `str`, is a pointer to its first element.
    // `p` is like a person standing at the start of our row of boxes.
    char *p = str;

    // This `while` loop is our core logic. It continues to run as long as the character
    // the pointer `p` is pointing to (`*p`) is not the null terminator (`\0`).
    // It's like our person walking down the row of boxes, stopping only when they find the special "end" box.
    while (*p != '\0')
    {
        // Inside the loop, we do two things:
        
        // 1. Print the character at the current location.
        // `*p` is the **value** at the address `p` is holding. It's the letter inside the current box.
        printf("Character = %c\t", *p);

        // 2. Print the address of the current location.
        // `p` is the **address** itself. It's the physical location of the current box.
        printf("Address = %p\n", p);

        // Finally, we move our pointer to the next box.
        // `p++` increments the pointer's value, which in this case means it moves forward
        // by the size of a single character (1 byte), to point to the next letter.
        p++;
    }

    return 0;
}