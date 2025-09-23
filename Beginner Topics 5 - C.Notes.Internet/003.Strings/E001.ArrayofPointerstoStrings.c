#include<stdio.h>

int main()
{
    // This is an array of pointers to characters, which is a common and efficient way to store a list of strings in C.
    // Think of `arrp` as a small notebook with five pages. Each page doesn't contain the full word itself;
    // instead, it holds the memory address (the starting location) of where each word is stored somewhere else.
    // The words "white", "red", etc., are stored as separate, null-terminated character arrays in a special area of memory
    // (often the read-only data section), and `arrp` simply points to them.
    char *arrp[5] = {
        "white",
        "red",
        "green",
        "yellow",
        "blue"
    };

    // This `for` loop goes through each entry in our notebook.
    for (int i = 0; i < 5; i++)
    {
        // This line prints the actual string. The `%s` format specifier tells `printf` to go to the address
        // stored in `arrp[i]` and keep printing characters until it finds a null terminator (`\0`).
        printf("String: %s\n", arrp[i]);

        // This line prints the address of the string. It's the memory location where the first letter of
        // the word is stored. This is the **value** stored on page `i` of our notebook.
        printf("Address of string: %p\n", arrp[i]);

        // This line prints the address of the pointer itself. It's the memory location of page `i` in our notebook.
        // Pointers are variables, and like all variables, they have their own address in memory.
        printf("Address of string is stored at: %p\n", arrp + i);
    }

    return 0;
}