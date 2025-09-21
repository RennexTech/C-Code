#include <stdio.h>

int main() {
    // We'll declare our integer variable. This is our final destination.
    int a = 5;

    // This is a pointer that holds the address of 'a'.
    // A beginner can think of this as a piece of paper with a house address on it.
    // The house address is where you'll find the value of 'a'.
    int *pa;

    // This is a pointer to a pointer. It holds the address of 'pa'.
    // This is like a second piece of paper that tells you where to find the first piece of paper.
    int **ppa;

    /*
     *
     * ## The Set Up
     *
     * We're initializing our pointers here.
     * `pa = &a;` means "make the pointer `pa` hold the address of the variable `a`."
     * `ppa = &pa;` means "make the pointer `ppa` hold the address of the pointer `pa`."
     *
     */
    pa = &a;
    ppa = &pa;

    printf("## Values and Addresses\n");
    printf("----------------------------------\n");
    
    // Printing the value of 'a' and its address.
    // This is the starting point.
    printf("Value of a: %d\n", a);
    printf("Address of a: %p\n", (void*)&a);
    printf("\n");

    // Printing the value of 'pa' (which is the address of 'a') and the value at `*pa`.
    // The value at `*pa` should be the value of `a`.
    printf("Value of pa: %p\n", (void*)pa);
    printf("Value of *pa: %d\n", *pa);
    printf("Address of pa: %p\n", (void*)&pa);
    printf("\n");

    // Printing the value of `ppa` (the address of `pa`) and the value at `*ppa` and `**ppa`.
    // The value at `*ppa` should be the address of `a`.
    // The value at `**ppa` should be the value of `a`.
    printf("Value of ppa: %p\n", (void*)ppa);
    printf("Value of *ppa: %p\n", (void*)*ppa);
    printf("Value of **ppa: %d\n", **ppa);
    printf("Address of ppa: %p\n", (void*)&ppa);
    printf("----------------------------------\n\n");
    
    /*
     *
     * ## Pro-Level Analysis: Why This Matters
     *
     * In **Windows API programming**, you'll often encounter this concept
     * in functions that return data or status information. For instance,
     * a function like `CreateThread` might take a pointer to a `DWORD` to
     * write the thread ID to. To get the thread ID back into your `main()`
     * function, you'd pass the address of a `DWORD` variable, which is a
     * pointer to it.
     *
     * In more complex scenarios, such as when dealing with memory-mapped
     * files or dynamically allocated structures on the **heap**, functions
     * might return a pointer to a pointer. For example, `realloc` returns
     * a new pointer to a potentially moved memory block. If you want to update
     * the original pointer, you'd have to pass a pointer to that pointer.
     *
     * This also opens the door to **security vulnerabilities**. If a function
     * doesn't properly validate the pointer to a pointer it's given, it might
     * write an address to an attacker-controlled memory location, a bug known as
     * a **double-pointer write vulnerability**. This can be a goldmine for
     * **malware authors** looking for a way to gain control over a program's
     * execution flow.
     *
     */

    return 0;
}
