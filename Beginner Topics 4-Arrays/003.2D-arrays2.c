#include <stdio.h>

// These are like blueprints. We're telling the compiler that our matrices will
// always have 3 rows and 4 columns. This way, we can use `ROW` and `COL`
// everywhere instead of hard-coding the numbers, which makes our code
// way easier to read and change later on.
#define ROW 3
#define COL 4

int main() {
    // We're setting up three empty containers for our matrices.
    // `matrix1` and `matrix2` are our starting ingredients, and `matrix3` is
    // the bowl where we'll put the final mixed-up result.
    int matrix1[ROW][COL];
    int matrix2[ROW][COL];
    int matrix3[ROW][COL];
    int i, j; // These are our helpers, our "loop counters."

    printf("Enter the values for matrix1(%d*%d): \n", ROW, COL);
    // This part is like filling up the first container, `matrix1`, one slot at a time.
    // The outer `for` loop moves us down the rows.
    // The inner `for` loop moves us across the columns in that row.
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            // We use `scanf_s` here for safety—it's like a bouncer at a party,
            // making sure the user's input doesn't crash the program.
            scanf_s("%d", &matrix1[i][j]);
        }
    }

    printf("=================================\n");

    printf("Enter the values for matrix2(%d*%d): \n", ROW, COL);
    // Same process, but for our second container, `matrix2`.
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            scanf_s("%d", &matrix2[i][j]);
        }
    }

    // This is the core logic: the actual addition.
    // It's like combining two bowls of ingredients, one spoonful at a time.
    // We go to the same slot in both `matrix1` and `matrix2`, add their values,
    // and then put the sum into the matching slot in our result container, `matrix3`.
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            matrix3[i][j] = matrix1[i][j] + matrix2[i][j];
        }
    }
    
    printf("The resultant matrix3 is: \n");
    // Finally, we're serving the result. These loops are just for display,
    // printing out each value from `matrix3` in an easy-to-read grid.
    for (i = 0; i < ROW; i++) {
        for (j = 0; j < COL; j++) {
            printf("%5d", matrix3[i][j]);
        }
        printf("\n"); // This moves us to a new line after each row is printed.
    }
    
    // We `return 0` to signal that the program ran successfully.
    return 0;
}
