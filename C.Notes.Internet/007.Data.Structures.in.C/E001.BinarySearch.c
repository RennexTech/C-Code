#include <stdio.h>

// This preprocessor directive defines a constant for the maximum array size.
// Using a #define constant makes the code cleaner and easier to modify.
#define MAX_SIZE 50

// Function prototype for BinarySearch. It takes an array, its size, and the item to find.
int BinarySearch(int arr[], int size, int item);

int main()
{
    // Declaring the array, its size, the item to be searched, and the result index.
    int arr[MAX_SIZE], size, item, index;
    
    // We check to make sure the user doesn't enter more elements than our array can hold.
    printf("Enter the number of elements (up to %d): ", MAX_SIZE);
    scanf("%d", &size);

    if (size > MAX_SIZE) {
        printf("Error: Number of elements exceeds maximum array size.\n");
        return 1;
    }

    // The binary search algorithm requires the array to be sorted.
    printf("Enter the elements (in sorted order): \n");
    for (int i = 0; i < size; i++)
    {
        scanf("%d", &arr[i]);
    }
    
    printf("Enter the item to be searched: ");
    scanf("%d", &item);
    
    // Call the `BinarySearch` function and store the result.
    index = BinarySearch(arr, size, item);
    
    // Check the returned index to see if the item was found.
    // The function returns -1 if the item is not in the array.
    if (index == -1)
    {
        printf("%d not found in array.\n", item);
    }
    else
    {
        // If the item is found, the function returns its index.
        // We add 1 to the index to show the human-readable position (starting from 1).
        printf("%d found at position %d.\n", item, index + 1);
    }
    
    return 0;
}

// This function performs a binary search on a sorted array.
int BinarySearch(int arr[], int size, int item)
{
    // `low` is the lower bound (start of the search range), initialized to 0.
    // `up` is the upper bound (end of the search range), initialized to the last index.
    int low = 0, up = size - 1, mid;

    // The search continues as long as the search range is valid (`low` is less than or equal to `up`).
    while (low <= up)
    {
        // We find the middle index of the current search range.
        mid = (low + up) / 2;
        
        // We compare the item with the middle element.
        if (item > arr[mid])
        {
            // If the item is greater, we discard the left half of the array.
            // We move the lower bound to `mid + 1`.
            low = mid + 1; // Search in the right half.
        }
        else if (item < arr[mid])
        {
            // If the item is smaller, we discard the right half of the array.
            // We move the upper bound to `mid - 1`.
            up = mid - 1; // Search in the left half.
        }
        else
        {
            // If the item matches the middle element, we have found it!
            // We return the index `mid`.
            return mid;
        }
    }
    
    // If the loop finishes without finding the item, it means the item is not in the array.
    // We return -1 to signal that the search failed.
    return -1;
}