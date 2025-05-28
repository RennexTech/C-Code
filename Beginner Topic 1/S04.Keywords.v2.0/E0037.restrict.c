/**
 *
 * restrict is like pinky-swearing to the compiler: “This pointer is the ONLY way to access this data.”
 *
 * It unlocks optimizations by giving the compiler permission to assume no overlapping memory access.
 *
 * Used in performance-critical code like graphics or scientific computing.
 *
 */

#include <stdio.h>

void add_arrays(int *restrict a, int *restrict b, int *restrict result, int n) {
    for (int i = 0; i < n; ++i) {
        result[i] = a[i] + b[i];
    }
}

int main() {
    printf("--------------------------------------------\n");
    printf("37. restrict\n");
    printf("--------------------------------------------\n");
    printf("'restrict' tells the compiler that a pointer is the only way to access that memory. Use it for optimization.\n");
    printf("--------------------------------------------\n");

    int a[] = {1, 2, 3};
    int b[] = {4, 5, 6};
    int result[3];

    add_arrays(a, b, result, 3);

    for (int i = 0; i < 3; i++) {
        printf("result[%d] = %d\n", i, result[i]);
    }

    return 0;
}



//=================================== ANOTHER EXAMPLE ============================


#include <stdio.h>   // For printf
#include <unistd.h>  // For sleep

/**
 * * restrict is a promise to the compiler: 'Yo, these two pointers? 
 * * They will *never* point to the same memory!' 
 * * This lets the compiler optimize code way harder, assuming it doesn't have to worry about weird overlaps. 
 * * Super important for high-performance code, especially with arrays and memory operations. 
 * * It's like giving the compiler a green light to go full speed on optimization.
 * */

// Function using 'restrict' pointers
// 'dest' and 'src' are guaranteed not to overlap in memory
void copy_data_restrict(int * restrict dest, const int * restrict src, int n) {
    printf("  [Inside copy_data_restrict] Copying %d elements...\n", n);
    for (int i = 0; i < n; i++) {
        dest[i] = src[i];
    }
    printf("  [Inside copy_data_restrict] Copy complete.\n");
}

int main() {
    printf("--------------------------------------------\n");
    printf("37. restrict (C99)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("This is a promise to the compiler: 'Yo, these two pointers? They will *never* point to the same memory!' This lets the compiler optimize code way harder, assuming it doesn't have to worry about weird overlaps. Super important for high-performance code, especially with arrays.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int source_array[] = {10, 20, 30, 40, 50};
    int destination_array[5];
    int num_elements = 5;

    printf("Source array: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", source_array[i]);
    }
    printf("\n");
    sleep(1);

    printf("Calling copy_data_restrict...\n");
    copy_data_restrict(destination_array, source_array, num_elements);
    sleep(1);

    printf("Destination array after copy: ");
    for (int i = 0; i < num_elements; i++) {
        printf("%d ", destination_array[i]);
    }
    printf("\n");
    sleep(1);

    printf("Note: 'restrict' is a powerful optimization hint. If you break the promise (make pointers overlap when they shouldn't), your program might have weird bugs. Best used when you know what you're doing!\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
