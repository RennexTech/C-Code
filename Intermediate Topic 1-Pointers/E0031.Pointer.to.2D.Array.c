#include <stdio.h>

int main() {
    // This is our 2D array, which we'll treat as our data set.
    // It's a grid in our minds, but in memory, it's just a long line of numbers.
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    // This is a pointer that points to a 1D array of 4 integers.
    // The syntax `(*ptr)[4]` is critical. The parentheses are a big deal
    // because they tell the compiler that `ptr` is a pointer to an array,
    // not an array of pointers.
    int (*ptr)[4];

    // ## The Set Up: The "Secret Key"
    // `ptr = arr;` is the magic line. We're not copying the array; we're just
    // making the pointer point to the very beginning of the array in memory.
    // `ptr` now holds the base address of the 2D array.
    ptr = arr;

    /*
     *
     * ## The Pro's View: Why This Matters
     *
     * When you're reverse engineering, you will see this all the time.
     * A function might be defined as `void processData(int (*data)[4])`.
     * You will not see a nice 2D array name. You'll see a pointer. You have
     * to look at how the function uses that pointer to figure out what it's
     * doing. The function will use pointer arithmetic to access elements,
     * like `*(data + i)` to get to the `i`-th row, and `*(*(data + i) + j)`
     * to get to the `j`-th element in that row.
     *
     * This is a super efficient way to pass data to a function. Instead of
     * copying 12 integers (48 bytes), we just pass a single pointer (8 bytes
     * on a 64-bit system), which saves time and memory. This is a core
     * concept that all operating systems and drivers rely on.
     *
     */
    printf("## Accessing Elements with a Pointer\n");
    printf("--------------------------------------\n");

    // We'll use our new pointer to print out all the elements.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            // This is the pointer magic. The compiler knows `ptr` points to
            // an array of arrays, so `ptr[i]` gives you the base address of
            // the `i`-th row. From there, `ptr[i][j]` is just like
            // a regular array access.
            printf("Element at ptr[%d][%d]: %d\n", i, j, ptr[i][j]);
        }
    }

    printf("\n## Proof that Pointers and Arrays are the Same\n");
    printf("----------------------------------------------\n");
    
    // We can also print the addresses to prove they are the same.
    printf("Address of arr: %p\n", (void*)arr);
    printf("Value of ptr (Address of arr): %p\n", (void*)ptr);

    printf("--------------------------------------\n");

    return 0;
}
