#include <stdio.h>

/*
 *
 * ## Understanding Multi-Dimensional Arrays and Pointers in C
 *
 * Imagine a 3D array like a high-rise office building, and each element is a single office.
 *
 * - The entire building is our `arr`.
 * - Each floor of the building is a 2D array.
 * - Each row of offices on a floor is a 1D array.
 * - Each individual office in a row is an element.
 *
 * This isn't just a mental model; it's how C actually stores it. The whole building's memory is
 * a single, contiguous block, and C just calculates the offset to find your specific office
 * based on the floor, row, and office number.
 *
 * The compiler does all this magic for you with `arr[i][j][k]`, but a pro knows what's
 * happening behind the scenes. This is crucial for low-level work. If you're analyzing
 * a piece of malware that's doing some wild pointer manipulation to hide data, you'll
 * immediately recognize this pattern and know what it's trying to do.
 *
 */

int main() {
    // We'll use this 3D array. It's an array of 2 2D arrays, each containing 3 1D arrays,
    // and each 1D array has 2 elements.
    int arr[2][3][2] = {
        {{5, 10}, {6, 11}, {7, 12}},
        {{20, 30}, {21, 31}, {22, 32}}
    };

    printf("## Accessing 3D Array Elements with Pointer Arithmetic\n\n");
    printf("Pointer expression vs. Subscript notation:\n\n");

    /*
     *
     * ## Deconstructing the Pointer Magic: A Step-by-Step Guide
     *
     * Let's break down the pointer arithmetic `*(*(*(arr + i) + j) + k)` to its core.
     * This is the manual way of telling the computer exactly where to go in memory.
     *
     * 1. `arr`
     * - What it is: The base address of the entire 3D array.
     * - Analogy: The address of the whole office building.
     *
     * 2. `arr + i`
     * - What it does: Moves the pointer forward by `i` number of 2D arrays.
     * - Analogy: You're at the building entrance. `arr + 1` means you go to the 2nd floor.
     *
     * 3. `*(arr + i)`
     * - What it does: Dereferences the pointer to get the value at that address, which is the base address of the `i`-th 2D array.
     * - Analogy: You've arrived at the `i`-th floor. This is a pointer to that entire floor.
     *
     * 4. `*(arr + i) + j`
     * - What it does: Adds `j` to the address of the 2D array, moving the pointer to the `j`-th 1D array on that floor.
     * - Analogy: You're on the `i`-th floor. You're walking down the hallway to the `j`-th row of offices.
     *
     * 5. `*(*(arr + i) + j)`
     * - What it does: Dereferences again to get the base address of the `j`-th 1D array.
     * - Analogy: You're now standing right at the entrance of the `j`-th row of offices.
     *
     * 6. `*(*(*(arr + i) + j) + k)`
     * - What it does: Moves the pointer forward by `k` elements to the final destination, then dereferences it to get the value.
     * - Analogy: You're at the start of the `j`-th row. You walk `k` steps and open the door to that specific office to get the data inside.
     *
     * This step-by-step memory walk is the same process the compiler does when you write `arr[i][j][k]`.
     *
     */

    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            for (int k = 0; k < 2; k++) {
                int pointer_value = *(*(*(arr + i) + j) + k);
                int subscript_value = arr[i][j][k];
                printf("arr[%d][%d][%d]:\t Pointer: %d\t Subscript: %d\n",
                       i, j, k, pointer_value, subscript_value);
            }
        }
    }
    printf("\n");

    /*
     *
     * ## Why `printf("\n");` is Outside the Loop
     *
     * You asked why `printf("\n");` is usually outside the innermost loop. That's a super good question,
     * and it gets to the heart of good code formatting and readability.
     *
     * Think of it like this: You're writing a report.
     *
     * - The **innermost loop** is like typing each word in a sentence. You just want spaces (or tabs) between them.
     * - The **`printf("\n");`** outside the innermost loop is like pressing ENTER at the end of a sentence. It moves you to a new line, but only after the full sentence is written.
     *
     * If you put `printf("\n");` inside the innermost loop, it's like pressing ENTER after every single word.
     * The output would be a long, single column of numbers, which is not what you want.
     * By placing it outside, we get a neat table-like format that's easy to read and shows the structure of the data.
     *
     */
     return 0;
}
