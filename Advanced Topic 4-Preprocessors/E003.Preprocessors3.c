//Define MAX and Print It:

#define MAX 5
main ( ) {
    printf("%d", MAX);
}

//This code defines MAX and prints it. It's a standalone program.
//Define MSSG and Print It:

#define MSSG printf("If you lapse, don't collapse\n")
main ( ) {
    MSSG;
}

//This code defines MSSG (a message) and prints it. It's also a standalone program.
//Define PROD Macro and Compute Product:

#define PROD(x, y) (x * y)
main ( ) {
    int a = 3, b = 4;
    printf("Product of a and b = %d", PROD(a, b));
}

//This code defines a macro PROD and uses it to calculate the product of a and b. It's another standalone program.
//Define A and B Macros:

#define A 50
#define B A + 100
main ( ) {
    int i, j;
    i = B / 20;
    j = 500 - B;
    printf("i = %d, j = %d\n", i, j);
}

//This code defines macros A and B and then uses them in calculations. It's also a standalone program.
//Define NEW_LINE and BLANK_LINES Macros:

#define NEW_LINE printf("\n");
#define BLANK_LINES(n) { int i; for(i = 0; i < n; i++) printf("\n"); }
main ( ) {
    printf("When you have a chance");
    NEW_LINE;
    printf("to embrace an opportunity");
    BLANK_LINES(3);
    printf("Give it a big hug");
    NEW_LINE;
}

//This code defines macros for new lines and blank lines and uses them to format output. It's also a standalone program.
//Define INFINITE and CHECK Macros:

#define INFINITE while (1)
#define CHECK(a) if (a == 0) break
main ( ) {
    int x = 5;
    INFINITE {
        printf("%d ", x);
        CHECK(x);
        x--;
    }
}

//This code defines macros for an infinite loop and a check. It's another standalone program.
//Define ABS Macro and Use It with an Array: (This code defines a macro for absolute value and uses it with an array. It's also a standalone program.)

#define ABS(x) ((x) < 0 ? -(x) : (x))
main ( ) {
    int array[4] = {1, -2, 3, -4};
    int *p = array + 3;
    while (p >= array) {
        printf("%d ", ABS(*p));
        p--;
    }
}

/*Program that does several things using macros*/
#include <stdio.h>

// Macro to calculate the cube of a number
#define CUBE(x) ((x) * (x) * (x))

// Macro to swap two values
#define SWAP(dtype, x, y) {dtype t; t = x, x = y, y = t;}

// Macro to increment a value
#define INC(dtype, x, i) x = x + i

// Macro to calculate the difference between two numbers
#define DIFF(FNAME, DTYPE, RTYPE) \
  RTYPE FNAME(DTYPE X, DTYPE Y) { \
    return X - Y; \
  }

// Calculate the difference for different data types
DIFF(diff_int, int, int)
DIFF(diff_iptr, int*, int)
DIFF(diff_float, float, float)
DIFF(diff_fptr, float*, int)

int main() {
    // 1. Calculate and print the cube of (1+2)
    printf("Cube of (1+2) = %d\n", CUBE(1 + 2));

    // 2. Swap values and print the results
    int a = 1, b = 2, x = 3, y = 4, s = 25, t = 26;
    SWAP(int, a, b)
    SWAP(int, x, y)
    SWAP(int, s, t)
    printf("a=%d, b=%d, x=%d, y=%d, s=%d, t=%d\n", a, b, x, y, s, t);

    // 3. Increment a value and print it
    int arr[5] = {20, 34, 56, 12, 96};
    int *ptr = arr;
    INC(int, arr[2], 3);
    INC(int*, ptr, 2);
    printf("*ptr = %d\n", *ptr);

    // 4. Print values using the difference functions
    int iarr[5] = {1, 2, 3, 4, 5};
    float farr[7] = {1.2, 2.3, 3.4, 4.5, 5.6, 6.7, 7.8};
    a = diff_int(iarr[4], iarr[0]);
    float b = diff_float(farr[6], farr[2]);
    p = diff_iptr(&iarr[4], &iarr[0]);
    q = diff_fptr(&farr[4], &farr[1]);
    printf("a = %d, b = %.1f, p = %d, q = %d\n", a, b, p, q);

    // 5. Define and print MAX
    #define MAX 3
    printf("Value of MAX is %d\n", MAX);
    #undef MAX

    // 6. Use preprocessor directives to display messages
    #define PRINT1(message)
    #define PRINT2(message) printf(message);
    #define PRINT3(message) printf(#message);

    PRINT1("If we rest, ")
    PRINT2("If we rest, ")
    PRINT3("If we rest, we rust.\n")

    // 7. Use #line directive
    #line 100 "system.e"
    printf("%d %s\n", __LINE__, __FILE__);

    return 0;
}


/*

The provided C program is a collection of macros and code snippets that demonstrate various preprocessor directives and their functionality. Let's break down each part of the program and explain what it does in depth:

Macros for Cube, Swap, and Increment:

The program defines three macros: CUBE(x), SWAP(dtype, x, y), and INC(dtype, x, i).
CUBE(x) calculates the cube of a number x.
SWAP(dtype, x, y) swaps two values x and y of a specified data type dtype.
INC(dtype, x, i) increments a value x by i.
Difference Functions (DIFF):

The program defines a macro DIFF(FNAME, DTYPE, RTYPE) to generate difference functions.
It uses this macro to create difference functions for different data types: diff_int, diff_iptr, diff_float, and diff_fptr.
These functions calculate the difference between two values of the specified data types.
Cube of (1+2):

The program calculates and prints the cube of (1+2) using the CUBE macro.
Swapping Values:

It swaps the values of variables a, b, x, y, s, and t using the SWAP macro.
Then, it prints the values of these variables after the swaps.
Incrementing Values:

It increments the third element of an integer array arr by 3.
It also increments a pointer ptr by 2.
The program then prints the updated value pointed to by ptr.
Difference Functions in Action:

It uses the difference functions created earlier to calculate and print differences between values from integer and float arrays.
Define and Undefine MAX:

The program defines MAX as 3 and prints its value.
Then, it undefines MAX using #undef.
Displaying Messages with Macros:

It defines three macros (PRINT1, PRINT2, PRINT3) for displaying messages.
These macros are used to demonstrate different ways to display messages using preprocessor directives.
Using #line Directive:

The #line directive sets the line number and filename for the source code.
In this case, it sets the line number to 100 and the filename to "system.e".
It then prints the line number and filename using __LINE__ and __FILE__ predefined macros.
Overall, this program is a demonstration of various preprocessor directives and macros in C. It showcases how macros can simplify repetitive tasks and how preprocessor directives can control compilation and code generation.

*/























