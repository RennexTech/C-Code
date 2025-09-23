#include <stdio.h>

// Defines a constant for the maximum array size.
#define MAX 10

// Function prototype for LinearSearch. It takes an array, its size, and the item to find.
int LinearSearch(int arr[], int n, int item);

int main() {
    int n, arr[MAX], item, index;

    // Prompt user for input and read the number of elements.
    printf("Enter the number of elements (up to %d): ", MAX);
    scanf("%d", &n);

    // Prompt user for input and fill the array.
    printf("Enter the elements:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }

    // Prompt user for the item to search for.
    printf("Enter the item to be searched: ");
    scanf("%d", &item);

    // Call the search function and store the result.
    index = LinearSearch(arr, n, item);

    // Check the returned index to determine if the item was found.
    if (index == -1) {
        printf("%d not found in the array.\n", item);
    } else {
        // If found, print the position (index + 1, since arrays are 0-indexed).
        printf("%d found at position %d.\n", item, index + 1);
    }

    return 0;
}

// This function performs a linear search on an array.
int LinearSearch(int arr[], int n, int item) {
    int i = 0;

    // The core of the algorithm: a loop that checks each element one by one.
    // The loop continues as long as we haven't reached the end of the array (`i < n`)
    // and the current element is not the item we're looking for.
    while (i < n && item != arr[i]) {
        i++; // Move to the next element.
    }

    // After the loop, we check the value of `i`.
    // If `i` is less than `n`, it means the loop terminated because the item was found.
    if (i < n) {
        return i; // Return the index of the found item.
    } else {
        // If `i` is equal to `n`, it means the loop finished without finding the item.
        return -1; // Return -1 to indicate failure.
    }
}


/*

Analogy: Finding a Book on a Shelf 📚

Linear search is the most straightforward way to find an item.

Imagine you're looking for a specific book on a shelf. 

You start at the very first book and check if it's the one you want. 

If not, you move to the next book, and the next, in a straight line, until you either find the book 

or you run out of books on the shelf. 

The code does this exact process, checking each element sequentially. 

This method works for any array, whether it's sorted or not.

*/
