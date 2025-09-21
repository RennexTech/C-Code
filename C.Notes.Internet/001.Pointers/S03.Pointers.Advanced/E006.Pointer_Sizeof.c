#include<stdio.h>
int main()
{
    // Here we declare a few variables of different types and their corresponding pointers.
    // The pointer `p1` is for a `char`, `p2` for an `int`, `p3` for a `float`, and `p4` for a `double`.
    // The `&` operator gets the memory address of each variable, and we store that address in the pointer.
    char a = 'x', *p1 = &a;
    int b = 12, *p2 = &b;
    float c = 12.4, *p3 = &c;
    double d = 18.34, *p4 = &d;
    
    // We use the `sizeof()` operator to find the size in bytes of different things.
    
    // For `p1` (a pointer to a `char`):
    // `sizeof(p1)` gives the size of the pointer itself. All pointers on the same system (e.g., a 64-bit system)
    // will have the same size, because they all just store a memory address. This is typically 8 bytes on a 64-bit system.
    // `sizeof(*p1)` gives the size of the thing `p1` is pointing to, which is a `char`. A `char` is always 1 byte.
    printf("Sizeof(p1)=%u, Sizeof(*p1)=%u\n", sizeof(p1), sizeof(*p1));
    
    // For `p2` (a pointer to an `int`):
    // `sizeof(p2)` is the size of the pointer (same as `p1`).
    // `sizeof(*p2)` is the size of an `int`, which is typically 4 bytes.
    printf("Sizeof(p2)=%u, Sizeof(*p2)=%u\n", sizeof(p2), sizeof(*p2));
    
    // For `p3` (a pointer to a `float`):
    // `sizeof(p3)` is the size of the pointer (same as `p1` and `p2`).
    // `sizeof(*p3)` is the size of a `float`, which is typically 4 bytes.
    printf("Sizeof(p3)=%u, Sizeof(*p3)=%u\n", sizeof(p3), sizeof(*p3));
    
    // For `p4` (a pointer to a `double`):
    // `sizeof(p4)` is the size of the pointer (same as the others).
    // `sizeof(*p4)` is the size of a `double`, which is typically 8 bytes.
    printf("Sizeof(p4)=%u, Sizeof(*p4)=%u\n", sizeof(p4), sizeof(*p4));
    
    return 0;
}



// -----------------------------------------------------------------------

#include<stdio.h>

int main()
{
    // These are our variables. Think of them as two separate storage lockers.
    int a = 87;
    float b = 4.5;
    
    // These are our "keys" to those lockers. They don't hold the items themselves,
    // just the address where the items are located. The asterisk `*` tells the compiler
    // that this variable is a pointer.
    int *p1 = &a;
    float *p2 = &b;
    
    // We're printing the contents of our "keys," which are the memory addresses.
    // Notice they are different, because they point to different storage lockers.
    printf("Value of p1 = Address of a = %p\n", p1);
    // Corrected: You had a typo here, trying to print the address of 'a' for p2.
    // This is a subtle but critical bug that would point to the wrong data.
    printf("Value of p2 = Address of b = %p\n", p2); 
    
    // Now we're printing the addresses of the keys themselves.
    // Pointers are just variables, so they have their own addresses in memory.
    printf("Address of p1 = %p\n", &p1);
    printf("Address of p2 = %p\n", &p2);
    
    // This is the money shot. We are "dereferencing" the pointers using the `*` operator.
    // It's like using our key to open the locker and get the item inside.
    printf("Value of a = %d, Value from p1 = %d, Value from address of a = %d\n", a, *p1, *(&a));
    printf("Value of b = %.1f, Value from p2 = %.1f, Value from address of b = %.1f\n", b, *p2, *(&b));

    return 0;
}
