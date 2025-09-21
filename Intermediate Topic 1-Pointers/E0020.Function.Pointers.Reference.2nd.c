#include <stdio.h>

/*
 *
 * ## Pass-by-Reference: The Shared Data Access
 *
 * In contrast to pass-by-value, C allows you to give a function direct access
 * to a variable's memory location. This is called "pass-by-reference," and you
 * do it by passing a pointer to the variable.
 *
 * Think of the pointer as a secret key to a vault. You give the key to a friend.
 * They don't have a copy of the treasure inside; they have the key to the original
 * vault. Anything they do inside the vault (like adding or removing treasure)
 * affects the original treasure, because they're working on the original data.
 *
 * This is how functions in C can actually modify the values of variables that
 * were created in another function, like `main()`. This is fundamental for
 * everything from a simple `swap` function to complex memory manipulation
 * in systems programming and kernel drivers.
 *
 */

// A function that demonstrates pass-by-reference.
// It takes two integer pointers, so it gets the memory addresses, not the values.
void increment_by_reference(int *p, int *q) {

    printf("\n## Inside the 'increment_by_reference' function:\n");
    printf("-------------------------------------------\n");
    printf("Before incrementing:\n");
    printf("   p (value): %p | Address: %p\n", (void*)p, (void*)&p);
    printf("   q (value): %p | Address: %p\n", (void*)q, (void*)&q);
    printf("   *p (value): %d\n", *p);
    printf("   *q (value): %d\n", *q);

    // Now we dereference the pointers and increment the VALUES at the addresses.
    // This is the key step: we are modifying the ORIGINAL variables.
    (*p)++;
    (*q)++;

    printf("\nAfter incrementing:\n");
    printf("   *p (value): %d\n", *p);
    printf("   *q (value): %d\n", *q);
    printf("-------------------------------------------\n");
}

int main() {
    int a = 5;
    int b = 8;

    printf("## Inside 'main' function, Before calling 'increment_by_reference':\n");
    printf("-----------------------------------------------------------\n");
    printf("   a (value): %d | Address: %p\n", a, (void*)&a);
    printf("   b (value): %d | Address: %p\n", b, (void*)&b);
    printf("-----------------------------------------------------------\n");

    // We call the function and pass the ADDRESSES of 'a' and 'b' using the '&' operator.
    increment_by_reference(&a, &b);

    printf("\n## Inside 'main' function, After calling 'increment_by_reference':\n");
    printf("-----------------------------------------------------------\n");
    printf("   a (value): %d | Address: %p\n", a, (void*)&a);
    printf("   b (value): %d | Address: %p\n", b, (void*)&b);
    printf("-----------------------------------------------------------\n");
    
    /*
     *
     * ## The Pro's Analysis: The Memory is the Same
     *
     * The output proves that the memory addresses of `a` and `b` in `main()` are the
     * exact same addresses stored in the pointers `p` and `q` inside the function.
     * When we incremented the values at those addresses, the original variables `a`
     * and `b` were directly modified.
     *
     * This is a critical concept for exploit development. A malicious function might
     * receive a pointer to a user-controlled buffer. By writing past the intended
     * end of that buffer, it can overwrite sensitive variables or even the return
     * address of the function on the stack, hijacking the program's execution flow.
     * Understanding this mechanism is the first step to building robust defenses.
     *
     */

    return 0;
}
