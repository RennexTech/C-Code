#include <stdio.h>

/*
 *
 * ## The 2D Array: A Table in a Single Line
 *
 * In C, a two-dimensional (2D) array is a mental model, not a physical reality.
 * While you can think of it as a table with rows and columns, the computer
 * actually stores it as a single, contiguous block of memory. All the elements
 * of the first row are stored first, followed by all the elements of the
 * second row, and so on.
 *
 * This is called **row-major order**, and it's a foundational concept in
 * how data is organized and accessed in memory.
 *
 * For a beginner, this lets you visualize a table, making the code easy to write.
 * For an advanced user like you, it explains why you can use a single pointer
 * to traverse an entire 2D array, and why certain memory access patterns can
 * be much faster or slower than others (e.g., iterating by row is faster than
 * iterating by column due to cache locality).
 *
 */

int main() {
    // A 3x4 2D array, just like in your diagram.
    int x[3][4] = {
        {1, 2, 3, 4},
        {5, 6, 7, 8},
        {9, 10, 11, 12}
    };

    printf("## The 2D Array: A Logical View\n");
    printf("-----------------------------------\n");

    // The nested loops let us iterate through the array row by row.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            // We use the familiar row/column syntax.
            printf("x[%d][%d] = %d\t", i, j, x[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------\n\n");

    /*
     *
     * ## The Pro's View: What's Really Going On
     *
     * To prove that it's all one continuous block of memory, let's print the
     * memory addresses of each element. You'll see that they are sequential.
     * The address of the next element is just the address of the current one
     * plus the size of an integer (4 bytes on most systems).
     *
     * This is the kind of stuff you'll be dealing with when you're analyzing
     * a memory dump or a disassembled binary. Understanding this layout is
     * the first step to making sense of it.
     *
     */
    printf("## The 2D Array: A Memory View\n");
    printf("-----------------------------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            // We print the address of each element.
            printf("Address of x[%d][%d]: %p\n", i, j, (void*)&x[i][j]);
        }
    }
    printf("-----------------------------------\n");

    return 0;
}
