/**
 * 
 * sizeof is like your program's built-in measuring tape. 
 * 
 * It tells you exactly how much space (in bytes) a variable or a data type takes up in your computer's memory. 
 * 
 * Need to know if your 'int' is a tiny sticky note or a bigger box? 
 * 
 * sizeof will give you the exact dimensions. 
 * 
 * It's super handy when you're trying to manage memory efficiently or work with complex data structures.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("23. sizeof\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'sizeof' is like your program's built-in measuring tape. It tells you exactly how much space (in bytes) a variable or a data type takes up in your computer's memory... It's super handy when you're trying to manage memory efficiently or work with complex data structures.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int my_integer = 10;
    char my_char = 'A';
    double my_double = 3.14;

    printf("Size of int: %zu bytes\n", sizeof(int));
    printf("Size of my_integer variable: %zu bytes\n", sizeof(my_integer)); // Same as sizeof(int)

    printf("Size of char: %zu bytes\n", sizeof(char));
    printf("Size of my_char variable: %zu bytes\n", sizeof(my_char));

    printf("Size of double: %zu bytes\n", sizeof(double));
    printf("Size of my_double variable: %zu bytes\n", sizeof(my_double));

    int numbers[] = {1, 2, 3, 4, 5};
    printf("Size of 'numbers' array: %zu bytes\n", sizeof(numbers)); // Total bytes of the array
    printf("Number of elements in 'numbers' array: %zu\n", sizeof(numbers) / sizeof(numbers[0]));

    printf("Size of a pointer (e.g., to an int): %zu bytes\n", sizeof(int*)); // Size of a memory address
    sleep(5);
    return 0;
}