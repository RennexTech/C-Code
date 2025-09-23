#include<stdio.h>

// Here's our function prototype. Notice the asterisk `*`?
// That's our key. It says this function isn't getting a value,
// it's getting a memory address. It's like saying, "I'm not giving
// you a copy of the letter; I'm giving you the address of the mailbox
// where the original letter is stored."
void changeValue(int *address);

int main()
{
    int a = 34, b = 56;

    // This is the value of 'a' before we mess with it.
    printf("The value of a now is %d\n", a);

    // This is where we hand over the keys. The `&` operator
    // means "get the address of." We're not sending the value 34;
    // we're sending the memory address where the variable 'a' lives.
    // This is how we achieve "pass by reference."
    changeValue(&a);

    // Now, we're checking the value of 'a' again.
    // Since we gave the function the address, it went directly to 'a's
    // memory location and changed the value. It's no longer 34.
    printf("The value of a now is %d\n", a);

    return 0;
}

// Our function now has a pointer variable called 'address'.
// A pointer is just a variable that holds a memory address.
// It's not a value; it's a map to a location in your computer's RAM.
void changeValue(int *address)
{
    // The `*` here is called the dereference operator. It's like
    // following the map to the location and saying, "Whatever is at
    // this address, change its value to 345." This action directly
    // modifies the variable 'a' from `main`, because 'address'
    // is pointing right at it.
    *address = 345;
}
