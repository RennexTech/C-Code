#include <stdio.h>
#define ROW 3
#define COL 4
int main()
{
    int mat1[ROW][COL], mat2[ROW][COL],i,j;
    printf("Enter matrix mat(%dx%d) row-wise :\n", ROW, COL);
    for ( i = 0; i < ROW; i++)
    {
        for ( j = 0; j < COL; j++)
            scanf("%d", &mat1[i][j]);
    }
    for ( i = 0; i < COL; i++)
    {
        for ( j = 0; j < ROW; j++)
            mat2[i][j] = mat1[j][i];
    }
    printf("Transpose of matrix is :\n");
    for (int i = 0; i < COL; i++)
    {
        for (int j = 0; j < ROW; j++)
            printf("%d ", mat2[i][j]);
        printf("\n");
    }
    return 0;
}


// ==============================================================
// NEW CODE

#include <stdio.h>

// We're defining the dimensions of our first matrix.
// `ROW` is 3 and `COL` is 4.
#define ROW 3
#define COL 4

int main()
{
    // Our first matrix, `mat1`, is 3 rows by 4 columns.
    // Our second matrix, `mat2`, is the **transpose** of the first, so its dimensions
    // must be flipped: 4 rows by 3 columns.
    int mat1[ROW][COL], mat2[COL][ROW];
    int i, j; // Loop counters

    // This section handles getting the numbers from the user for `mat1`.
    printf("Enter matrix mat1(%dx%d) row-wise:\n", ROW, COL);
    for (i = 0; i < ROW; i++)
    {
        for (j = 0; j < COL; j++)
        {
            scanf("%d", &mat1[i][j]);
        }
    }

    // This is the core logic for transposing the matrix.
    // We're taking the number at `mat1[j][i]` and placing it at `mat2[i][j]`.
    // It's like flipping a grid or spreadsheet. The value in row `j` and column `i`
    // of the original matrix now becomes the value in row `i` and column `j` of the new one.
    // For example, the number at `mat1[0][1]` goes to `mat2[1][0]`.
    for (i = 0; i < COL; i++)
    {
        for (j = 0; j < ROW; j++)
        {
            mat2[i][j] = mat1[j][i];
        }
    }

    // Finally, we print the transposed matrix.
    // Notice that the loops now use the dimensions of `mat2` (`COL` and `ROW`).
    printf("Transpose of matrix is:\n");
    for (i = 0; i < COL; i++)
    {
        for (j = 0; j < ROW; j++)
        {
            printf("%d ", mat2[i][j]);
        }
        printf("\n"); // Prints a newline after each row for a clean grid format.
    }

    return 0;
}