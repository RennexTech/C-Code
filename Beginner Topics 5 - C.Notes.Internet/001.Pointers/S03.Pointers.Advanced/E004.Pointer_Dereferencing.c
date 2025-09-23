#include<stdio.h>
int main()
{
    // These are our variables. Think of them as containers holding specific values.
    int a = 87;
    float b = 4.5;

    // These are our pointer variables. They don't hold numbers or text;
    // they hold memory addresses. We're pointing `p1` to the location of `a`
    // and `p2` to the location of `b`. The `*` indicates they are pointers.
    int *p1=&a;
    float *p2=&b;

    // This line prints the VALUE stored inside the pointer `p1`.
    // Since `p1` holds the address of `a`, this will show you `a`'s memory address.
    printf("Value of p1 = Address of a = %p\n",p1);

    // This line prints the VALUE stored inside the pointer `p2`.
    // Since `p2` holds the address of `b`, this will show you `b`'s memory address.
    // Note: The comment in the original code for this line was incorrect. It should be "Address of b".
    printf("Value of p2 = Address of b = %p\n",p2);

    // This line prints the memory address of the pointer `p1` itself.
    // Pointers are variables too, so they also have their own location in memory.
    printf("Address of p1 = %p\n",&p1);

    // This line prints the memory address of the pointer `p2` itself.
    printf("Address of p2 = %p\n",&p2);

    // These three expressions all give you the same result: the value of `a`.
    // 1. `a`: The variable's name directly.
    // 2. `*p1`: The value at the address `p1` is pointing to. This is called dereferencing the pointer.
    // 3. `*(&a)`: The value at the address of `a`. This is a bit redundant but shows the relationship.
    printf("Value of a = %d %d %d\n",a,*p1,*(&a));

    // Similarly, these three expressions all give you the same result: the value of `b`.
    // The `*` operator retrieves the value from the memory location a pointer holds.
    printf("Value of b = %.1f %.1f %.1f\n",b,*p2,*(&b));

    return 0;
}