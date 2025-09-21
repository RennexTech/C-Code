#include <stdio.h>
#include <stdlib.h>

int main()
{
    printf("Hello world!\n");
    return 0;
}

/*

In C, pointers allow us to work with memory addresses and perform arithmetic operations on them. However, not all arithmetic operations are valid with pointers. Here are the essential operations that can be performed with pointers:

Addition of an Integer to a Pointer and Increment Operation:

When you add an integer value to a pointer, the resulting address depends on the size of the base data type of the pointer. For example, if you have an integer pointer pi containing address 1000 and increment it, you will get 1004 because the size of an int data type is typically 4 bytes (not 2 as previously mentioned).

Subtraction of an Integer from a Pointer and Decrement Operation:

Subtracting an integer from a pointer works similarly to addition but in the opposite direction. If you decrement the pi pointer by 1, you will get 1000 instead of 999.

Subtraction of a Pointer from Another Pointer of the Same Type:

You can subtract one pointer from another if they are of the same data type. The result represents the number of elements (not bytes) between the two addresses. For example, if you subtract one int pointer from another, the result represents the number of int elements between them.

Here's a practical example using different pointer types:

*/

int a = 5, *pi = &a;
float b = 2.2, *pf = &b;
char c = 'x', *pc = &c;


/*

Incrementing pi by 1 will result in pi pointing to the next integer in memory.

Incrementing pf by 1 will move it to the next float.

Incrementing pc by 1 will advance it to the next character.

Pointer arithmetic is a powerful feature in C, but it's important to use it carefully, ensuring that you stay within the bounds of allocated memory to avoid undefined behavior. The size of data types may vary depending on the platform and compiler, so it's a good practice to use the sizeof operator to determine the size of a data type on your specific system rather than assuming a fixed size.

*/

void incrementing_pointers()
{
    //Let's play around with some pointer arithmetic as explained above
    //Hacker simulator game download
}



















