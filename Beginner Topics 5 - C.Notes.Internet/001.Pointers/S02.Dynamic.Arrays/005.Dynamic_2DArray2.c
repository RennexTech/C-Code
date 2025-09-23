#include <stdio.h>
#include <stdlib.h> // We need this for `malloc` and `free`.

int main()
{
    // `a` is a pointer to a pointer. Think of it as a list of "address cards"
    // where each card will point to the beginning of a row.
    int **a, i, j, rows, cols;
    
    // We're asking the user for the dimensions of the matrix. This is what
    // makes our program flexible and powerful.
    printf("Enter number of rows and columns : ");
    scanf("%d%d", &rows, &cols);

    // --- STEP 1: Allocate the "list of address cards" (the array of pointers) ---
    // We are requesting a block of memory big enough to hold `rows` number of
    // **pointers to integers**. The `sizeof(int *)` is crucial here.
    // This is like getting a blank binder with enough rings for your pages.
    a = (int **)malloc(rows * sizeof(int *));

    // A crucial check to make sure the memory for our list of addresses was successfully allocated.
    if (a == NULL) {
        printf("Memory not available for row pointers.\n");
        return 1;
    }

    // --- STEP 2: Allocate each individual "page" (the rows) ---
    // This loop is where we go through our list of address cards and, for each one,
    // we get a separate chunk of memory big enough for `cols` integers.
    // It's like adding pages to your binder, one by one.
    for (i = 0; i < rows; i++)
    {
        a[i] = (int *)malloc(cols * sizeof(int));
        // Check if the memory for this specific row was allocated.
        if (a[i] == NULL) {
            printf("Memory not available for row %d.\n", i);
            // In a real program, you'd free the previously allocated rows here.
            return 1;
        }
    }
    
    // Now we can fill the matrix just like a regular 2D array. The compiler handles
    // all the pointer magic for us behind the scenes.
    for (i = 0; i < rows; i++)
    {
        for (j = 0; j < cols; j++)
        {
            printf("Enter a[%d][%d] : ", i, j);
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

    // --- CRITICAL STEP: Freeing the memory ---
    // This is a two-step process, just like the allocation.
    // 1. We must first free each individual row (the pages in our binder).
    for (i = 0; i < rows; i++)
    {
        free(a[i]);
    }
    
    // 2. Finally, we free the main array of pointers (the binder itself).
    // You missed this step in your original code, which would have caused a memory leak.
    free(a);
    
    return 0;
}
