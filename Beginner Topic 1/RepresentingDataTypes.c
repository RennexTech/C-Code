#include <stdio.h>   // Standard input/output functions (printf)
#include <stdlib.h>  // Standard library functions (not strictly needed here)
#include <limits.h>  // Defines limits of integer types (e.g., INT_MAX, SHRT_MIN)
#include <float.h>   // Defines limits of floating-point types (e.g., FLT_MAX, DBL_MIN)
#include <stdbool.h> // Defines 'bool', 'true', 'false' macros

/**
 * @brief Main function to demonstrate C data types, their sizes, and ranges.
 *
 * This program uses the sizeof operator and constants from <limits.h> and <float.h>
 * to display typical memory consumption and value ranges for fundamental C data types.
 */

int main()
{
    printf("--------------------------------------------------------------------------------\n");
    printf("C Data Types: Sizes and Ranges (Typical Values - May Vary by System/Compiler)\n");
    printf("--------------------------------------------------------------------------------\n");

    // Integer Types
    printf("\n--- Integer Types ---\n");
    printf("Type             | Size (bytes) | Range                                            \n");
    printf("-----------------|--------------|--------------------------------------------------\n");

    printf("char             | %12zu | %d to %d\n", sizeof(char), SCHAR_MIN, SCHAR_MAX);
    printf("unsigned char    | %12zu | %u to %u\n", sizeof(unsigned char), 0, UCHAR_MAX);
    printf("short            | %12zu | %d to %d\n", sizeof(short), SHRT_MIN, SHRT_MAX);
    printf("unsigned short   | %12zu | %u to %u\n", sizeof(unsigned short), 0, USHRT_MAX);
    printf("int              | %12zu | %d to %d\n", sizeof(int), INT_MIN, INT_MAX);
    printf("unsigned int     | %12zu | %u to %u\n", sizeof(unsigned int), 0, UINT_MAX);
    printf("long             | %12zu | %ld to %ld\n", sizeof(long), LONG_MIN, LONG_MAX);
    printf("unsigned long    | %12zu | %lu to %lu\n", sizeof(unsigned long), 0UL, ULONG_MAX);
    printf("long long        | %12zu | %lld to %lld\n", sizeof(long long), LLONG_MIN, LLONG_MAX);
    printf("unsigned long long| %12zu | %llu to %llu\n", sizeof(unsigned long long), 0ULL, ULLONG_MAX);

    // Floating-Point Types
    printf("\n--- Floating-Point Types ---\n");
    printf("Type             | Size (bytes) | Range (Approximate)                               \n");
    printf("-----------------|--------------|---------------------------------------------------\n");

    printf("float            | %12zu | %e to %e\n", sizeof(float), FLT_MIN, FLT_MAX);
    printf("double           | %12zu | %e to %e\n", sizeof(double), DBL_MIN, DBL_MAX);
    printf("long double      | %12zu | %Le to %Le\n", sizeof(long double), LDBL_MIN, LDBL_MAX);

    // Boolean Type
    printf("\n--- Boolean Type ---\n");
    printf("Type             | Size (bytes) | Values                                           \n");
    printf("-----------------|--------------|--------------------------------------------------\n");
    printf("bool             | %12zu | true (1), false (0)                              \n", sizeof(bool));

    // Example Usage
    printf("\n--- Example Values ---\n");
    char my_char = 'A';
    int my_int = 12345;
    double my_double = 3.14159;
    bool my_bool = true;

    printf("char: '%c' (ASCII %d)\n", my_char, my_char);
    printf("int: %d\n", my_int);
    printf("double: %.5lf\n", my_double);
    printf("bool: %d (true)\n", my_bool); // bool prints as 0 or 1

    printf("--------------------------------------------------------------------------------\n");

    return 0; // Indicates successful program execution
}
