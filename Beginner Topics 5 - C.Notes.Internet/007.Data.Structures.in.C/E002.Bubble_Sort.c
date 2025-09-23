#include <stdio.h>

// Defines a constant for the maximum array size.
#define MAX 100

int main()
{
    int arr[MAX], temp, n, xchange;

    printf("Enter the number of elements (up to %d): ", MAX);
    scanf("%d", &n);

    // Input validation: ensure the user doesn't exceed the array size.
    if (n > MAX) {
        printf("Error: Number of elements exceeds maximum size.\n");
        return 1;
    }

    // This loop prompts the user to enter `n` elements into the array.
    for (int i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // This is the **Bubble Sort** algorithm.
    // The outer loop runs `n-1` times. Each pass places the next largest element in its correct position.
    for (int i = 0; i < n - 1; i++)
    {
        // `xchange` is a flag to check if any swaps were made in a pass.
        xchange = 0;
        
        // The inner loop compares adjacent elements and swaps them if they are out of order.
        // `n-1-i` ensures that we don't re-check the elements that are already sorted at the end.
        for (int j = 0; j < n - 1 - i; j++)
        {
            // If the current element is greater than the next one, we swap them.
            if (arr[j] > arr[j + 1])
            {
                temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                xchange++; // Increment `xchange` to indicate a swap occurred.
            }
        }
        
        // Optimization: if no swaps were made in a pass, the array is already sorted, and we can stop early.
        if (xchange == 0)
        {
            break;
        }
    }

    // We print the final sorted list after the sorting loops have completed.
    printf("\nSorted List is:\n");
    for (int i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}