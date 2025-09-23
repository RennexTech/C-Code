#include <stdio.h>

int main()
{
    // `typedef` is like creating a nickname for an existing data type.
    // The syntax is: `typedef <previous_name> <alias_name>`.
    
    // Now we can use `ul` instead of `unsigned long`.
    typedef unsigned long ul;
    
    // Now we can use `integer` instead of `int`.
    typedef int integer;
    
    // We declare three variables of type `ul` (which is `unsigned long`).
    ul l1, l2, l3;
    
    // We declare a variable of type `integer` (which is `int`).
    integer a = 12;

    // We print the value of `a`.
    printf("Value of a is: %d\n", a);
    
    return 0;
}