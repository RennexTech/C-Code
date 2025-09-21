#define ROW 3
#define COL 4
#include <stdio.h>
int main()
{
    int mat1[ROW][COL], mat2[ROW][COL], mat3[ROW][COL];
    printf("Enter matrix mat1(%dx%d) row-wise : \n", ROW, COL);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }
    printf("Enter matrix mat2(%dx%d) row-wise : \n", ROW, COL);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }
    // Addition -
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }
    printf("The resultant matrix mat3 is : \n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            printf("%d  ", &mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}



// =======================================================================
// FIXED CODE

#include <stdio.h>

// We're using #define to create constants for the dimensions of our matrices.
// This is good practice because it makes the code more readable and easier to change.
// If we ever want to change the size of the matrices, we only have to change these
// two lines instead of searching through the entire code.
#define ROW 3
#define COL 4

int main()
{
    // We're declaring three 2D arrays. Think of these as three separate grids or tables.
    // `mat1` and `mat2` are where we'll store the numbers we input.
    // `mat3` is where we'll store the result of adding `mat1` and `mat2`.
    int mat1[ROW][COL], mat2[ROW][COL], mat3[ROW][COL];

    // --- Input for the First Matrix (mat1) ---
    // This part of the code asks the user to fill in the first grid.
    printf("Enter matrix mat1(%dx%d) row-wise: \n", ROW, COL);

    // The nested `for` loops are perfect for working with a grid.
    // The outer loop (`i`) handles the rows, and the inner loop (`j`) handles the columns.
    // It's like a person filling out a form, going from left to right on each line, then moving down to the next line.
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // `scanf` reads an integer from the user. `&mat1[i][j]` provides the exact
            // memory address where the number should be stored in our `mat1` grid.
            scanf("%d", &mat1[i][j]);
        }
    }

    // --- Input for the Second Matrix (mat2) ---
    // This is the exact same process, but for our second grid.
    printf("Enter matrix mat2(%dx%d) row-wise: \n", ROW, COL);
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // --- Matrix Addition ---
    // This is the core logic. We're adding the numbers from `mat1` and `mat2`
    // and putting the sum into `mat3`.
    // The nested loops ensure we add each number in the exact same position.
    // For example, the number at `mat1[0][0]` is added to the number at `mat2[0][0]`,
    // and the result is stored in `mat3[0][0]`.
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            mat3[i][j] = mat1[i][j] + mat2[i][j];
        }
    }

    // --- Output for the Resultant Matrix (mat3) ---
    // Finally, we display the result.
    printf("The resultant matrix mat3 is: \n");
    for (int i = 0; i < ROW; i++)
    {
        for (int j = 0; j < COL; j++)
        {
            // The FIX: We are now printing the **value** of the element `mat3[i][j]`, not its address.
            // The `%d` format specifier is for an integer value, which is what we need.
            // The `\t` adds a tab for neat spacing, creating a grid-like appearance.
            printf("%d\t", mat3[i][j]);
        }
        // After each row is printed, we print a newline character to move to the next line.
        printf("\n");
    }

    return 0;
}
