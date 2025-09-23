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
    printf("Value of p2 = Address of b = %p\n", p2); // Corrected: was pointing to 'a'
    
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
