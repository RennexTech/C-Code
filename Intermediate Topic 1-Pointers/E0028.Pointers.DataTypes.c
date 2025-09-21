#include <stdio.h>

int main() {
    // We'll declare two variables, just like your diagram.
    int age = 30;
    float salary = 1500.50f;

    /*
     *
     * ## The Set Up
     *
     * A beginner can think of this like creating two boxes in memory. One
     * box is for an integer (a whole number), and the other is for a float
     * (a number with a decimal).
     *
     * An advanced user knows that `age` and `salary` are stack-allocated
     * variables. `age` occupies 4 bytes (on most systems), and `salary` also
     * occupies 4 bytes.
     *
     */
    printf("## Variables in Memory\n");
    printf("-----------------------------------------\n");
    printf("Value of age: %d\n", age);
    printf("Memory address of age: %p\n", (void*)&age);
    printf("Value of salary: %.2f\n", salary);
    printf("Memory address of salary: %p\n", (void*)&salary);
    printf("-----------------------------------------\n\n");


    // Now, we create pointers to these variables. The pointer's type must match
    // the variable's type.
    int *iptr;
    float *fptr;

    /*
     *
     * ## The Pointers
     *
     * For a beginner, think of a pointer as a sticky note that has an address
     * written on it. The type of the pointer (like `int*`) is like writing
     * "This is a house address" on the sticky note. It tells you what kind of
     * thing to expect at that address.
     *
     * For an advanced user, we're declaring two pointers on the stack. Their
     * size is dependent on the system's architecture (e.g., 8 bytes on a 64-bit system),
     * and they will be used to hold the memory addresses of our variables.
     *
     */
    iptr = &age;
    fptr = &salary;

    printf("## Pointers Pointing to Variables\n");
    printf("-----------------------------------------\n");
    printf("Value in iptr (address of age): %p\n", (void*)iptr);
    printf("Value at *iptr (the value it points to): %d\n", *iptr);
    printf("Value in fptr (address of salary): %p\n", (void*)fptr);
    printf("Value at *fptr (the value it points to): %.2f\n", *fptr);
    printf("-----------------------------------------\n\n");

    /*
     *
     * ## The Pro's Analysis: Why This Matters
     *
     * This simple program is a foundation for understanding complex data
     * structures. In a reverse engineering scenario, you might see a function
     * receive a memory address and then try to read data from it. The
     * **instruction** the function uses to read that data will implicitly tell
     * you the data type. For instance, `mov eax, [ptr]` on a 32-bit system would
     * read 4 bytes (an integer or a float), while `mov al, [ptr]` would read only
     * 1 byte. By matching the instruction with the size, you can deduce the
     * type of data the pointer is referencing.
     *
     * In **Android firmware analysis**, you'll see pointers to various hardware
     * registers, which might be `unsigned int`s for status flags or `float`s for
     * sensor readings. Your ability to map a memory address to its intended data type
     * is how you'll reverse-engineer the device's functionality.
     *
     */

    return 0;
}
