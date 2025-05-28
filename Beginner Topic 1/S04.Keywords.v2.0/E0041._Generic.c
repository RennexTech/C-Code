/**
 *
 * _Generic is C’s version of function overloading — kinda.
 *
 * It picks a value or expression based on the type, like a smart vending machine that gives different snacks depending on your height.
 *
 * Helps make type-safe macros or function-like expressions in plain C.
 *
 */

#include <stdio.h>

#define type_name(x) _Generic((x), \
    int: "int", \
    float: "float", \
    double: "double", \
    default: "unknown")

int main() {
    printf("--------------------------------------------\n");
    printf("41. _Generic\n");
    printf("--------------------------------------------\n");
    printf("'_Generic' is C’s way of simulating function overloading — it selects behavior based on the type.\n");
    printf("--------------------------------------------\n");

    int a = 1;
    float b = 2.0f;
    double c = 3.0;

    printf("a is of type: %s\n", type_name(a));
    printf("b is of type: %s\n", type_name(b));
    printf("c is of type: %s\n", type_name(c));

    return 0;
}


//=================================== ANOTHER EXAMPLE ============================


#include <stdio.h>   // For printf
#include <unistd.h>  // For sleep

/**
 * * _Generic is a compiler magic trick! 
 * * It lets you write one function that acts differently based on the *type* of data you pass to it. 
 * * Like a smart tool that knows if you gave it a hammer or a screwdriver and adjusts its behavior. 
 * * Makes code cleaner for similar operations on different types, avoiding repetitive code.
 * */

// Define a generic macro for printing different types
// This macro will choose which printf format to use based on the type of 'x'
#define PRINT_VALUE(x) _Generic((x), \
    int:    printf("Int value: %d\\n", x), \
    float:  printf("Float value: %.2f\\n", x), \
    double: printf("Double value: %.4f\\n", x), \
    char*:  printf("String value: %s\\n", x), \
    default: printf("Unknown type!\\n") \
)

int main() {
    printf("--------------------------------------------\n");
    printf("41. _Generic (C11)\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("A compiler magic trick! It lets you write one function that acts differently based on the *type* of data you pass to it. Like a smart tool that knows if you gave it a hammer or a screwdriver and adjusts its behavior. Makes code cleaner for similar operations on different types.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int int_data = 123;
    float float_data = 45.67f;
    double double_data = 987.654321;
    char* string_data = "Hello _Generic!";
    char single_char = 'X'; // This will hit 'default' as 'char' is not explicitly handled

    printf("Using PRINT_VALUE macro with different types:\n");
    sleep(1);

    PRINT_VALUE(int_data);
    sleep(1);
    PRINT_VALUE(float_data);
    sleep(1);
    PRINT_VALUE(double_data);
    sleep(1);
    PRINT_VALUE(string_data);
    sleep(1);
    PRINT_VALUE(single_char); // Will print "Unknown type!" because 'char' is not a specific case

    printf("Note: Super useful for creating flexible, type-aware macros that adapt to the data you give them. It's a compile-time feature.\n");
    printf("--------------------------------------------\n");
    sleep(5);
    return 0;
}
