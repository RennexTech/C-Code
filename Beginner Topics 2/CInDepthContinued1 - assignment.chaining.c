#include <stdio.h>
#include <stdlib.h> // Not strictly needed here

int main() {
    /*
     * This program demonstrates two key concepts in C:
     * 1. Assignment Chaining: How to assign the same value to multiple variables
     * in a single line (e.g., x = y = z = 200).
     * 2. Compound Assignment Operators: Shorthand ways to perform an operation
     * and assign the result back to the same variable (e.g., x += 5 is
     * the same as x = x + 5).
     * This helps in writing more concise and efficient code.
     */
    int x, y, z, f, g, h;
    x = y = z = f = g = h = 200;
    printf("x is: %d\n", x);
    printf("y is: %d\n", y);
    printf("z is: %d\n", z);
    printf("f is: %d\n", f);
    printf("g is: %d\n", g);
    printf("h is: %d\n", h);

    x = x + 65; // can also be x+= 65;
    y += 64;
    printf("The new x is: %d\n", x);
    printf("The new y is: %d\n", y);

    return 0;
}
