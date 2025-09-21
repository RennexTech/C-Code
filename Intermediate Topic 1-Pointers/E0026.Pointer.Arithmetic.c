#include <stdio.h>

int main() {
    // We'll create some variables of different types.
    char char_arr[4] = {'A', 'B', 'C', 'D'};
    int int_arr[4] = {10, 20, 30, 40};
    float float_arr[4] = {1.1f, 2.2f, 3.3f, 4.4f};
    double double_arr[4] = {10.1, 20.2, 30.3, 40.4};

    // Pointers to the first element of each array.
    char *p1 = char_arr;
    int *p2 = int_arr;
    float *p3 = float_arr;
    double *p4 = double_arr;

    printf("## Pointer Arithmetic Demonstration\n");
    printf("------------------------------------------\n");

    /*
     *
     * ### Pointers to Characters (`char`)
     *
     * A `char` is a single byte. When we increment a `char` pointer, it moves
     * one byte forward in memory. This is the smallest possible jump.
     *
     */
    printf("### Char Pointer\n");
    printf("Initial address of p1: %p, Value: %c\n", (void*)p1, *p1);
    p1++;
    printf("After p1++: address %p, Value: %c\n", (void*)p1, *p1);
    printf("Expected jump: 1 byte\n\n");

    /*
     *
     * ### Pointers to Integers (`int`)
     *
     * An `int` is typically 4 bytes. The compiler knows this, so when we
     * increment an `int` pointer, it automatically jumps forward by 4 bytes
     * to point to the next integer. It's smart like that.
     *
     */
    printf("### Int Pointer\n");
    printf("Initial address of p2: %p, Value: %d\n", (void*)p2, *p2);
    p2++;
    printf("After p2++: address %p, Value: %d\n", (void*)p2, *p2);
    printf("Expected jump: 4 bytes (on most systems)\n\n");

    /*
     *
     * ### Pointers to Floating-Point Numbers (`float`)
     *
     * A `float` is also typically 4 bytes. Just like with integers, the
     * compiler makes the pointer jump 4 bytes to the next `float` in memory.
     *
     */
    printf("### Float Pointer\n");
    printf("Initial address of p3: %p, Value: %.1f\n", (void*)p3, *p3);
    p3++;
    printf("After p3++: address %p, Value: %.1f\n", (void*)p3, *p3);
    printf("Expected jump: 4 bytes (on most systems)\n\n");

    /*
     *
     * ### Pointers to Double-Precision Numbers (`double`)
     *
     * A `double` is typically 8 bytes, which is a much larger jump. The
     * pointer knows to move by the size of a `double` to get to the next one.
     *
     */
    printf("### Double Pointer\n");
    printf("Initial address of p4: %p, Value: %.1f\n", (void*)p4, *p4);
    p4++;
    printf("After p4++: address %p, Value: %.1f\n", (void*)p4, *p4);
    printf("Expected jump: 8 bytes (on most systems)\n\n");
    
    /*
     *
     * ### The Pro's Analysis: Why This Matters
     *
     * This small program is a powerful lesson in how C works at the lowest level.
     * The compiler uses the pointer's type to perform an implicit multiplication
     * (`p + 1` is actually `p + 1 * sizeof(type)`). When you're analyzing
     * a **firmware dump** or a **binary file**, you'll see these size-based
     * offsets all over the place. For example, a function might walk through
     * a data structure by adding 16 bytes to a pointer on each loop. By
     * knowing your data types, you can deduce that it's likely a structure
     * that's 16 bytes in size.
     *
     * This is the kind of **reverse engineering** mindset that turns a stream
     * of bytes into a meaningful data structure, and it's a foundation for
     * everything you want to do with OS and network protocol analysis.
     *
     */

    return 0;
}
