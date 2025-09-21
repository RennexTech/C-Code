#include <stdio.h>

// Defines a constant for the maximum array size.
#define MAX 100

int main()
{
    // Declares an array, loop counters, and variables for the sorting process.
    int arr[MAX], i, j, k, n;

    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // This loop gets the elements from the user.
    for (i = 0; i < n; i++)
    {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // This is the **Insertion Sort** algorithm.
    // The outer loop starts at the second element (`i = 1`). We consider the first element to be already sorted.
    for (i = 1; i < n; i++)
    {
        // `k` stores the current element we want to insert into the sorted part of the array.
        k = arr[i];

        // The inner loop compares `k` with elements in the sorted part of the array (to the left).
        // It shifts elements to the right to make space for `k`.
        for (j = i - 1; j >= 0 && k < arr[j]; j--)
        {
            // We shift the element at `j` to the right, into the `j+1` position.
            arr[j + 1] = arr[j];
        }

        // Once the inner loop finishes, `j+1` is the correct position for `k`.
        // We insert `k` into its proper place in the sorted section.
        arr[j + 1] = k;
    }

    // After the sorting is complete, this loop prints the sorted array.
    printf("\nSorted list is:\n");
    for (i = 0; i < n; i++)
    {
        printf("%d\n", arr[i]);
    }

    return 0;
}