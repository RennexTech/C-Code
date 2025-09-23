#include <stdio.h>
int main()
{
    int temp, arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    for (int i = 0, j = 9; i < j; i++, j--)
    {
        temp = arr[i];
        arr[i] = arr[i]; // here's the flaw, not deleting this, so you can see the changes
        arr[j] = temp;
    }
    printf("After reversing, the array is : ");
    for (int i = 0; i < 10; i++)
        printf("%d", arr[i]);
    printf("\n");
    return 0;
}
//output = 1234554321

// This has some flaw 

// ===================================================

#include <stdio.h>

int main()
{
    // This is our integer array with 10 elements, sorted from 1 to 10.
    // Think of this as a line of 10 people, standing in order from 1 to 10.
    int temp, arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // This `for` loop is the heart of the reversal. We're using two counters:
    // `i` starts at the beginning (index 0) and moves forward.
    // `j` starts at the end (index 9) and moves backward.
    // The loop continues as long as `i` is less than `j`. When they meet in the middle, we stop.
    // This ensures we only swap each pair of elements once.
    for (int i = 0, j = 9; i < j; i++, j--)
    {
        // We need a temporary variable, `temp`, to hold one of the values during the swap.
        // It's like having a third, empty hand. 
        
        // Step 1: Store the value from the beginning (`arr[i]`) in our temporary hand.
        temp = arr[i];

        // Step 2: Move the value from the end (`arr[j]`) to the beginning's spot.
        // The original value at `arr[i]` is now safe in `temp`.
        arr[i] = arr[j];

        // Step 3: Put the original value from the beginning (now in `temp`) into the end's spot.
        arr[j] = temp;
    }

    // Now we print the reversed array to see the result.
    printf("After reversing, the array is: ");
    for (int i = 0; i < 10; i++)
        printf("%d", arr[i]);
    printf("\n");

    return 0;
}