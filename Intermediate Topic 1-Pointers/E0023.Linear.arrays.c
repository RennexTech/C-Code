#include <stdio.h>

/*
 *
 * ## Walking the Array with a Single Pointer
 *
 * For a beginner, a 2D array is a table of values. To get to `a[1][1]`, you
 * first go to the second row, then the second column. But in reality, your
 * computer's memory is a single, long street of bytes.
 *
 * The compiler lays out a 2D array in **row-major order**, which means it
 * stores the first row, then the second, and so on, all in one continuous
 * line.
 *
 * This code uses a single pointer, `p`, to walk this linear street. The
 * `for` loop's condition, `p <= &a[1][1]`, is the same as saying, "keep
 * walking down the street until you get to the address of the element at
 * `a[1][1]`." This is how you access a "2D" array without ever needing
 * a second dimension. It's a fundamental concept for working with memory at a low level.
 *
 */

int main() {
    // The 2D array we'll traverse. Conceptually, it's a 2x2 grid.
    int a[2][2] = {
        {1, 2}, // Row 0
        {3, 4}  // Row 1
    };
    
    // A pointer to an integer. We initialize it with the address of the first
    // element of the array.
    int *p;

    printf("## Traversing the 2D Array with a Single Pointer\n");
    printf("---------------------------------------------------\n");
    printf("Logical view:\n");
    printf("a[0][0] = %d\n", a[0][0]);
    printf("a[0][1] = %d\n", a[0][1]);
    printf("a[1][0] = %d\n", a[1][0]);
    printf("a[1][1] = %d\n", a[1][1]);
    printf("---------------------------------------------------\n\n");
    
    printf("## Walking the Memory with a Pointer Loop\n");
    printf("----------------------------------------\n");

    // The loop from the diagram. It starts `p` at the address of `a[0][0]` and continues
    // until `p` is at or past the address of `a[1][1]`.
    for (p = &a[0][0]; p <= &a[1][1]; p++) {
        // The loop is just doing pointer arithmetic. It's incrementing the address
        // by the size of an integer each time, letting it walk to the next element.
        printf("Value at address %p: %d\n", (void*)p, *p);
    }

    printf("----------------------------------------\n");
    
    /*
     *
     * ## The Pro's Analysis: Why This Matters
     *
     * This single loop reveals the contiguous nature of memory. When you're
     * analyzing a memory dump or a disassembled binary, you won't see `a[i][j]`.
     * You'll see a pointer (`p`) being incremented to a specific memory offset.
     * Understanding this `p++` operation as a move to the next logical element,
     * regardless of whether it's in the same "row" or a new "row," is key to
     * reverse engineering a program's data structures. This knowledge is
     * the foundation for understanding how a program handles data behind the scenes.
     *
     */

    return 0;
}
