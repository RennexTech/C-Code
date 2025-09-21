#include <stdio.h>

// We're using #define to set up our matrix dimensions. This is good practice
// because it makes the code a lot more readable and easier to change.
// The rule for matrix multiplication is that the number of columns in the first matrix
// MUST equal the number of rows in the second matrix.
// So here, COL1 (4) == ROW2 (4). This is non-negotiable.
#define ROW1 3
#define COL1 4
#define ROW2 COL1
#define COL2 2

int main()
{
    // We're declaring three matrices on the stack.
    // `mat1` and `mat2` are the input matrices.
    // `mat3` is the resulting matrix, with dimensions ROW1 x COL2 (3x2).
    int mat1[ROW1][COL1], mat2[ROW2][COL2], mat3[ROW1][COL2];

    // --- Input for the First Matrix (mat1) ---
    // This is the input loop. It's asking the user to fill out the first grid.
    printf("Enter matrix mat1(%dx%d) row-wise :\n", ROW1, COL1);
    for (int i = 0; i < ROW1; i++)
    {
        for (int j = 0; j < COL1; j++)
        {
            // `scanf` takes the user's input and stores it at the memory address
            // of `mat1[i][j]`.
            scanf("%d", &mat1[i][j]);
        }
    }

    // --- Input for the Second Matrix (mat2) ---
    // Same deal here. We fill out the second grid, `mat2`.
    printf("Enter matrix mat2(%dx%d) row-wise :\n", ROW2, COL2);
    for (int i = 0; i < ROW2; i++)
    {
        for (int j = 0; j < COL2; j++)
        {
            scanf("%d", &mat2[i][j]);
        }
    }

    // --- The Matrix Multiplication Logic ---
    // This is the core of the algorithm, a "three-loop dance."
    // 1. The outer loop (`i`) iterates through the rows of the resulting matrix (`mat3`).
    // 2. The middle loop (`j`) iterates through the columns of the resulting matrix.
    // 3. The inner loop (`k`) is the "workhorse" that performs the dot product.
    // It's like having a team. One person (the outer loop) picks a row. The next person (the middle loop)
    // picks a column. The third person (the inner loop) multiplies each element in the row
    // by the corresponding element in the column and adds them up.
    // 
    for (int i = 0; i < ROW1; i++)
    {
        for (int j = 0; j < COL2; j++)
        {
            // We initialize the sum to zero before we start the dot product.
            mat3[i][j] = 0;
            // The inner loop iterates through the number of elements we're multiplying (COL1 or ROW2).
            for (int k = 0; k < COL1; k++)
            {
                // This is the core calculation. We take `mat1[i][k]`, which moves along
                // a single row of `mat1`, and `mat2[k][j]`, which moves down a single column of `mat2`.
                mat3[i][j] = mat3[i][j] + mat1[i][k] * mat2[k][j];
            }
        }
    }

    // --- Output for the Resultant Matrix (mat3) ---
    // We print the resulting matrix, `mat3`.
    printf("The Resultant Matrix mat3 is :\n");
    for (int i = 0; i < ROW1; i++)
    {
        for (int j = 0; j < COL2; j++)
        {
            // We use `%5d` to format the output nicely. It reserves 5 spaces for each number,
            // which keeps the columns aligned even if the numbers are different sizes.
            printf("%5d", mat3[i][j]);
        }
        printf("\n");
    }

    return 0;
}
