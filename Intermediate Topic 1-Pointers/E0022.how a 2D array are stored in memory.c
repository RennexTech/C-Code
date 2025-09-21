#include <stdio.h>

/*
 *
 * ## The 2D Array in Memory: A Linear Street
 *
 * For a beginner, a 2D array is like a table with neat rows and columns.
 * It's easy to picture `arr[i][j]` as finding the right row and then the
 * right column, just like a spreadsheet.
 *
 * For a pro, you know that this is just a mental model. In reality, the
 * computer's memory is a single, long street of bytes. C stores a 2D array
 * in what's called **row-major order**. This means the entire first row is
 * stored, then the entire second row, and so on.
 *
 * This code demonstrates that by using a single pointer to walk the array.
 * You can see how the pointer moves from the last element of one row directly
 * to the first element of the next row without skipping any memory. This
 * is a huge deal for performance (cache locality) and for low-level memory
 * manipulation.
 *
 */

int main() {
    // Declaring and initializing the 2D array from your diagram.
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    // A simple pointer to the first element of the array.
    // This pointer, `ptr`, can walk through the entire array.
    int *ptr = &arr[0][0];

    printf("## Logical View (Using `arr[i][j]` notation)\n");
    printf("-----------------------------------------\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("-----------------------------------------\n\n");

    printf("## Memory View (Using a single pointer)\n");
    printf("-----------------------------------------\n");
    // We loop 12 times because there are 12 total elements (3 rows * 4 columns).
    for (int i = 0; i < 12; i++) {
        // We print the memory address and the value it holds.
        // We use `ptr + i` to move `i` integers forward in memory.
        printf("Address: %p | Value: %d\n", (void*)(ptr + i), *(ptr + i));

        // This is a check to visually show the transition from one row to the next.
        // The last element of a row (at indices 3, 7, 11) is followed by a blank line.
        if ((i + 1) % 4 == 0) {
            printf("---\n");
        }
    }
    printf("-----------------------------------------\n");
    
    /*
     *
     * ## The Pro's Analysis: The Memory Is Contiguous
     *
     * Notice how the memory addresses are sequential. The address of `arr[0][3]`
     * is immediately followed by the address of `arr[1][0]`, with no gaps. This
     * confirms that the array is a single block of memory, not a collection
     * of separate rows.
     *
     * In malware analysis, this is the kind of pattern you'll look for when
     * a program is iterating through a data structure. Understanding how the
     * compiler lays out this data in memory is the first step to reverse-engineering
     * the logic of the program.
     *
     */

    return 0;
}
