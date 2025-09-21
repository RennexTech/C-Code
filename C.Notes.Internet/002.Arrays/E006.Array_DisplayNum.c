#include <stdio.h>

int main()
{
    // Declares an integer array named `arr` with 5 slots.
    // Think of this as creating an empty bookshelf with 5 spots, ready to hold books (integers).
    int arr[5];

    // This `for` loop is our input section. It runs 5 times, once for each slot on our bookshelf.
    for (int i = 0; i < 5; i++)
    {
        // This line asks the user to enter a value, specifying which slot number (`i`) it's for.
        printf("Enter a value for arr[%d]: ", i);
        
        // `scanf` reads the number the user types. The `&arr[i]` is crucial; it gets the **memory address**
        // of the current slot, telling `scanf` exactly where to place the number.
        scanf("%d", &arr[i]);
    }

    // This second `for` loop is our output section. It also runs 5 times to display the contents
    // of each slot on our bookshelf.
    for (int i = 0; i < 5; i++)
        // `printf` displays the value stored in the current slot, `arr[i]`.
        // `\t` adds a tab for neat spacing between the numbers.
        printf("%d\t", arr[i]);
        
    return 0;
}