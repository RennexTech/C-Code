#include <stdio.h>

// This is our function prototype. Think of it as a "declaration of intent."
// It tells the C compiler, "Hey, I've got a function called `ref` that takes two
// integer pointers as arguments. Don't be surprised when you see it later."
void ref(int *p, int *q);

// --- The Main Function: The Grand Central Station of Your Code ---
int main()
{
    // These are our actual variables, living right here in this function.
    // They have their own home in memory. For now, think of 'a' and 'b' as
    // your personal bank accounts, each with its own balance.
    int a = 5, b = 8;
    
    // We're just checking the initial balances. This is like a quick
    // peek at your account before you do a transaction.
    printf("Initial values:\n");
    printf("a = %d, b = %d\n", a, b);

    // This is the key moment. Instead of giving the `ref` function a copy of
    // our bank account balances, we're giving it the actual physical address of
    // where they're stored. The `&` operator gets us that address.
    // This is like giving a friend a treasure map to your hidden stash.
    // They don't get the treasure itself, but they have the location.
    ref(&a, &b); // These are our actual parameters.

    // Now we check our balances again. Since we gave the `ref` function
    // the treasure map, any changes it made were to the actual stash,
    // not a copy. So, our original balances here in `main` have been
    // permanently changed.
    printf("\nAfter `ref` function call:\n");
    printf("a = %d, b = %d\n", a, b);
    
    // The main function needs to return a value to the operating system,
    // and `0` is the standard way of saying, "Everything went fine."
    return 0;
}

// --- The `ref` Function: The Treasure Hunter ---
// This is the formal parameter list. 'p' and 'q' aren't integers; they're
// pointers to integers. They are the treasure maps we got from `main`.
void ref(int *p, int *q)
{
    // The `*` operator here is for dereferencing. It's like a command that
    // says, "Don't look at the address itself. Go to that address and grab
    // whatever value is stored there."
    // `(*p)++` goes to the address stored in `p`, grabs the integer there,
    // and increments its value by one. The parentheses are crucial because
    // `*p++` would be an entirely different (and buggy) operation.
    (*p)++;
    (*q)++;

    // We can also check the values inside the function using the same
    // dereferencing operator.
    printf("\nInside `ref` function:\n");
    printf("a's value at its address = %d, b's value at its address = %d\n", *p, *q);
}
