#include <stdio.h>
#include <stdlib.h> // We need this for `malloc` and `free`.

int main()
{
    int rows;
    // This is a pointer to an array of 4 integers.
    // The parentheses are key. It tells the compiler, "Hey, this variable `a`
    // doesn't point to a single integer; it points to a whole row of integers,
    // and that row has exactly 4 columns."
    int (*a)[4];

    // We're asking the user how many rows they need, making the matrix size flexible.
    printf("Enter number of rows : ");
    scanf("%d", &rows);

    // We're allocating a single, continuous block of memory big enough for
    // all the rows and all the columns. It's like buying a long, single bookshelf
    // that has slots for all your books, and you just calculate the total space you need.
    // The expression `rows * 4 * sizeof(int)` calculates the total bytes needed for all elements.
    a = (int(*)[4])malloc(rows * 4 * sizeof(int));
    
    // Check if the memory allocation was successful.
    if (a == NULL) {
        printf("Memory not available\n");
        return 1; // Exit with an error code.
    }

    // This is where we fill the matrix. We can use standard 2D array notation (`a[i][j]`)
    // because the memory is laid out in a contiguous block, just like a static array.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("Enter a[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe matrix is : \n");
    // And here we print it out, row by row.
    for (int i = 0; i < rows; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    // We're done with the memory, so we give it back to the OS.
    free(a);

    return 0;
}
