#include<stdio.h>
int main()
{
    // Our regular variable, `a`, which holds the integer value 5.
    int a = 5;
    
    // Our pointer variable, `p`. This variable is designed to store a memory address.
    int *p;
    
    // We're now making `p` point to `a`. The `&` operator gives us the memory address of `a`.
    p = &a;
    
    // Let's see what address `p` is currently holding. It should be the address of `a`.
    printf("Value of p = Address of a = %p\n", p);
    
    // ---
    // Now for the interesting part: Pointer arithmetic!
    // When you add or subtract from a pointer, it doesn't just change the address by one byte.
    // Instead, it moves the pointer to the next or previous "block" of memory
    // that can hold the data type it's pointing to (in this case, an `int`).
    // On most systems, an `int` takes up 4 bytes. So, adding 1 to the pointer
    // will actually increase its address by 4.
    
    // This is the **prefix increment** operator (`++p`).
    // It first adds 1 to the pointer's value (the address) and *then* uses that new value.
    printf("Value of p = %p\n", ++p);
    
    // This is the **postfix increment** operator (`p++`).
    // It first uses the current value of the pointer and *then* adds 1 to it.
    // So, this line will print the address `p` had just before this line executed.
    printf("Value of p = %p\n", p++);
    
    // Now let's print `p` again to see its new value after the last operation completed.
    printf("Value of p = %p\n", p);
    
    // This is the **prefix decrement** operator (`--p`).
    // It first subtracts 1 from the pointer's value and *then* uses that new value.
    printf("Value of p = %p\n", --p);
    
    // This is the **postfix decrement** operator (`p--`).
    // It first uses the current value of the pointer and *then* subtracts 1 from it.
    printf("Value of p = %p\n", p--);
    
    // Let's print `p` one last time to see its final value.
    printf("Value of p = %p\n", p);
    
    return 0;
}