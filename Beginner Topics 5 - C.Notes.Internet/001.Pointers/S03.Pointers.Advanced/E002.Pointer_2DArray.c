#include <stdio.h>

int main()
{
    // This is a 2D array. To C, it's just a big, single block of memory,
    // but the compiler gives us a logical way to treat it like a grid.
    // Think of it as a wall of lockers, organized into 3 rows and 4 columns.
    int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}};

    // We loop through each row.
    for (int i = 0; i < 3; i++)
    {
        // This line is a core concept. `arr[i]` and `*(arr + i)` are the same thing.
        // `arr` is a pointer to the first row. `arr[i]` is a pointer to the `i`-th row.
        // It's like having the address for an entire row of lockers.
        printf("Address of %dth row = %p %p\n", i, arr[i], *(arr + i));
        
        // Now we loop through each column in the current row.
        for (int j = 0; j < 4; j++)
        {
            // Here we print the value in two ways that are actually the same thing.
            // `arr[i][j]` is the easy way, but under the hood, the compiler
            // is doing `*(*(arr + i) + j)`. It's going to the address of the `i`-th row,
            // moving forward `j` spaces, and then getting the value.
            printf("Value at arr[%d][%d] = %d | Value using pointers = %d\n", i, j, arr[i][j], *(*(arr + i) + j));
        }
        printf("\n");
    }

    return 0;
}
