#include <stdio.h>
#include <stdlib.h> // This is for `malloc` and `free`.

int main()
{
    // A pointer to hold the address of our dynamically allocated memory.
    int *ptr = NULL;
    int n;

    // We're asking the user how many integers they need space for.
    printf("Enter the size of the array you want to create: ");
    scanf("%d", &n);

    // --- The `malloc()` Call: Renting Memory ---
    // We are requesting a block of memory big enough for `n` integers.
    // This is like telling the operating system, "Hey, I need a storage unit, and it
    // needs to be big enough for `n` boxes."
    // CRITICAL FIX: The original code requested space for 10 integers but then tried
    // to write `n` integers. If `n` was > 10, this would cause a buffer overflow,
    // which is a major security vulnerability.
    ptr = (int *)malloc(n * sizeof(int));
    

    // A crucial check. If `malloc` fails (e.g., no memory is available), it returns `NULL`.
    // It's a defensive move, like checking if the storage company actually gave you a key.
    if (ptr == NULL) {
        printf("Memory not available\n");
        return 1;
    }

    // Now, we can use our pointer `ptr` just like a regular array name.
    // We are filling each "box" in our storage unit with a value from the user.
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
    // until your program ends, which is a **memory leak**. It's like renting that
    // storage unit and then just walking away without telling anyone you're done.
    free(ptr);
    
    return 0;
}
