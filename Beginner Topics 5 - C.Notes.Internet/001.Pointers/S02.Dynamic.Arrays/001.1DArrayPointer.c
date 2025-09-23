#include <stdio.h>

int main()
{
    // This is our array. Think of it as a row of five houses.
    // Each house has a number, and they're all next to each other in memory.
    int arr[5] = {3, 5, 6, 7, 9};

    // This is a normal pointer to an integer. By setting it to `arr`, we're
    // giving it the address of the first house (the first element of the array).
    // It's like having a GPS that only knows the starting point of the street.
    int *p = arr;

    // This is a pointer to the entire array. The parentheses are crucial.
    // It's like having a blueprint or a street sign that points to the entire
    // block of five houses, not just the first one. This pointer knows the size
    // of the entire structure it's pointing to.
    int (*ptr)[5] = &arr;

    // Printing the addresses. Notice how both `p` and `ptr` hold the exact same
    // address. They both point to the beginning of the array. The difference is
    // in what they "see" at that address.
    printf("p = %p, ptr = %p\n", p, ptr);

    // Dereferencing the pointers.
    // `*p` dereferences the pointer `p`, so it gives you the value of the
    // first house: `3`.
    // `*ptr` dereferences the pointer `ptr`. Since `ptr` points to the whole
    // array, dereferencing it gives you the **address of the first element** again.
    // This can be a brain bender, but it's a key distinction.
    printf("*p = %d, *ptr = %p\n", *p, *ptr);
    
    // Now let's check their sizes. This is where the real difference shows up.
    // `sizeof(p)` will give you the size of the pointer itself (e.g., 4 or 8 bytes
    // depending on your system), no matter what it points to.
    // `sizeof(*p)` gives you the size of the thing `p` is pointing to, which is an integer (4 bytes).
    printf("sizeof(p) = %u, sizeof(*p) = %u\n", (unsigned)sizeof(p), (unsigned)sizeof(*p));

    // `sizeof(ptr)` is also the size of the pointer itself. It will be the same
    // as `sizeof(p)`.
    // `sizeof(*ptr)` is different. It gives you the size of the **entire array**
    // because `ptr` points to the whole thing. `5` integers * `4` bytes each = `20` bytes.
    printf("sizeof(ptr) = %u, sizeof(*ptr) = %u\n", (unsigned)sizeof(ptr), (unsigned)sizeof(*ptr));

    return 0;
}
