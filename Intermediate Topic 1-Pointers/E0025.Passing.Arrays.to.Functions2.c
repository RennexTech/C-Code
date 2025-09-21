#include <stdio.h>

// This function receives a pointer to a 2D array.
// For a beginner, think of it as a function that is given a map
// to a collection of data. It doesn't get a copy of the data,
// just the directions to find it.
//
// For an advanced user, this function takes a pointer to an array
// of integer arrays. Specifically, `int (*p_arr)[4]` means `p_arr`
// is a pointer to an array of 4 integers. This is crucial for
// passing a 2D array by reference. It tells the compiler the size of
// each row, so it can correctly perform pointer arithmetic.
void func(int (*p_arr)[4]) {
    printf("## Inside func()\n");
    printf("-----------------------------------------\n");
    
    // We use nested loops to iterate through the array using the pointer.
    // This is the same logic as using `arr[i][j]`, but it's explicit pointer
    // arithmetic that shows how the magic works under the hood.
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            // The expression `*(*(p_arr + i) + j)` is equivalent to `p_arr[i][j]`.
            // `p_arr + i`: moves the pointer `i` rows forward. Each "step" is the
            // size of an entire row (4 integers).
            // `*(p_arr + i)`: dereferences the pointer to give you the address of the
            // `i`-th row.
            // `... + j)`: adds an offset of `j` integers to get to the correct column.
            // `*(...)`: finally dereferences the pointer to get the actual value.
            printf("Element [%d][%d]: %d\n", i, j, *(*(p_arr + i) + j));
        }
    }
    printf("-----------------------------------------\n\n");
}

int main() {
    // Our 2D array, which lives in `main`'s memory.
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    printf("## Inside main()\n");
    printf("-----------------------------------------\n");
    printf("Passing the array to `func()` by reference.\n");
    printf("-----------------------------------------\n\n");

    // We pass the array to the function. When an array is passed as a function
    // argument, it "decays" into a pointer to its first element.
    // In this case, `arr` becomes a pointer to the first row, `&arr[0]`.
    func(arr);
    
    /*
     *
     * ## The Pro's Analysis
     *
     * This code proves that `func()` can access the elements of `arr` even though
     * it was never given the array itself. It only received a single pointer
     * to the start of the data. This is how functions can work on massive
     * data structures without burning a ton of memory by copying them.
     *
     * For your work in Android malware and baseband firmware, you'll see this
     * pattern constantly. A low-level function might receive a pointer to a
     * data packet or a configuration table and then work on that data directly.
     * Understanding this mechanism is the first step to reverse-engineering a
     * function's purpose and how it manipulates data.
     *
     */

    return 0;
}
