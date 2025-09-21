#include <stdio.h>

int main()
{
    // This is a fixed-size array. Think of it like a lunchbox with exactly 10 compartments.
    // The size is locked in at compile time, and you can't change it.
    // This memory is allocated on the program's "stack."
    int arr[10], sum = 0;
    
    // We're iterating through each compartment of our lunchbox.
    for (int i = 0; i < 10; i++)
    {
        // We're putting one item into each compartment. This is safe because we
        // know we have exactly 10 slots.
        printf("Enter a value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
        
        // We're adding up the values as we go.
        sum = sum + arr[i];
    }
    
    // Finally, we print out the total number of items.
    printf("The total sum of the values in the array is: %d\n", sum);
    
    return 0;
}
