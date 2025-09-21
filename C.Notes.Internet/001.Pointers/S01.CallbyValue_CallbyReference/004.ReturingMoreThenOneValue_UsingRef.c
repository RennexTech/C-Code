#include<stdio.h>

// This is our function's blueprint. It tells the compiler,
// "This function takes two numbers, but it also needs three special
// delivery addresses to drop off the sum, difference, and product."
// The asterisks (*) are the signal for these delivery addresses.
void func(int x, int y, int *sum, int **diff, int *Product);

int main()
{
    // These are our three empty containers, ready to receive the results.
    // They're sitting here in main's memory, waiting to be filled.
    int a = 6, b = 4;
    int sum, diff, product;
    
    // Now we call the function. We're not sending a and b's actual containers
    // (their values), but rather a copy of them. For our empty containers
    // `sum`, `diff`, and `product`, we send their physical memory addresses
    // using the `&` operator. It's like we're giving the function a set of keys
    // to three empty lockers, telling it exactly where to put the results.
    func(a, b, &sum, &diff, &product);
    
    // Now that the function is done, we check our lockers. They're no longer empty.
    // The `func` function put the results there directly, so we can access them
    // without the function needing to return anything.
    printf("Sum=%d\nDiff=%d\nProduct=%d\n", sum, diff, product);
    
    return 0;
}

// Our function receives the two numbers `x` and `y` as copies.
// But `sum`, `diff`, and `Product` are received as pointers (memory addresses).
// They are the special keys to the lockers.
void func(int x, int y, int *sum, int *diff, int *Product)
{
    // The asterisk (*) is the "dereference" operator. It says, "Go to the
    // address you were given and put this value there."
    // We're performing the calculations and then using the keys to directly
    // place the results into the right memory locations.
    *sum = x + y;
    *diff = x - y;
    *Product = x * y;
}
