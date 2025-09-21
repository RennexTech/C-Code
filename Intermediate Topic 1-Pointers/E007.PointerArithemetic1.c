#include <stdio.h>
#include <stdlib.h>

int main()
{
    int a = 5, *p = &a;
    float b = 2.2, *pf = &b;
    char c = 'x', *pc = &c;

    /*

    You are using the %d format specifier to print the pointer values, incorrect.
    Pointers should be printed with the %p format specifier. Here's the corrected code:
    (my code is correct, because I wanted a decimal format of the address, not a hex)

    printf("The old address of the pointer was: %p\n", (void*)p);
    p++;
    printf("The new address that int pointer points to is: %p\n", (void*)p);

    */

    printf("The old address of the pointer was: %d\n", p);
    p++;
    printf("The new address that int pointer points to is: %d\n", p);


    /*

    The problem is that you are incrementing the pointer p before  dereferencing it. When you increment p, it points to a location in memory that is not valid or not pointing to an integer.

    Consequently, when you dereference it using *p, you get undefined behavior, which in this case happens to result in the value 0.

    To fix this issue and correctly dereference p, you should perform the dereference before incrementing the pointer.

    The problem is that you are incrementing the pointer p before  dereferencing it. When you increment p, it points to a location in memory that is not valid or not pointing to an integer. then what's the need for pointer arithmetic, if i will be pointing to nothing everytime?

    Pointer arithmetic is used to manipulate and navigate through arrays or memory regions effectively. When you increment or decrement a pointer, you are essentially moving it to the next or previous element in an array (or memory block) of the same data type. This is a fundamental concept in C and C++.

    In your original code, you were correctly using pointer arithmetic, but the issue was in the order of operations. You should dereference the pointer before incrementing it to access the value it points to. Pointer arithmetic allows you to perform operations relative to the size of the data type it points to, which is useful when working with arrays or memory buffers.

    */

    //Dereference the pointer
    int value = *p;
    printf("The value of a is: %d\n", value); // gets a zero, coz we first incremented p
    using_pointers();

    return 0;
}

/*

After running this code:

The old address of the pointer was: 6422016
The new address that int pointer points to is: 6422020 ( +4 bytes - integer)
The value of a is: 0

Suppose the address of variables a, b, and c are 1000, 4000, and 5000, respectively.

Increment the integer pointer p by 1.
p++;
p now points to the address 1002, which is the next integer location after the variable a.

Subtract 3 from the integer pointer p.
p -= 3;
 p now points to the address 996, which is the third integer location before the variable a.

Add 5 to the integer pointer p.
p += 5;
p now points to the address 1006, which is the fifth integer location after the variable a.

Decrement the floating-point pointer pf by 1.
pf--;
pf now points to the address 3996, which is the previous floating-point location before the variable b.

Subtract 3 from the floating-point pointer pf.
pf -= 3;
pf now points to the address 3992, which is the third floating-point location before the variable b.

Add 5 to the floating-point pointer pf.
pf += 5;
pf now points to the address 4012, which is the fifth floating-point location after the variable b.

Increment the character pointer pc by 1.
pc++;
pc now points to the address 5001, which is the next character location after the variable c.

Subtract 3 from the character pointer pc.
pc -= 3;
pc now points to the address 4998, which is the third character location before the variable c.

Add 5 to the character pointer pc.
pc += 5;
pc now points to the address 5003, which is the fifth character location after the variable c.

Decrement the character pointer pc by 1.
pc--;
pc now points to the address 5002, which is the previous character location before the variable c.

The compiler scales all this arithmetic automatically since it knows the base type of pointer.

It is important to note that pointer arithmetic can only be performed on pointers of the same type. For example, you cannot add an integer pointer to a floating-point pointer. Additionally, it is important to make sure that pointer arithmetic does not cause the pointer to point outside of the valid memory space.

Pointer arithmetic does not change the data inside the pointer, it only changes the memory address that the pointer is pointing to. This is because a pointer is just a variable that stores the memory address of another variable.

*/

/*

void using_pointers()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = array;

    for(i = 0; i < array[i]; i++)
    {
        printf("The elements are: %d\n", *p);
        p++;
    }
}

In the code above, the for loop condition i < array[i] is not suitable for iterating through the elements of the array correctly. This condition is essentially comparing the current value of i to array[i], which may not work as expected. Instead, you should use the size of the array to control the loop.



*/

void using_pointers()
{
    int array[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int *p = array;

    for(i = 0; i < 10; i++)
    {
        printf("The element %d: %d\n",i , *p);
        p++;
    }
}
