#include <stdio.h>

int main() {
    // We'll use this array to demonstrate the operations.
    // Think of this as a small, continuous block of memory.
    int arr[] = {25, 38};

    /*
     *
     * ## The Set Up
     *
     * A beginner can think of this as our "data." We have two numbers.
     * `ptr` is a pointer that holds the address of the first number, 25.
     * `x` is a variable that will hold the value we grab from the array.
     *
     * An advanced user knows this is our stack-allocated data. `arr` is an
     * array of two integers. `ptr` is a pointer initialized to the base
     * address of `arr` (`&arr[0]`).
     *
     */
    int *ptr = arr;
    int x;

    printf("## Initial State\n");
    printf("----------------------------------\n");
    printf("Array elements: arr[0] = %d, arr[1] = %d\n", arr[0], arr[1]);
    printf("Address of arr[0]: %p\n", (void*)&arr[0]);
    printf("Address of ptr: %p\n", (void*)&ptr);
    printf("Value in ptr (address it points to): %p\n", (void*)ptr);
    printf("Value at *ptr: %d\n", *ptr);
    printf("----------------------------------\n\n");

    /*
     *
     * (i) x = *ptr++;
     *
     * ## Post-increment and Dereference
     *
     * A beginner can think of this as grabbing the value first, and then
     * taking a step. It's like a waiter taking your order (the value) and
     * then walking away to the next table (incrementing the pointer).
     *
     * An advanced user understands this is a **post-increment** operation.
     * The dereference (`*`) happens first, so the value at the current
     * address (`25`) is assigned to `x`. Then, `ptr` is incremented to
     * point to the next integer. The `++` has a higher precedence than `*`,
     * but the post-increment happens after the entire expression is evaluated.
     *
     */
    ptr = arr; // Reset the pointer for the demo
    x = *ptr++;
    printf("## (i) x = *ptr++\n");
    printf("----------------------------------\n");
    printf("Value of x: %d\n", x);
    printf("Address in ptr: %p\n", (void*)ptr);
    printf("Value at *ptr: %d\n", *ptr);
    printf("----------------------------------\n\n");

    /*
     *
     * (ii) x = *++ptr;
     *
     * ## Pre-increment and Dereference
     *
     * A beginner can think of this as taking a step first, and then grabbing
     * the value. It's like the waiter stepping to the next table and then
     * asking for your order.
     *
     * An advanced user understands this is a **pre-increment** operation.
     * The `++` happens first, so `ptr` is incremented to point to the next
     * integer (`arr[1]`). Then, the dereference (`*`) is performed, and the
     * value at the new address (`38`) is assigned to `x`.
     *
     */
    ptr = arr; // Reset the pointer
    x = *++ptr;
    printf("## (ii) x = *++ptr\n");
    printf("----------------------------------\n");
    printf("Value of x: %d\n", x);
    printf("Address in ptr: %p\n", (void*)ptr);
    printf("Value at *ptr: %d\n", *ptr);
    printf("----------------------------------\n\n");

    /*
     *
     * (iii) x = ++*ptr;
     *
     * ## Dereference and Pre-increment
     *
     * A beginner can think of this as grabbing the value, changing it, and
     * then assigning that new value. It's like finding a number, adding 1
     * to it, and then putting that new number in your pocket. The original
     * number in the memory location is also changed.
     *
     * An advanced user understands that this expression has two parts:
     * `*ptr` (dereference) and `++` (pre-increment). The `++` applies to
     * the value that `ptr` points to. The value at `*ptr` (`25`) is
     * incremented to `26`, and then that new value is assigned to `x`.
     * The address in `ptr` does **not** change.
     *
     */
    ptr = arr; // Reset the pointer
    x = ++*ptr;
    printf("## (iii) x = ++*ptr\n");
    printf("----------------------------------\n");
    printf("Value of x: %d\n", x);
    printf("Address in ptr: %p\n", (void*)ptr);
    printf("Value at *ptr: %d\n", *ptr);
    printf("----------------------------------\n\n");

    /*
     *
     * (iv) x = (*ptr)++;
     *
     * ## Dereference and Post-increment
     *
     * A beginner can think of this as grabbing a value, putting it in your
     * pocket, and then going back to the original spot to add 1 to it.
     *
     * An advanced user understands that the parentheses force the dereference
     * `*ptr` to happen first, grabbing the value `25`. This value is
     * assigned to `x`. Then, the post-increment operator (`++`) increments
     * the value at the memory location pointed to by `ptr` to `26`. The address
     * in `ptr` does **not** change.
     *
     */
    ptr = arr; // Reset the pointer
    x = (*ptr)++;
    printf("## (iv) x = (*ptr)++\n");
    printf("----------------------------------\n");
    printf("Value of x: %d\n", x);
    printf("Address in ptr: %p\n", (void*)ptr);
    printf("Value at *ptr: %d\n", *ptr);
    printf("----------------------------------\n\n");
    
    return 0;
}
