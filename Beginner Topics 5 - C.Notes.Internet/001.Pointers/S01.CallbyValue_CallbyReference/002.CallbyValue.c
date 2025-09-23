#include<stdio.h>

// This is our function prototype. Think of it as a blueprint or a memo
// telling the compiler, "Hey, there's a function called 'value' coming up
// that needs two integer inputs, and it won't give anything back (void)."
void value(int a, int b);

int main()
{
    // Meet our two buddies, 'a' and 'b'. In main's little world, they're the
    // original, official documents. Their values are 5 and 8.
    int a = 5, b = 8;

    // We're just checking in on the originals. As expected, they're 5 and 8.
    printf("a=%d, b=%d\n", a, b);

    // This is the key moment. We're calling the 'value' function.
    // But instead of handing over the original documents (a and b),
    // we make photocopies of them. These photocopies are the "actual parameters."
    // We send a copy of 'a' (with the value 5) and a copy of 'b' (with the value 8).
    value(a, b);

    // The function is done, and we're back in main's world.
    // We're checking on the original documents again.
    // Did they change? Nope. They're still 5 and 8 because we only gave the
    // function photocopies to mess with, not the originals. This is the whole point
    // of "pass by value." The function's actions don't affect the variables
    // in the calling function (main).
    printf("a=%d, b=%d\n", a, b);
    return 0;
}

// This is where our 'value' function lives. Think of this as a different office.
// The variables 'x' and 'y' are like temporary employees here.
// They receive the photocopies of 'a' and 'b' from the main office.
// 'x' gets a copy of 5, and 'y' gets a copy of 8.
void value(int x, int y)
{
    // Our temp employees 'x' and 'y' get new instructions: "increment your number."
    // They do what they're told. x becomes 6, and y becomes 9.
    x++;
    y++;

    // They proudly show off their new numbers. The output is 6 and 9.
    // But remember, this is only happening with the photocopies, inside this function.
    printf("a=%d, b=%d\n", x, y);
}
