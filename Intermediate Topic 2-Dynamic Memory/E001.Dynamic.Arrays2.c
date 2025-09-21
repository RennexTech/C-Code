#include <stdio.h>
#include <stdlib.h> // For malloc() and free()

// A professional-grade macro for a cleaner error message and exit.
#define CHECK_ALLOCATION(ptr) \
    if ((ptr) == NULL) { \
        fprintf(stderr, "Error: Memory allocation failed for " #ptr ". Exiting.\n"); \
        exit(EXIT_FAILURE); \
    }

int main() {
    int rows, cols;

    printf("Enter number of rows and columns for the 2D array: ");
    scanf("%d %d", &rows, &cols);

    /*
     *
     * ## The Blueprint: Building a "Scattered" Array
     *
     * Imagine you are a contractor building a new neighborhood. You don't have a single,
     * massive piece of land. Instead, you have a bunch of small, separate parcels.
     *
     * First, you need a blueprint. This `int **a` is that blueprint. It's a list that
     * will hold the starting address of each parcel of land. You can think of it as a
     * directory where each entry points to a different row in your 2D array.
     *
     * The line below allocates memory for that directory itself. It's a single,
     * contiguous block on the heap that's big enough to store 'rows' number of
     * pointers.
     *
     */
    int **a = malloc(rows * sizeof(int *));
    CHECK_ALLOCATION(a);
    
    // The `a` pointer now holds the address of this list.
    printf("Successfully allocated memory for %d row pointers at address: %p\n", rows, (void*)a);


    /*
     *
     * ## The Construction: Building Each Row Individually
     *
     * Now, you loop through your blueprint and buy each individual parcel of land.
     * Each piece of land is a separate `malloc()` call. This is why the rows in your
     * diagram are at non-contiguous addresses like `1800`, `2200`, and `2570`.
     *
     * This method is incredibly flexible. Each row can theoretically be a different
     * size, though in this example, we keep them all the same size for simplicity.
     * This flexibility is critical for things like handling a command line with a
     * variable number of arguments or processing a video where each frame is a
     * different size.
     *
     */
    for (int i = 0; i < rows; i++) {
        a[i] = malloc(cols * sizeof(int));
        CHECK_ALLOCATION(a[i]);
        printf("  - Allocated memory for row %d at address: %p\n", i, (void*)a[i]);
    }
    printf("\n");

    // Get the elements from the user.
    printf("Populating the array...\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("Enter element a[%d][%d]: ", i, j);
            scanf("%d", &a[i][j]);
        }
    }

    // Print the array.
    printf("\nThe matrix is:\n");
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            printf("%5d", a[i][j]);
        }
        printf("\n");
    }

    /*
     *
     * ## The Cleanup: Demolition and Waste Management
     *
     * This is the most crucial part. Since we made multiple `malloc()` calls, we **MUST**
     * make a matching number of `free()` calls. If you forget, you create a memory leak.
     * If you free the main directory `a` first, you lose all the addresses of the rows,
     * creating "orphan" memory that can never be freed. This is a common bug and a
     * frequent target for malware.
     *
     * The correct order is to first free the individual rows, then free the main
     * directory.
     *
     */
    printf("\nFreeing memory...\n");
    for (int i = 0; i < rows; i++) {
        free(a[i]);
    }
    free(a);
    printf("All memory freed successfully.\n");
    
    return 0;
}
