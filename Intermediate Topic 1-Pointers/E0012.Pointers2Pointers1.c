#include <stdio.h>
#include <stdlib.h>

/*

Pointer to Pointer (Double Pointer):

In the world of programming, we are familiar with the concept of a pointer, which is a variable capable of storing a memory address.

This pointer variable itself occupies some memory space, and consequently, it has its own address.

Now, consider this: just as we can store the address of a regular variable in another variable (a pointer), we can also store the address of a pointer variable in yet another variable.

This new variable is called a pointer to pointer, often denoted as a double pointer.

You might be wondering how deep this can go.

Well, in theory, we can keep creating pointers to pointers to pointers to... well, you get the idea.

However, in practice, we typically stop at pointer to pointer because that covers most use cases.

Pointer to pointer becomes particularly handy when we're dealing with functions.

Here's how you declare a pointer to pointer:

*/

data_type **pptr;

/*

In this declaration, pptr is a pointer to pointer. It has the capability to point to a pointer that, in turn, points to a variable of type data_type.

The double asterisk in the declaration is a way to tell the compiler that we're dealing with a pointer to a pointer.

Now, let's illustrate this with an example:

*/

int a = 5;
int *pa = &a;
int **ppa = &p;


/*

In this example, we have an integer variable a with the value 5. Then, we have a pointer pa that points to the address of a.

Finally, we introduce a pointer to pointer ppa that points to the address of pa.

So, ppa effectively points to a pointer that points to an integer variable, creating this hierarchical structure.

This concept might seem a bit abstract at first, but it becomes invaluable when working with more complex data structures and function arguments.

It allows us to pass pointers to functions, making it possible to modify variables in the calling function, among other powerful applications.

Indeed, you're absolutely right. To access the value indirectly pointed to by a pointer to pointer, we use the double indirection operator **. Let's illustrate this with a table for clarity:

The table is found in an image on github:(black chatgpt table)

*/

int value = **ppa;

/*

int value = **ppa;

Can we say int value = ppa, coz the compiler already knows its a double pointer?

*/

/*

No, you cannot directly assign int value = ppa because ppa is a double pointer (pointer to pointer), and you need to use the double indirection operator ** to access the value it points to.

Here's why:

ppa is a pointer to a pointer (int **ppa). It holds the address of another pointer, not the actual integer value you want.

To get the value pointed to by ppa, which is the value of a, you must use **ppa.

The first * dereferences ppa to get the address of pa, and the second * dereferences pa to get the value pointed to by it, which is a.

So, you should use int value = **ppa; to correctly access the value of a through the double pointer ppa.

Simply assigning int value = ppa; would result in a type mismatch error, as you're trying to assign a pointer to an integer variable, which is not valid in C programming.

*/

/*

If you want to print the value of the pointer ppa, which is the address of pa, you can simply use a single asterisk * to dereference it. Here's how you can print the value of ppa:

*/

printf("Value of ppa: %p\n", *ppa);


/*

In this case, *ppa gives you the value pointed to by ppa, which is the address of pa. Using the %p format specifier in printf allows you to print the address in a human-readable format.

So, you don't need to use **ppa to print the address stored in ppa. A single asterisk * is sufficient for this purpose.

*/


/*

So if i want to print *p using printf, i will not use * but printing **ppa I wil use a single *

That's correct! If you want to print the value of *p (which is the value of the variable a in your example), you should use **ppa inside printf and use a single * like this:

*/

printf("Value of *p: %d\n", **ppa);

/*

Here's what's happening:

*ppa gives you the value of pa, which is the pointer to a.
**ppa then dereferences pa to get the actual value of a.
So, using **ppa with a single * in printf correctly prints the value of a.

*/


/*

printf("Value of *p: %d\n", **ppa); what the heck you lost me there, can you explain all the posibliites of printf'ing ppa, pa, and *pa and **ppa, show me all the possibilities of printf these:

Certainly, let's clarify how to print various values using printf for ppa, pa, *pa, and **ppa:

Assuming you have the following declarations:

*/

int a = 5;
int *pa = &a;
int **ppa = &pa;

//Printing the address stored in ppa (address of pa):

printf("Address of ppa: %p\n", ppa);

//Printing the value stored in ppa (address of pa) using a single asterisk *:

printf("Value of ppa (address of pa): %p\n", *ppa);

//Printing the value stored in pa (address of a) using *pa:

printf("Value of pa (address of a): %p\n", pa);

//Printing the value pointed to by pa (the value of a) using *pa:

printf("Value pointed to by pa (value of a): %d\n", *pa);

//Printing the value pointed to by pa (the value of a) using **ppa (double dereference of ppa):

printf("Value pointed to by pa (value of a): %d\n", **ppa);

//Each printf statement is designed to print a different aspect of the pointers and values involved in your example. The %p format specifier is used to print addresses, and %d is used to print integer values.

int main() {
    int a = 5;
    int *pa;
    int **ppa;

    pa = &a;     // Assign the address of 'a' to 'pa'
    ppa = &pa;   // Assign the address of 'pa' to 'ppa'

    printf("Address of a = %p\n", &a);
    printf("Value of pa = Address of a = %p\n", pa);
    printf("Value of *pa = Value of a = %d\n", *pa);
    printf("Address of pa = %p\n", &pa);
    printf("Value of ppa = Address of pa = %p\n", ppa);
    printf("Value of *ppa = Value of pa = %p\n", *ppa);
    printf("Value of **ppa = Value of a = %d\n", **ppa);
    printf("Address of ppa = %p\n", &ppa);

    return 0;
}


//Rectified to show decimal addresses which are positive integers that are easier to read.
//That's why I used unsigned integer/ positive numbers
//Memory addresses can only be positive

int main() {
    int a = 5;
    int *pa;
    int **ppa;
    pa = &a;     // Assign the address of 'a' to 'pa'
    ppa = &pa;   // Assign the address of 'pa' to 'ppa'
    printf("Address of a = %p (Decimal: %u)\n", &a, (unsigned int)&a);
    printf("Value of pa = Address of a = %p (Decimal: %u)\n", pa, (unsigned int)pa);
    printf("Value of *pa = Value of a = %d\n", *pa);
    printf("Address of pa = %p (Decimal: %u)\n", &pa, (unsigned int)&pa);
    printf("Value of ppa = Address of pa = %p (Decimal: %u)\n", ppa, (unsigned int)ppa);
    printf("Value of *ppa = Value of pa = %p (Decimal: %u)\n", *ppa, (unsigned int)*ppa);
    printf("Value of **ppa = Value of a = %d\n", **ppa);
    printf("Address of ppa = %p (Decimal: %u)\n", &ppa, (unsigned int)&ppa);

    return 0;
}

/*

The result is:

Address of a = 000000000061FE1C (Decimal: 6422044)
Value of pa = Address of a = 000000000061FE1C (Decimal: 6422044)
Value of *pa = Value of a = 5
Address of pa = 000000000061FE10 (Decimal: 6422032)
Value of ppa = Address of pa = 000000000061FE10 (Decimal: 6422032)
Value of *ppa = Value of pa = 000000000061FE1C (Decimal: 6422044)
Value of **ppa = Value of a = 5
Address of ppa = 000000000061FE08 (Decimal: 6422024)

*/



