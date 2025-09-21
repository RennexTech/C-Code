#include <stdio.h>

#define MAX 100

int main(void) {
    int arr[MAX], n, temp, min_index;

    // Get the number of elements from the user.
    printf("Enter the number of elements: ");
    scanf("%d", &n);

    // Get the array elements from the user.
    for (int i = 0; i < n; i++) {
        printf("Enter element %d: ", i + 1);
        scanf("%d", &arr[i]);
    }

    // This is the **Selection Sort** algorithm.
    // The outer loop iterates through the unsorted part of the array.
    for (int i = 0; i < n - 1; i++) {
        // Assume the current element is the smallest.
        min_index = i;

        // The inner loop finds the actual smallest element in the rest of the array.
        for (int j = i + 1; j < n; j++) {
            // If we find a smaller element, we update `min_index`.
            if (arr[j] < arr[min_index]) {
                min_index = j;
            }
        }

        // After the inner loop, `min_index` holds the index of the smallest element.
        // We swap the smallest element with the first element of the unsorted part.
        // This places the smallest element in its correct, sorted position.
        if (min_index != i) {
            temp = arr[i];
            arr[i] = arr[min_index];
            arr[min_index] = temp;
        }
    }

    // Print the final sorted list.
    printf("\nSorted list is:\n");
    for (int i = 0; i < n; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");

    return 0;
}


/*

Selection Sort is like sorting a hand of playing cards.

You start with all the cards in one hand and need to sort them.

Find the smallest card by looking through all the cards in the hand.

Move it to the front by placing that smallest card at the beginning of your hand.

Repeat the process: Look through the remaining unsorted cards, find the next smallest, and place it in the second position.

Continue doing this one by one until your entire hand is sorted.

In the code:

The outer loop (i) marks the start of the unsorted portion.

The inner loop (j) finds the minimum value.

The swap is performed to put the minimum value in the correct position.

*/