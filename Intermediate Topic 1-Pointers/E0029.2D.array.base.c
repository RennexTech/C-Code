#include <stdio.h>

int main() {
    // We'll use a 2D array exactly like the one you've been using.
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    /*
     *
     * ## The Beginner's View: The Table
     *
     * To a beginner, `arr[0]` is the first row, `arr[1]` is the second, and
     * `arr[2]` is the third. You think of it as a logical grid.
     *
     * ## The Pro's View: The Pointers
     *
     * An advanced user knows that `arr` is just a pointer to the start of the entire
     * block of memory. When you say `arr[0]`, `arr[1]`, or `arr[2]`, the compiler
     * is performing a hidden calculation.
     *
     * `arr[0]` is the base address of the 0th 1D array (the first row).
     * `arr[1]` is the base address of the 1st 1D array (the second row).
     * `arr[2]` is the base address of the 2nd 1D array (the third row).
     *
     * The `*(arr + i)` syntax is the explicit way of doing this calculation.
     * It says: "Take the base address of the 2D array (`arr`), add `i` groups
     * of 1D arrays, and then dereference that to get the base address of that row."
     *
     * On a system where `int` is 4 bytes, a row has 4 integers, so a row is 16 bytes.
     *
     * `*(arr + 0)` -> base address of row 0
     * `*(arr + 1)` -> base address + (1 * 16 bytes) -> base address of row 1
     * `*(arr + 2)` -> base address + (2 * 16 bytes) -> base address of row 2
     *
     */
    printf("## Comparing arr[i] and *(arr + i)\n");
    printf("------------------------------------------\n");

    for (int i = 0; i < 3; i++) {
        // Here we use both methods to show they yield the same addresses.
        printf("Address of row %d:\n", i);
        printf("  Using arr[%d]: %p\n", i, (void*)arr[i]);
        printf("  Using *(arr + %d): %p\n", i, (void*)*(arr + i));
        printf("\n");
    }

    /*
     *
     * ## Pro-Level Analysis: Why This Matters
     *
     * This might seem like a small detail, but it is the foundation of
     * how all array access works in C. This concept is the first thing you'll
     * need to recognize when you're doing **firmware analysis** or **malware
     * research**. You will often see a raw memory address, and you need to
     * figure out what it points to.
     *
     * For example, in Android kernel code, a driver might have a 2D array that
     * holds device configurations. When a function needs to access a specific
     * row of that data, you won't see `config_table[i]`. Instead, you'll see
     * an assembly instruction that calculates the address of the `i`th row
     * and stores it in a register. Recognizing that pattern is how you
     * understand what the code is doing. It's the difference between
     * seeing random numbers and seeing a data structure.
     *
     */
    
    return 0;
}
