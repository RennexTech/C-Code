#include <stdio.h>

// This function takes an array as its argument.
// Under the hood, C doesn't make a copy of the entire array.
// Instead, it passes a pointer to the first element of the original array.
// This is like giving someone the key to your garage—they have access to
// everything inside, and any changes they make are to the actual contents,
// not a copy.
int func1(int array[])
{
    // We're iterating through the array using the pointer we were given.
    // Each time, we "dereference" the pointer to get the value inside.
    for (int i = 0; i < 4; i++)
    {
        printf("The value at %d is %d\n", i, array[i]);
    }
    
    // This is the key moment. We're using our key to the garage to change the
    // first item. This change is permanent because we are modifying the
    // original data in memory, not a temporary copy.
    array[0] = 383;
    
    return 0;
}

// The `main` function is where our program starts and where our original array lives.
int main()
{
    // This is our original array. Think of this as the garage you own,
    // with four items inside.
    int arr[] = {23, 13, 3, 4};
    
    printf("The original value of index 0 is %d\n", arr[0]);
    
    // We are calling the `func1` function and passing it our array.
    // We are giving it the "key" to our garage, so it can go inside and work on the original items.
    func1(arr);
    
    // When we check our garage again, we see the item at index 0 has been
    // permanently changed by `func1`.
    printf("The new value of index 0 is %d\n", arr[0]);
    
    return 0;
}
