#include <stdio.h>

// This function takes a pointer to an integer.
// When you pass an array to a function like this, C doesn't make a copy of the whole
// array. Instead, it just passes the memory address of the very first element.
// Think of it like giving someone the GPS coordinates to your treasure chest—they don't
// have the chest itself, but they know exactly where to go to find it and access the contents.
int func2(int *ptr)
{
    // We're iterating through the array using the pointer we were given.
    // The syntax `ptr[i]` is just a friendly shorthand. Under the hood, the compiler
    // translates it into `*(ptr + i)`. Both lines of code do the exact same thing:
    // they tell the program to go to the starting address (`ptr`), move forward by `i`
    // elements, and then grab the value that's stored at that final location.
    // This is the core of pointer arithmetic.
    for (int i = 0; i < 4; i++)
    {
        printf("The value at index %d is %d\t", i, ptr[i]);
        printf("The value at index %d is %d\n", i, *(ptr + i));
    }
    
    // This is the key moment. We're using our pointer to go directly to the first
    // element of the original array and change its value. Since we have the original
    // address, this change is permanent.
    *ptr = *ptr + 3;
    
    return 0;
}

// The `main` function is where our program starts and where our original array lives.
int main()
{
    // This is our original array. Think of this as the treasure chest you own,
    // with four valuable items inside.
    int arr[] = {23, 13, 3, 4};
    
    printf("The original value of index 0 is %d\n", arr[0]);
    
    // We are calling the `func2` function and passing it our array.
    // We are giving it the "GPS coordinates" to our treasure chest.
    func2(arr);
    
    // When we check our treasure chest again, we see the item at index 0 has been
    // permanently changed by `func2`.
    printf("The new value of index 0 is %d\n", arr[0]);
    
    return 0;
}
