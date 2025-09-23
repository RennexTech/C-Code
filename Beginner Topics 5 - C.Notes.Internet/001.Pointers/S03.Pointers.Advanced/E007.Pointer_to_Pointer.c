#include <stdio.h>
int main()
{
    // a is a regular variable. Think of it as a small locker with the number '5' inside.
    int a = 5;

    // pa is a pointer to an integer. It stores the address of an integer variable.
    // We're giving `pa` the address of our locker `a`. It's like a key with the
    // address to locker `a` written on it.
    int *pa = &a;

    // ppa is a pointer to a pointer. It stores the address of another pointer variable.
    // This is like having a second key, and on it, you've written the address of your first key (`pa`).
    int **ppa = &pa;

    // Let's print the memory addresses and values to see how they're all connected.

    // This shows the physical location of our original locker `a`.
    printf("Address of a = %p\n", &a);

    // This shows the address stored on our first key, `pa`. It's the same as the address of `a`.
    printf("Value of pa = Address of a = %p\n", pa);

    // This is `*pa`. The `*` operator means "go to the address this key points to and get the value."
    // It's like using your key to open the locker and see the number 5 inside.
    printf("Value of *pa = Value of a = %d\n", *pa);

    // This is the address of our first key itself. Remember, a key is also a physical object
    // that needs its own place.
    printf("Address of pa = %p\n", &pa);

    // This shows the address stored on our second key, `ppa`. It's the same as the address of the first key, `pa`.
    printf("Value of ppa = Address of pa = %p\n", ppa);

    // This is `*ppa`. It means "go to the address this key points to."
    // Since `ppa` points to `pa`, this will give you the value of `pa`, which is the address of `a`.
    printf("Value of *ppa = Value of pa = %p\n", *ppa);

    // This is `**ppa`. This means "go to the address `ppa` points to, and then
    // from there, go to the address that key points to and get the value."
    // It's like using your second key to find the first key, and then using the first key to
    // open the locker and get the value 5. 
    printf("Value of *ppa = Value of a = %d\n", **ppa);

    // This is the address of our second key itself.
    printf("Address of ppa=%p\n", &ppa);

    return 0;
}