#include <stdio.h>

// Defines the maximum size of the array.
#define SIZE 10

int main()
{
    int arr[SIZE], item, i, current_size;

    // We'll read `SIZE-1` elements so there's one empty spot for insertion.
    printf("Enter %d elements of the array (in sorted order):\n", SIZE - 1);
    for (i = 0; i < SIZE - 1; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    // The current number of elements in the array is `SIZE-1`.
    current_size = SIZE - 1;
    
    // We ask the user for the item they want to insert.
    printf("Enter the item to be inserted: ");
    scanf("%d", &item);
    
    // This loop finds the correct position for the new item.
    // It starts from the last element and shifts larger elements to the right.
    // The loop continues as long as `i` is within the array bounds and the `item` is smaller than the current element `arr[i]`.
    for (i = current_size - 1; i >= 0 && item < arr[i]; i--)
    {
        arr[i + 1] = arr[i]; // Shift the element to the right.
    }
    
    // Once the loop ends, `i+1` is the correct index to insert the item.
    arr[i + 1] = item;
    
    // Now we print the final array with the new element inserted.
    printf("\nArray after insertion:\n");
    for (i = 0; i < SIZE; i++)
    {
        printf("%d\n", arr[i]);
    }
    
    return 0;
}