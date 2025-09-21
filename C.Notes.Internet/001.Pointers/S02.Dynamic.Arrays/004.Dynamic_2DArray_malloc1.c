#include <stdio.h>
#include <stdlib.h> // We need this for `malloc` and `free`.

int main()
{
    int rows, cols, i, j;

    // First, we create an array of pointers. Think of this as a list of
    // "address cards" that we'll use to point to different places.
    // We're going to ask the user for the number of rows dynamically.
    printf("Enter number of rows: ");
    scanf("%d", &rows);
    int **a; // This is a pointer to a pointer. We'll allocate the array of pointers dynamically.
    a = (int **)malloc(rows * sizeof(int *));

    // A crucial check to make sure our list of address cards was created.
    if (a == NULL) {
        printf("Memory not available for row pointers.\n");
        return 1;
    }

    // Now we ask for the number of columns. We'll use this for each row.
    printf("Enter number of columns: ");
    scanf("%d", &cols);

    // This loop is where the magic happens. For each address card in our list,
    // we go get a separate chunk of memory big enough for `cols` integers.
    // It's like having a library catalog where each card points to a different
    // section of books in the library. They don't have to be right next to each other.
    for (i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(cols * sizeof(int));
        if (a[i] == NULL) {
            printf("Memory not available for row %d.\n", i);
            return 1;
        }
    }

    // Now we fill the "matrix" with data. We're using standard 2D array syntax,
    // but the compiler is secretly using the pointers we've created to find
    // the right memory locations.
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter value of a[%d][%d] : ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    printf("\nThe matrix is : \n");
    // And here we print the data.
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    // --- The Two-Step Memory Release ---
    // 1. First, we free each individual row of memory that we allocated.
    // It's like returning each of the separate sections of books back to the library.
    for (i = 0; i < rows; i++)
    {
        free(a[i]);
    }

    // 2. Second, we free the main array of pointers itself.
    // It's like returning the library catalog card holder itself.
    free(a);
    
    return 0;
}
