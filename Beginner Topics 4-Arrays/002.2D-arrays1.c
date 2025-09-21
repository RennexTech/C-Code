#include <stdio.h>

// Imagine this is a blueprint for our matrices. We're setting the default number
// of rows and columns here so we don't have to re-type it everywhere.
// It's a way of saying, "Hey, for this project, our standard grid is 3x3."
// This makes the code super easy to change later if we want a 4x5 or 2x2 grid.
#define ROWS 3
#define COLS 3

// --- Function Prototypes ---
// Prototypes are like the table of contents for our code. They tell the compiler
// what functions we're going to use later, so it's not surprised when it sees
// a function call it hasn't seen yet.

// A function to fill a matrix with numbers from the user.
void readMatrix(int rows, int cols, int matrix[rows][cols]);

// A function to neatly print a matrix to the console.
void printMatrix(int rows, int cols, int matrix[rows][cols]);

// A function to add two matrices together.
void addMatrices(int rows, int cols, int matA[rows][cols], int matB[rows][cols], int result[rows][cols]);

// A function to subtract one matrix from another.
void subtractMatrices(int rows, int cols, int matA[rows][cols], int matB[rows][cols], int result[rows][cols]);

// A function to multiply two matrices.
// Note: Matrix multiplication has a specific rule: the number of columns in the
// first matrix must equal the number of rows in the second. We handle this in the main function.
void multiplyMatrices(int r1, int c1, int r2, int c2, int matA[r1][c1], int matB[r2][c2], int result[r1][c2]);

// --- Main Function: The Control Center ---
// Think of the main function as the director of a play. It sets the stage,
// introduces the actors (our matrices), and tells each one when to perform their role
// by calling the functions we defined. Everything starts and ends here.
int main() {
    // Declaring our matrices. We have two input matrices and several
    // "output" matrices to hold the results of our operations.
    int matrix1[ROWS][COLS];
    int matrix2[ROWS][COLS];
    int sum[ROWS][COLS];
    int difference[ROWS][COLS];
    int product[ROWS][COLS] = {0}; // It's good practice to initialize the product matrix to all zeros.

    // -----------------------------------------------------------
    // PART 1: Reading and Displaying Matrices
    // This is like asking the user to fill out two separate spreadsheets.
    printf("--- Enter the first matrix (%d*%d) row-wise ---\n", ROWS, COLS);
    readMatrix(ROWS, COLS, matrix1);

    printf("\n--- Enter the second matrix (%d*%d) row-wise ---\n", ROWS, COLS);
    readMatrix(ROWS, COLS, matrix2);

    // Now we'll show the user what they entered to make sure it's correct.
    // It's a quick sanity check before we start the calculations.
    printf("\n--- First Matrix Entered ---\n");
    printMatrix(ROWS, COLS, matrix1);

    printf("\n--- Second Matrix Entered ---\n");
    printMatrix(ROWS, COLS, matrix2);

    // -----------------------------------------------------------
    // PART 2: Performing Operations and Displaying Results
    printf("\n--- Starting Matrix Operations ---\n");

    // Adding the two matrices. This is the easiest part. We're just
    // combining the two spreadsheets, cell by cell.
    addMatrices(ROWS, COLS, matrix1, matrix2, sum);
    printf("\n--- Sum of the Two Matrices ---\n");
    printMatrix(ROWS, COLS, sum);

    // Subtracting the two matrices. Same idea as addition, but we're
    // finding the difference between the values in each cell.
    subtractMatrices(ROWS, COLS, matrix1, matrix2, difference);
    printf("\n--- Difference of the Two Matrices (Matrix1 - Matrix2) ---\n");
    printMatrix(ROWS, COLS, difference);

    // Multiplying the two matrices. This is where it gets a little more complex.
    // We're taking the dot product of rows from the first matrix and columns
    // from the second. Think of it as a series of mini-calculations for each cell
    // in the product matrix.
    multiplyMatrices(ROWS, COLS, ROWS, COLS, matrix1, matrix2, product);
    printf("\n--- Product of the Two Matrices ---\n");
    printMatrix(ROWS, COLS, product);

    return 0;
}

// --- Function Definitions ---
// Now we get into the nitty-gritty of each function. These are the workhorses
// that do all the heavy lifting for the main function.

void readMatrix(int rows, int cols, int matrix[rows][cols]) {
    // The outer loop is like walking down the aisles (rows) of a supermarket.
    for (int i = 0; i < rows; i++) {
        // The inner loop is like walking down each shelf (columns) in that aisle.
        for (int j = 0; j < cols; j++) {
            // We tell the user which item (cell) we're on and then take their input.
            // This is how we fill up our matrix, one cell at a time.
            printf("Enter element [%d][%d]: ", i + 1, j + 1);
            scanf_s("%d", &matrix[i][j]);
        }
    }
}

void printMatrix(int rows, int cols, int matrix[rows][cols]) {
    // This is basically a "show and tell" function for our matrix.
    // We're going to loop through every cell, just like in the read function,
    // but this time we're just printing out the value we find there.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            // The `%5d` is a formatting trick. It's like a rule that says
            // "every number gets at least 5 spaces." This keeps our columns
            // perfectly aligned and readable, no matter the size of the numbers.
            printf("%5d", matrix[i][j]);
        }
        // After we're done with a row, `printf("\n");` moves the cursor to
        // the next line, creating that neat grid layout.
        printf("\n");
    }
}

void addMatrices(int rows, int cols, int matA[rows][cols], int matB[rows][cols], int result[rows][cols]) {
    // Adding matrices is a one-to-one mapping.
    // We grab the value from a spot in Matrix A, the same spot in Matrix B,
    // add them together, and then save the result in the same spot in the new matrix.
    // It's as straightforward as combining two checklists into one.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] + matB[i][j];
        }
    }
}

void subtractMatrices(int rows, int cols, int matA[rows][cols], int matB[rows][cols], int result[rows][cols]) {
    // This is just like addition, but with subtraction. It's a quick way to find the
    // difference between two sets of data in the same format.
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = matA[i][j] - matB[i][j];
        }
    }
}

void multiplyMatrices(int r1, int c1, int r2, int c2, int matA[r1][c1], int matB[r2][c2], int result[r1][c2]) {
    // Matrix multiplication has a more intense logic.
    // Imagine you have a shopping list (Matrix A) and a price list (Matrix B).
    // To find the total cost for the first product, you have to multiply
    // the quantity of each item in the first list's first row by the price of
    // each item in the second list's first column, and then add all those
    // products together. That's the value of just ONE cell in our result matrix.
    // We have three loops because we need to iterate through the first matrix's rows,
    // the second matrix's columns, and also the individual elements within each.
    
    // Safety check: Matrix multiplication is only possible if the number of columns
    // in the first matrix equals the number of rows in the second.
    if (c1 != r2) {
        printf("Error: Matrix multiplication is not possible with these dimensions.\n");
        return;
    }

    // Outer loops set up our current position in the result matrix.
    for (int i = 0; i < r1; i++) {
        for (int j = 0; j < c2; j++) {
            // The inner loop does the heavy lifting: the dot product.
            // It sums up the products of corresponding elements from a row in A and a column in B.
            // This is the core engine of the multiplication.
            for (int k = 0; k < c1; k++) {
                result[i][j] += matA[i][k] * matB[k][j];
            }
        }
    }
}
