#include <stdio.h>

#define ROW1 3
#define COL1 4
#define ROW2 COL1
#define COL2 2

int main() {
    // These matrices are our ingredients. `mat1` and `mat2` are the inputs,
    // and `mat3` is where we'll put the final result.
    int mat1[ROW1][COL1], mat2[ROW2][COL2], mat3[ROW1][COL2];
    int i, j, k;

    // This block is like a production line for `mat1`.
    // The loops make sure we get every single value, from the first row to the last,
    // and store it in the right spot.
    printf("Enter the matrix mat1(%d*%d) row-wise: \n", ROW1, COL1);
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL1; j++)
            scanf_s("%d", &mat1[i][j]);
    }

    // Same thing here, but for `mat2`. The code is a factory worker
    // filling up the second set of ingredients.
    printf("Enter the matrix mat2(%d*%d) row-wise: \n", ROW2, COL2);
    for (i = 0; i < ROW2; i++) {
        for (j = 0; j < COL2; j++)
            scanf_s("%d", &mat2[i][j]);
    }

    // This is the main event: the multiplication kitchen.
    // Analogy: Think of a food truck at a festival.
    // The **outer `for (i)` loop** is the chef handling each `mat1` row, one by one.
    for (i = 0; i < ROW1; i++) {
        // The **middle `for (j)` loop** is the customer placing their order.
        // It's in charge of a single cell in the final result matrix (`mat3[i][j]`).
        // We set it to `0` to start with, like an empty plate, before adding anything.
        for (j = 0; j < COL2; j++) {
            mat3[i][j] = 0;
            // The **innermost `for (k)` loop** is the secret sauce.
            // It runs through all the ingredients (columns of `mat1` and rows of `mat2`),
            // multiplying them and adding the result to the current plate.
            // This is where the magic happens that gets us the correct value for `mat3[i][j]`.
            for (k = 0; k < COL1; k++) {
                mat3[i][j] += mat1[i][k] * mat2[k][j];
            }
        }
    }

    // Time to serve the food.
    // These two nested loops are just for presentation. They go through the
    // final `mat3` matrix and print each value neatly, row by row.
    printf("The Resultant matrix mat3 is: \n");
    for (i = 0; i < ROW1; i++) {
        for (j = 0; j < COL2; j++) {
            printf("%5d", mat3[i][j]);
        }
        printf("\n"); // Move to the next line for the next row.
    }

    return 0;
}
