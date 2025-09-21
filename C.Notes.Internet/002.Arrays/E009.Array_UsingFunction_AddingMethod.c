#include <stdio.h>
int add(int arr[], int n);
int main()
{
    int a[5] = {2, 4, 6, 8, 10};
    int b[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Sum of element of array a : %d\n", add(a, 5));
    printf("Sum of element of array b : %d\n", add(b, 8));
    printf("Sum of element of array c : %d\n", add(c, 10));
}
int add(int arr[], int n)
{
    int sum = 0;
    for (int i = 0; i < n; i++)
        sum = sum + arr[i];
    return sum;
}



// =======================================================================
// SAME CODE

#include <stdio.h>

// This is a function prototype. It's like a table of contents that tells the compiler:
// "Hey, there's a function coming up called `add`. It takes an integer array and an integer,
// and it will return an integer."
int add(int arr[], int n);

int main()
{
    // These are three separate arrays, each with its own set of numbers.
    // Think of them as three different baskets of fruit.
    int a[5] = {2, 4, 6, 8, 10};
    int b[8] = {1, 3, 5, 7, 9, 11, 13, 15};
    int c[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    // We're calling the `add` function three times, once for each basket.
    // We pass the basket (the array) and the number of fruits in it (the size).
    // The function will return the total number of fruits, which we then print.
    printf("Sum of element of array a: %d\n", add(a, 5));
    printf("Sum of element of array b: %d\n", add(b, 8));
    printf("Sum of element of array c: %d\n", add(c, 10));

    return 0;
}

// This is our `add` function. Its job is to calculate the sum of the elements in an array.
// `arr[]` is a **pointer** to the beginning of the array passed in. It's like being
// handed a map to a treasure chest.
// `n` is the number of items we need to count.
int add(int arr[], int n)
{
    // `sum` is our accumulator. We initialize it to zero, like an empty piggy bank.
    int sum = 0;

    // This `for` loop goes through each element of the array.
    // It's like a person at the treasure chest, taking out one coin at a time.
    for (int i = 0; i < n; i++)
        // With each step, we add the value of the current element (`arr[i]`) to our `sum`.
        // The person adds each coin to their piggy bank.
        sum = sum + arr[i];

    // Finally, we return the total `sum`. The person hands back the full piggy bank.
    return sum;
}