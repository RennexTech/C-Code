#include <stdio.h>
#include <stdlib.h> // This is for `malloc`, `calloc`, and `free`.

int main()
{
    // A pointer to hold the address of our dynamically allocated memory.
    int *ptr;
    int n;

    // We're asking the user how many integers they need space for.
    printf("Enter the size of array you want to create: ");
    scanf("%d", &n);

    // --- The `calloc()` Magic ---
    // `calloc()` is like `malloc()`, but with a bonus feature.
    // It allocates the memory *and* initializes every single bit to zero.
    // Think of `malloc()` as renting a messy room that might have junk left behind.
    // `calloc()` is like renting a room that's been spotless and empty from the start.
    ptr = (int *)calloc(n, sizeof(int));
    

    // A crucial check to make sure the memory was actually allocated.
    if (ptr == NULL) {
        printf("Memory not available\n");
        return 1;
    }

    // Now, we can use our pointer `ptr` just like a regular array name to
    // take user input.
    for (int i = 0; i < n; i++)
    {
        printf("Enter the value no %d of this array: ", i);
        scanf("%d", &ptr[i]);
    }

    // Finally, we print out the values to show they were stored correctly.
    for (int i = 0; i < n; i++)
    {
        printf("The value at index %d of this array is: %d\n", i, ptr[i]);
    }
    
    // --- The Final Crucial Step: Giving Memory Back ---
    // If you don't call `free()` on `ptr`, this memory will stay "reserved"
    // until your program ends, which is a memory leak. It's like renting that
    // spotless room and then just walking away without telling anyone you're done.
    free(ptr);
    
    return 0;
}
