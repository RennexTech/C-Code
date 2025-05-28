/**
 *
 * _Alignof tells you how a type is aligned in memory — how many bytes it needs to line up correctly.
 *
 * Think of it like asking: “How wide is this parking space?” before pulling in your truck (a data type).
 *
 * It helps when writing memory-efficient or low-level code that cares about alignment boundaries.
 *
 */

#include <stdio.h>
#include <stdalign.h>

int main() {
    printf("--------------------------------------------\n");
    printf("39. _Alignof\n");
    printf("--------------------------------------------\n");
    printf("'_Alignof' gives the alignment requirement (in bytes) of a type. Useful for low-level memory tricks.\n");
    printf("--------------------------------------------\n");

    printf("Alignment of char: %zu bytes\n", _Alignof(char));
    printf("Alignment of int: %zu bytes\n", _Alignof(int));
    printf("Alignment of double: %zu bytes\n", _Alignof(double));

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================

#include <stdio.h>    // For printf
#include <stdalign.h> // For _Alignof
#include <unistd.h>   // For sleep

/**
 * * _Alignof is your memory alignment inspector! 
 * * It tells you the required alignment of a type. 
 * * Like asking: 'How many bytes does this data type need to be perfectly aligned in memory?' 
 * * It's useful for understanding how the compiler packs your data and for working with _Alignas.
 * */

// A simple struct
struct MyData {
    char a;
    int b;
    double c;
};

int main() {
    printf("--------------------------------------------\n");
    printf("39. _Alignof (C11)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("Your memory alignment inspector! It tells you the required alignment of a type. Like asking: 'How many bytes does this data type need to be perfectly aligned in memory?'\n");
    printf("--------------------------------------------\n");
    sleep(1);

    printf("Required alignment for 'char': %zu bytes\n", _Alignof(char));
    sleep(1);
    printf("Required alignment for 'int': %zu bytes\n", _Alignof(int));
    sleep(1);
    printf("Required alignment for 'double': %zu bytes\n", _Alignof(double));
    sleep(1);
    printf("Required alignment for 'struct MyData': %zu bytes\n", _Alignof(struct MyData));
    sleep(1);

    printf("Note: Alignment is how the compiler organizes data in memory for optimal performance. Different data types have different alignment requirements. This keyword helps you inspect those rules.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}

