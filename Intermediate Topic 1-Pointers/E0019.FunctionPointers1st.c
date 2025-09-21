#include <stdio.h>

/*
 *
 * ## Pass-by-Value: The Copycat Function
 *
 * In C, when you pass a variable to a function, you're not giving the function
 * the original variable. You're just giving it a copy of the variable's value.
 *
 * Think of it like this: You have a secret blueprint for a new hacking tool.
 * You send a copy of the blueprint to a friend to get their feedback. Your friend
 * can scribble all over their copy, but your original blueprint stays perfectly
 * clean and untouched.
 *
 * This is "pass-by-value." The function works on a local copy, and any changes
 * it makes are confined to its own little world. Once the function is done,
 * its copies are destroyed, and your original variables are exactly as they were.
 *
 * For a reverse engineer, this matters a lot. When you're looking at a function
 * call, you have to know if it's operating on a local copy or if it has access
 * to the original data in the main program's memory space. This helps you figure
 * out where data is being modified in a program's execution flow.
 *
 */

// A function that demonstrates pass-by-value.
// It takes two integers by value, so it gets copies.
void increment_values(int x, int y) {

    printf("\n## Inside the 'increment_values' function:\n");
    printf("-------------------------------------------\n");
    printf("Before incrementing:\n");
    printf("   x (value): %d | Address: %p\n", x, (void*)&x);
    printf("   y (value): %d | Address: %p\n", y, (void*)&y);

    // Now we increment our local copies.
    x++;
    y++;

    printf("\nAfter incrementing:\n");
    printf("   x (value): %d | Address: %p\n", x, (void*)&x);
    printf("   y (value): %d | Address: %p\n", y, (void*)&y);
    printf("-------------------------------------------\n");
}

int main() {
    int a = 5;
    int b = 8;

    printf("## Inside 'main' function, Before calling 'increment_values':\n");
    printf("-----------------------------------------------------------\n");
    printf("   a (value): %d | Address: %p\n", a, (void*)&a);
    printf("   b (value): %d | Address: %p\n", b, (void*)&b);
    printf("-----------------------------------------------------------\n");

    // We call the function and pass the VALUES of 'a' and 'b'.
    increment_values(a, b);

    printf("\n## Inside 'main' function, After calling 'increment_values':\n");
    printf("-----------------------------------------------------------\n");
    printf("   a (value): %d | Address: %p\n", a, (void*)&a);
    printf("   b (value): %d | Address: %p\n", b, (void*)&b);
    printf("-----------------------------------------------------------\n");
    
    /*
     *
     * ## The Pro's Analysis: The Memory Is Different
     *
     * Look at the output closely. The memory addresses of `a` and `b` in `main()`
     * are completely different from the addresses of `x` and `y` in the function.
     * The values of `a` and `b` remain `5` and `8`, proving that the function's
     * actions did not affect the original variables.
     *
     * The `(void*)` cast is a small but important detail. It tells the compiler to
     * treat the address as a generic pointer, which prevents it from throwing a
     * warning when we try to print it. This is a common practice when you need to
     * inspect raw memory addresses.
     *
     */

    return 0;
}
