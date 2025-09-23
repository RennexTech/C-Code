#include <stdio.h>
#include <stdlib.h> // This is for `calloc` and `realloc`.

int main()
{
    // A pointer to hold the address of our dynamically allocated memory.
    int *ptr = NULL;
    int n;

    // --- Using `calloc()` to start our dynamic array ---
    printf("Enter the size of the array you want to create: ");
    scanf("%d", &n);

    // `calloc()` allocates memory and initializes it all to zero.
    // It's like renting a storage unit and finding it completely empty and spotless.
    ptr = (int *)calloc(n, sizeof(int));
    
    // Always check if the memory was allocated successfully.
    if (ptr == NULL) {
        printf("Memory not available.\n");
        return 1;
    }

    // Now, we fill the array with some initial values.
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array: ", i);
        scanf("%d", &ptr[i]);
    }

    // And print out the initial contents.
    printf("\nThe initial array values are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("The value at %d of this array is: %d\n", i, ptr[i]);
    }

    // --- Using `realloc()` to resize the array ---
    printf("\nEnter the new size of the array: ");
    scanf("%d", &n);
    
    // We create a temporary pointer. This is a critical security practice!
    // `realloc()` might fail and return `NULL`. If we overwrite `ptr` directly,
    // we'd lose the original memory and get a memory leak.
    int *temp_ptr = (int *)realloc(ptr, n * sizeof(int));

    // We check if the reallocation succeeded.
    if (temp_ptr == NULL) {
        // If it failed, we print an error and `free` the original `ptr`.
        printf("Memory reallocation failed. Original memory block is still available.\n");
        free(ptr);
        return 1;
    }
    
    // If it succeeded, we can now safely update our main pointer.
    // `realloc` returns a pointer to the newly sized memory block, which could be
    // at a completely different address from the original.
    ptr = temp_ptr;
    

    // We fill the new array. Notice we're not starting at 0, because `realloc()`
    // keeps the existing data and just extends or shrinks the memory.
    // We'll just populate the new space for this example.
    for (int i = 0; i < n; i++)
    {
        // This is a simple demo to show the array can be filled now.
        printf("Enter the new value no %d of this array: ", i);
        scanf("%d", &ptr[i]);
    }

    // And print out the final contents to show the changes.
    printf("\nThe new array values are:\n");
    for (int i = 0; i < n; i++)
    {
        printf("The new value at %d of this array is: %d\n", i, ptr[i]);
    }

    // The final and most important step: free the memory we borrowed.
    free(ptr);
    
    return 0;
}
