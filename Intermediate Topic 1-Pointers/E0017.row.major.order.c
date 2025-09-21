#include <stdio.h>

/*
 *
 * ## Understanding Row-Major Order: The Memory Layout Blueprint
 *
 * Imagine a 2D array as a spreadsheet with rows and columns. While we see it as a grid,
 * the computer's memory is a single, long street with houses lined up one after another.
 * Row-major order is the rule that determines how the houses from our grid are placed
 * on that street.
 *
 * The rule is simple: **all the elements of the first row are placed on the street first,
 * followed by all the elements of the second row, and so on.**
 *
 * This isn't just a fun fact; it's a critical concept for system-level programming and
 * reverse engineering. When you're looking at a memory dump, you won't see a neat grid.
 * You'll see a long sequence of bytes. Knowing that C uses row-major order allows you
 * to reconstruct the logical structure of an array from its physical layout in memory.
 * This is crucial for analyzing data structures in a binary, especially when you can't
 * rely on source code.
 *
 */

int main() {
    // Let's declare a 3x4 2D array.
    // Logically, it looks like this:
    // Row 0: 10, 11, 12, 13
    // Row 1: 20, 21, 22, 23
    // Row 2: 30, 31, 32, 33
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    printf("## Logical View: The Array as a Grid\n");
    printf("----------------------------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("----------------------------------\n\n");

    /*
     *
     * ## Physical View: The Array in Contiguous Memory
     *
     * Now, let's prove that C stores this array in a straight line, row by row.
     * We'll use a pointer to step through the entire array as if it were a single
     * 1D array. This is the ultimate "behind the scenes" peek.
     *
     * We cast `arr` to an `int*` to tell the compiler to treat the starting address
     * of the 2D array as the starting address of a 1D array of integers. This
     * bypasses the row/column logic and lets us walk through the raw memory.
     *
     * If the memory addresses are sequential and the values match our logical
     * rows, we've proven row-major order.
     *
     */

    printf("## Physical View: Iterating through Memory with a Pointer\n");
    printf("------------------------------------------------------\n");
    
    // We get a pointer to the very first element of the array.
    int* ptr = &arr[0][0];

    // We loop for the total number of elements (3 rows * 4 columns = 12 elements).
    for (int i = 0; i < 12; i++) {
        // We print the memory address and the value at that address.
        // The address should increment by 4 bytes (the size of an int) each time.
        printf("Element %2d: Address = %p, Value = %d\n", i, (void*)(ptr + i), *(ptr + i));
    }
    printf("------------------------------------------------------\n\n");


    /*
     *
     * ## The Big Takeaway for the Pro
     *
     * Notice how the output for the physical view shows the numbers 10, 11, 12, 13
     * first, followed immediately by 20, 21, 22, 23, and so on. The memory addresses
     * are contiguous and match the row-by-row layout.
     *
     * This is a fundamental pattern you'll encounter. When you're in a debugger looking
     * at a memory dump and you see a sequence of bytes, this knowledge allows you to
     * recognize that it might be a 2D array and figure out its dimensions by analyzing
     * the stride. For example, if you see data repeating a pattern every 16 bytes,
     * you might guess it's a row of 4 integers. This is a skill that separates a
     * reverse engineer from someone who just reads the source code.
     *
     */

    return 0;
}
