#include <stdio.h>    // For printf, duh
#include <stdlib.h>   // For general utilities (not strictly needed here, but whatever)
#include <limits.h>   // Constants for integer limits
#include <float.h>    // Constants for floating-point limits
#include <stdbool.h>  // bool, true, false — making C less grumpy

/**
 * @brief Shows C primitive data types sizes and their value ranges.
 * 
 * This demo is all about how much space types gobble up and their limits,
 * with some example variables thrown in for flavor.
 */

int main() {
    printf("=============================================================\n");
    printf("  C Data Types: Sizes and Ranges (System-dependent values)  \n");
    printf("=============================================================\n");

    // INTEGER TYPES
    printf("\n--- Integer Types ---\n");
    printf("%-18s | %-12s | %-30s\n", "Type", "Size (bytes)", "Range");
    printf("--------------------|--------------|------------------------------\n");

    printf("%-18s | %12zu | %d to %d\n", "char", sizeof(char), SCHAR_MIN, SCHAR_MAX);
    printf("%-18s | %12zu | %u to %u\n", "unsigned char", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("%-18s | %12zu | %d to %d\n", "short", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("%-18s | %12zu | %u to %u\n", "unsigned short", sizeof(unsigned short), 0, USHRT_MAX);
    printf("%-18s | %12zu | %d to %d\n", "int", sizeof(int), INT_MIN, INT_MAX);
    printf("%-18s | %12zu | %u to %u\n", "unsigned int", sizeof(unsigned int), 0, UINT_MAX);
    printf("%-18s | %12zu | %ld to %ld\n", "long", sizeof(long), LONG_MIN, LONG_MAX);
    printf("%-18s | %12zu | %lu to %lu\n", "unsigned long", sizeof(unsigned long), 0UL, ULONG_MAX);
    printf("%-18s | %12zu | %lld to %lld\n", "long long", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("%-18s | %12zu | %llu to %llu\n", "unsigned long long", sizeof(unsigned long long), 0ULL, ULLONG_MAX);

    // FLOATING POINT TYPES
    printf("\n--- Floating-Point Types ---\n");
    printf("%-18s | %-12s | %-30s\n", "Type", "Size (bytes)", "Range (approximate)");
    printf("--------------------|--------------|------------------------------\n");

    printf("%-18s | %12zu | %e to %e\n", "float", sizeof(float), FLT_MIN, FLT_MAX);
    printf("%-18s | %12zu | %e to %e\n", "double", sizeof(double), DBL_MIN, DBL_MAX);
    printf("%-18s | %12zu | %Le to %Le\n", "long double", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // BOOLEAN TYPE
    printf("\n--- Boolean Type ---\n");
    printf("%-18s | %12zu | %s\n", "bool", sizeof(bool), "true (1), false (0)");

    // Quick example variables — so it’s not just dry facts
    printf("\n--- Quick Example Values ---\n");
    char my_char = 'Z';
    int my_int = 42;
    double my_double = 3.14159;
    bool my_bool = true;

    printf("char: '%c' (ASCII %d)\n", my_char, my_char);
    printf("int: %d\n", my_int);
    printf("double: %.5lf\n", my_double);
    printf("bool: %d (true)\n", my_bool);

    printf("=============================================================\n");

    return 0; // Exit gracefully
}
