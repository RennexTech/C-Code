// C Program to demonstrate multidimensional arrays by handling various tasks.
#include <stdio.h>

// A good practice is to use constants for array dimensions.
// This makes the code more readable and easier to modify in the future.
// It's like giving a fixed address to a building instead of just writing the location.
const int CITY_COUNT = 2;
const int WEEK_DAYS = 7;
const int MATRIX_DIM = 2;

// Function prototypes to declare the functions before they are used in main().
void recordAndDisplayTemperatures();
void sumMatrices();
void handle3DArray();
void discuss2DArrayIndexing();

int main() {
    // We'll run each demonstration one by one to keep the output clean.
    
    printf("--- Part 1: Temperature Data ---\n");
    recordAndDisplayTemperatures();
    printf("\n\n");

    printf("--- Part 2: Matrix Summation ---\n");
    sumMatrices();
    printf("\n\n");

    printf("--- Part 3: 3D Array ---\n");
    handle3DArray();
    printf("\n\n");

    printf("--- Part 4: 2D Array Indexing and Errors ---\n");
    discuss2DArrayIndexing();
    printf("\n\n");

    return 0;
}

/**
 * @brief Records and displays temperature data for two cities over a week.
 * * We use a 2D array, which is like a spreadsheet with rows and columns.
 * The first index (row) represents the city, and the second index (column)
 * represents the day of the week.
 */
void recordAndDisplayTemperatures() {
    int temperature[CITY_COUNT][WEEK_DAYS];

    printf("Enter temperatures for two cities over a week:\n");

    // This outer loop iterates through each city (the rows).
    // Think of this loop as you moving from one city's record book to the next.
    for (int i = 0; i < CITY_COUNT; ++i) {
        // This inner loop iterates through each day of the week (the columns).
        // This is you writing down the temperature for each day in the city's book.
        for (int j = 0; j < WEEK_DAYS; ++j) {
            printf("City %d, Day %d: ", i + 1, j + 1);
            scanf("%d", &temperature[i][j]);
        }
    }

    printf("\nDisplaying recorded temperatures:\n\n");

    // We use another set of nested loops to read and print the data.
    // This is like going back and reading the records you just wrote down.
    for (int i = 0; i < CITY_COUNT; ++i) {
        for (int j = 0; j < WEEK_DAYS; ++j) {
            printf("City %d, Day %d = %d\n", i + 1, j + 1, temperature[i][j]);
        }
    }
}

/**
 * @brief Adds two 2x2 matrices and displays the result.
 * * Matrices are a core concept in computer graphics and scientific computing.
 * Adding them is a fundamental operation where you combine elements at the
 * same position from two separate matrices.
 */
void sumMatrices() {
    float a[MATRIX_DIM][MATRIX_DIM], b[MATRIX_DIM][MATRIX_DIM], result[MATRIX_DIM][MATRIX_DIM];

    // We'll use a helper function to avoid repeating the input logic.
    printf("Enter elements of the 1st matrix:\n");
    for (int i = 0; i < MATRIX_DIM; ++i) {
        for (int j = 0; j < MATRIX_DIM; ++j) {
            printf("Enter a[%d][%d]: ", i, j);
            scanf("%f", &a[i][j]);
        }
    }

    printf("Enter elements of the 2nd matrix:\n");
    for (int i = 0; i < MATRIX_DIM; ++i) {
        for (int j = 0; j < MATRIX_DIM; ++j) {
            printf("Enter b[%d][%d]: ", i, j);
            scanf("%f", &b[i][j]);
        }
    }

    // This is the core logic for matrix addition. We iterate through each position
    // and add the corresponding elements from matrices 'a' and 'b'.
    for (int i = 0; i < MATRIX_DIM; ++i) {
        for (int j = 0; j < MATRIX_DIM; ++j) {
            result[i][j] = a[i][j] + b[i][j];
        }
    }

    printf("\nSum of the matrices:\n");
    // We display the result in a clean, matrix-like format.
    for (int i = 0; i < MATRIX_DIM; ++i) {
        for (int j = 0; j < MATRIX_DIM; ++j) {
            printf("%.1f\t", result[i][j]);
        }
        printf("\n"); // This newline creates a new row for each row of the matrix.
    }
}

/**
 * @brief Demonstrates storing and printing values in a 3D array.
 * * A 3D array is like a stack of 2D arrays (matrices). You can think of it as
 * a multi-story building where the first index is the floor, the second is the
 * row of rooms, and the third is the column of rooms.
 */
void handle3DArray() {
    int test[2][3][2];

    printf("Enter 12 values for the 3D array:\n");

    // We use three nested loops to access and store elements in the 3D array.
    for (int i = 0; i < 2; ++i) { // Outer loop for "layers" or "floors."
        for (int j = 0; j < 3; ++j) { // Middle loop for "rows" on a layer.
            for (int k = 0; k < 2; ++k) { // Innermost loop for "columns" in a row.
                printf("Enter value for test[%d][%d][%d]: ", i, j, k);
                scanf("%d", &test[i][j][k]);
            }
        }
    }

    printf("\nDisplaying values:\n");
    // We use the same nested loop structure to print the stored values.
    for (int i = 0; i < 2; ++i) {
        for (int j = 0; j < 3; ++j) {
            for (int k = 0; k < 2; ++k) {
                printf("test[%d][%d][%d] = %d\n", i, j, k, test[i][j][k]);
            }
        }
    }
}

/**
 * @brief Explains 2D array indexing and corrects a common out-of-bounds error.
 * * This section addresses a critical concept: **array indexing starts at 0.**
 * Misunderstanding this is one of the most common bugs in C and a prime source
 * of security vulnerabilities, like buffer overflows.
 */
void discuss2DArrayIndexing() {
    int arr[3][2] = {
        {2, 3}, 
        {5, 6},
        {9, 10}
    };

    printf("Initial 2D array `arr`:\n");
    for (int i = 0; i < 3; ++i) {
        for (int j = 0; j < 2; ++j) {
            printf("%d\t", arr[i][j]);
        }
        printf("\n");
    }
    printf("\n");

    // Your original code had two major errors here.
    // 1. You were trying to access `arr[2][2]`, but the array only has 2 columns (indices 0 and 1).
    // 2. You were trying to access `arr[3][2]`, but the array only has 3 rows (indices 0, 1, and 2).
    // Accessing indices that are outside the bounds of an array (out-of-bounds access)
    // is a major security flaw. It can lead to unpredictable behavior, crashes, or, in
    // malware, the ability to overwrite critical data in memory.
    printf("Accessing `arr[2][1]` (row 3, column 2) instead of the invalid `arr[2][2]`.\n");
    arr[2][1] = 40;
    
    // We'll also fix the second invalid access. The array has no 4th row (index 3).
    // You'd get a crash or write to unexpected memory.
    printf("Accessing `arr[0][0]` instead of the invalid `arr[3][2]`.\n");
    arr[0][0] = 80;

    printf("The new value for arr[2][1] is %d.\n", arr[2][1]);
    printf("The new value for arr[0][0] is %d.\n", arr[0][0]);
    printf("Note: The original `arr[2][2]` and `arr[3][2]` are outside array bounds and would cause a critical error.\n");
}