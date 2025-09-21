#include <stdio.h>

/*
 *
 * Don't worry, from E0017, I made new code coz I forgot what files the images belonged to. 
 * 
 * ## The Pointer's Path: Navigating a 2D Array
 *
 * In C, a 2D array is fundamentally an array of 1D arrays. It's not a true grid in memory.
 * Instead, all the rows are laid out end-to-end, one after another, in a continuous block.
 *
 * This means you can use pointer arithmetic to navigate the entire structure without
 * ever using a double-subscript. This is what's happening under the hood anyway; the
 * compiler is just translating your simple `arr[i][j]` syntax into a more complex
 * pointer expression.
 *
 * For a reverse engineer, understanding this translation is key. In a disassembled
 * program, you won't see `arr[i][j]`. You'll see a series of low-level instructions
 * that perform exactly this kind of pointer math to calculate the memory address of
 * a specific element. Learning to recognize this pattern is a huge step in understanding
 * what a program is doing.
 *
 */

int main() {
    // A 3x4 2D array.
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    printf("## Logical View: Accessing Elements with `arr[i][j]`\n");
    printf("--------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("--------------------------------------------------\n\n");

    /*
     *
     * ## The Pointer Magic: The Analogous Expressions
     *
     * Let's break down the pointer expressions, just like your diagram showed.
     * We'll print the addresses and values to prove they are identical to the
     * `arr[i][j]` version.
     *
     * `arr`            : The name of the array, which points to the base address
     * of the entire 2D array (the first element of the first row).
     *
     * `arr + i`        : Points to the i-th 1D array (the i-th row).
     *
     * `*(arr + i)`     : Dereferencing `arr + i` gives the base address of the
     * i-th row. This is what you can think of as a pointer to the
     * first element of that row.
     *
     * `*(arr + i) + j` : Takes the address of the i-th row and adds `j` positions
     * to it, giving the memory address of the element at `arr[i][j]`.
     *
     * `*(*(arr + i) + j)`: The final dereference. It says "go to the address we just
     * calculated and give me the value stored there."
     *
     */
    printf("## Physical View: Accessing Elements with Pointer Arithmetic\n");
    printf("------------------------------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", *(*(arr + i) + j));
        }
        printf("\n");
    }
    printf("------------------------------------------------------------\n\n");

    /*
     *
     * ## Pro-Level Takeaway:
     *
     * The fact that `arr[i][j]` and `*(*(arr + i) + j)` are perfectly equivalent
     * means you can use either one. The first is more readable and less error-prone.
     * The second is a direct representation of what the CPU is actually doing with
     * memory addresses.
     *
     * This is foundational for understanding how data is accessed in a stripped binary
     * (a program without debugging symbols). By analyzing the opcodes and memory
     * offsets, you can figure out what the program is doing, even without knowing
     * the variable names or logical structure. You can spot a pattern like this
     * and say, "Aha, the program is accessing a 2D array here."
     *
     */

    return 0;
}
