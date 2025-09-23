#include <stdio.h>
#include <stdlib.h>

/*
 * Section 1: Memory Layout with a Struct
 *
 * Imagine a struct is a blueprint for a house. It defines the rooms
 * (the variables) and their order. When you build the house (create an
 * instance of the struct), the builder allocates a contiguous block of
 * land (memory) big enough for all the rooms, and they are arranged
 * one after another, just as the blueprint specifies.
 *
 * The diagram you sent shows three variables: a char 'c', an int 'i',
 * and a float 'f', all laid out sequentially in memory. We'll use a struct
 * to model this behavior perfectly.
 */
struct DataLayout {
    char c;
    int i;
    float f;
};

/*
 * Section 2: Memory Layout with a Union
 *
 * Now, a union is a different kind of blueprint. It's for a house with
 * a single, shared, multipurpose room. You can use that room as a bedroom,
 * a kitchen, or a living room, but only one at a time. All the different
 * functions (the variables) occupy the exact same space. The union's
 * total size is equal to the size of its largest member.
 *
 * The second part of your diagram shows this perfectly. All three variables
 * start at the same address. They're all trying to use the same memory.
 * This is super useful in embedded systems and low-level programming where
 * you need to save memory or reinterpret the same data in different ways.
 */
union OverlappingData {
    char c;
    int i;
    float f;
};

int main() {
    // Let's create an instance of our struct.
    // Think of this as building the house from the blueprint.
    struct DataLayout my_struct;

    // Let's create an instance of our union.
    // This is the multipurpose room.
    union OverlappingData my_union;

    printf("--- Part 1: Sequential Memory Layout (The Struct) ---\n");
    printf("Variables in a struct are like rooms in a house, laid out sequentially.\n\n");

    // We can use the addresses of the variables to show their positions.
    // The difference in addresses will show you the size of the previous variable.
    printf("Address of char c:   %p\n", &my_struct.c);
    printf("Address of int i:    %p\n", &my_struct.i);
    printf("Address of float f:  %p\n", &my_struct.f);
    printf("\n");

    printf("The size of the DataLayout struct is: %zu bytes\n", sizeof(my_struct));
    printf("Notice how the address of each member is offset by the size of the previous member.\n");
    printf("For example, the address of 'i' is the address of 'c' plus the size of 'c'.\n\n");
    
    // An optional check to show the difference between addresses.
    printf("Address diff (i - c): %ld bytes\n", (long)(&my_struct.i - &my_struct.c));
    printf("Address diff (f - i): %ld bytes\n", (long)(&my_struct.f - &my_struct.i));
    printf("Note: This simple math may not always be perfectly clean due to memory alignment.\n\n");

    printf("--- Part 2: Overlapping Memory Layout (The Union) ---\n");
    printf("Variables in a union are like a single multipurpose room, all sharing the same space.\n\n");

    // Let's print the addresses of all three members of the union.
    // You'll see that they all point to the exact same memory location.
    printf("Address of char c:   %p\n", &my_union.c);
    printf("Address of int i:    %p\n", &my_union.i);
    printf("Address of float f:  %p\n", &my_union.f);
    printf("\n");

    printf("The size of the OverlappingData union is: %zu bytes\n", sizeof(my_union));
    printf("The size of a union is always the size of its largest member.\n");
    printf("All members occupy the same memory location, allowing you to interpret the same data differently.\n");
    printf("For example, if you assign a value to 'i' and then print 'f', you'll get a garbage value because the bits are re-interpreted.\n\n");

    // A small demonstration of data corruption in a union.
    printf("--- Union Demonstration ---\n");
    my_union.i = 0x41424344; // Hexadecimal for 'DCBA' in ASCII (on a little-endian machine)
    printf("Assigned my_union.i the value 0x%X\n", my_union.i);
    printf("The value of my_union.c is now: '%c' (ascii: %d)\n", my_union.c, my_union.c);
    printf("The value of my_union.f is now: %f (garbage)\n", my_union.f);

    return 0;
}
