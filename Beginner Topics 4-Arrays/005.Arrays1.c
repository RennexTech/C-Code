#include <stdio.h>

// This function finds the smallest and largest values in a simple array.
void min_max_array() {
    // Imagine you're scanning a list of items to find the cheapest and most expensive.
    // You start by assuming the very first item is both the cheapest and most expensive.
    // Then, you go through the rest of the list, comparing each item to your current
    // cheapest and most expensive. If you find a better deal (a new minimum) or
    // a higher price (a new maximum), you update your assumptions.
    int i;
    int min, max;
    int array6[10] = { 2, 5, 4, 1, 8, 9, 11, 6, 3, 7 };

    // Both `min` and `max` are initialized to the first element's value.
    min = max = array6[0];

    for (i = 0; i < 10; i++) {
        if (array6[i] < min)
            min = array6[i];

        if (array6[i] > max)
            max = array6[i];
    }
    printf("The minimum in the array is: %d\nThe maximum in the array is: %d\n", min, max);
}

// This function flips the order of elements in an array.
void reverse_array() {
    // Think of this like two people walking towards each other on a line of items.
    // One person starts at the front (`i`), the other at the back (`j`).
    // They meet in the middle, swapping items as they go.
    int i, j;
    int temp; // A temporary space to hold an item during the swap.
    int array7[10] = { 2, 5, 4, 1, 8, 9, 11, 6, 3, 7 };

    // We use two counters in one loop here: `i` starts at the beginning and goes up,
    // and `j` starts at the end and goes down. The loop runs until they meet in the middle.
    for (i = 0, j = 9; i < j; i++, j--) {
        // This is a three-step swap. We can't just set `array7[i] = array7[j]`
        // because we'd lose the original `array7[i]` value. So we use `temp`
        // as a holding spot.
        temp = array7[i];
        array7[i] = array7[j];
        array7[j] = temp;
    }
    
    printf("After reversing the array, it is: ");
    for (i = 0; i < 10; i++)
        printf("%d ", array7[i]); // Note the space for readability.
    printf("\n");
}

// This function sums up all the numbers in an array.
// We pass in the array and its size (`n`) to make this function reusable.
int add(int array[], int n) {
    // This is like adding up a grocery bill. You start with a total of zero
    // and then go through each item, adding its price to the running total.
    int i;
    int sum = 0;
    for (i = 0; i < n; i++) {
        sum += array[i];
    }
    return sum;
}

// This function prints a two-dimensional array.
void two_d_arrays() {
    // Think of a spreadsheet. This code is like printing that spreadsheet to paper.
    // The outer `for` loop handles the rows, and the inner one handles the columns.
    int array8[4][5] = {
        {1, 2, 3, 4, 5},
        {6, 7, 8, 9, 10},
        {11, 12, 13, 14, 15},
        {16, 17, 18, 19, 20}
    };
    
    int i, j;
    for (i = 0; i < 4; i++) {
        for (j = 0; j < 5; j++) {
            printf("%d ", array8[i][j]);
        }
        printf("\n"); // Move to the next line after each row.
    }
}

// The main function where everything comes together.
int main() {
    // We're declaring some arrays here. Notice how we don't need to specify their size.
    // The compiler figures it out for us based on the number of elements we provide.
    int a[] = {2, 32, 345, 234, 12, 632, 46};
    int b[] = {54, 2345, 5, 856, 34, 96, 435, 23, 123, 746};
    int c[] = {23, 2};

    // We're calling our `add` function with different arrays and their actual sizes.
    // This is important because C doesn't automatically know the size of an array
    // when you pass it to a function.
    printf("Sum of elements of array a: %d\n", add(a, 7)); // Changed to 7, the actual size
    printf("Sum of elements of array b: %d\n", add(b, 10)); // Changed to 10
    printf("Sum of elements of array c: %d\n", add(c, 2)); // Changed to 2
    printf("\n");

    min_max_array();
    printf("\n");

    reverse_array();
    printf("\n");

    two_d_arrays();
    printf("\n");

    return 0;
}
