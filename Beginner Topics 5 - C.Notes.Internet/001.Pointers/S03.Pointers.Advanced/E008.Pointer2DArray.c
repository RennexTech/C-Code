#include<stdio.h>
int main()
{
    // Here we're creating a 2D array, which is an array of arrays.
    // Think of `arr` as a grid or a table with 3 rows and 4 columns.
    // Each row contains 4 integers.
    int arr[3][4] = {{10, 12, 13, 14}, {20, 21, 22, 23}, {30, 31, 32, 33}};

    // This is an array of pointers. It's an array with 3 slots,
    // and each slot is designed to hold the memory address of an integer.
    // It's like having a list of 3 empty address books.
    int *pa[3];

    // This loop connects our array of pointers to our 2D array.
    for (int i = 0; i < 3; i++)
    {
        // `arr[i]` is the name of a row in our 2D array. In C, the name of an array
        // (or a row in a 2D array) acts as a pointer to its first element.
        // So, `arr[0]` is a pointer to the first row, `arr[1]` to the second, and so on.
        // We're taking the address of each row and storing it in our pointer array.
        // `pa[0]` now points to the first row of `arr`.
        // `pa[1]` now points to the second row of `arr`.
        // `pa[2]` now points to the third row of `arr`.
        pa[i] = arr[i];
    }

    // Now we're using our array of pointers (`pa`) to print the contents of the 2D array.
    // This is an alternative way to access the elements.
    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            // `pa[i]` gets the address of a row.
            // `pa[i][j]` is a very convenient syntax for "go to the address in `pa[i]` and
            // then move `j` steps forward to get the value." It's the same as `*(*(pa+i)+j)`.
            printf("%d  ", pa[i][j]);
        }
        printf("\n");
    }

    return 0;
}