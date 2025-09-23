#include <stdio.h>
int main()
{
    int arr[10] = {2, 5, 4, 1, 8, 9, 11, 6, 3, 7};
    int small, largest;
    small = largest = arr[0];
    for (int i = 0; i < 10; i++)
    {
        if (arr[i] < small)
            small = arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }
    printf("Smallest Num = %d, Largest Num = %d", small, largest);
    return 0;
}



// ====================================================================================

// SAME AS THE ABOVE
#include <stdio.h>

int main()
{
    // This is a fixed-size array. Think of it like a perfectly organized lunchbox
    // with 10 compartments. Everything is pre-sorted for our convenience.
    int arr[10] = {2, 5, 4, 1, 8, 9, 11, 6, 3, 7};
    int small, largest;

    // We start by assuming the first item is both the smallest and the largest.
    // This is like picking the first building on the street and using it as our
    // baseline for comparison.
    small = largest = arr[0];

    // We then walk down the rest of the street, checking each building.
    // If we find a building that's shorter than our current "smallest," we update
    // our record.
    // If we find one that's taller than our current "largest," we update that too.
    for (int i = 1; i < 10; i++)
    {
        // Check for smallest
        if (arr[i] < small)
            small = arr[i];

        // Check for largest
        if (arr[i] > largest)
            largest = arr[i];
    }

    printf("Smallest Num = %d, Largest Num = %d\n", small, largest);
    return 0;
}


// ====================================================================================
// MORE INTERMEDIATE

#include <stdio.h>

int main()
{
    // Our array. Same as before.
    int arr[10] = {2, 5, 4, 1, 8, 9, 11, 6, 3, 7};
    int small, largest;

    // We handle the first two elements as a special case to set our initial values.
    // This is like sending two detectives out at the same time to look at the first
    // two buildings and report back on which one is taller and which is shorter.
    if (arr[0] < arr[1]) {
        small = arr[0];
        largest = arr[1];
    } else {
        small = arr[1];
        largest = arr[0];
    }

    // Now, we loop through the rest of the array in pairs. This means we'll do half as many loops.
    // We start at index 2 since we already handled the first two elements.
    for (int i = 2; i < 10; i += 2)
    {
        // Let's compare the two elements in our current pair first.
        int a = arr[i];
        int b = arr[i + 1];

        if (a < b) {
            // If `a` is smaller, we compare it to our current smallest.
            if (a < small)
                small = a;
            // And compare `b` (the larger one) to our current largest.
            if (b > largest)
                largest = b;
        } else {
            // If `b` is smaller, we compare it to our current smallest.
            if (b < small)
                small = b;
            // And compare `a` (the larger one) to our current largest.
            if (a > largest)
                largest = a;
        }
    }

    printf("Smallest Num = %d, Largest Num = %d\n", small, largest);
    return 0;
}




// ====================================================================================
// MORE DYNAMIC AND ADVANCED

#include <stdio.h>
#include <stdlib.h> // For malloc and free

int main()
{
    int n, small, largest;

    // We're asking the user for the size of the array.
    // This is like telling the OS, "I don't know how big this is gonna be,
    // so just give me a space big enough for whatever they ask for."
    printf("Enter the size of the array: ");
    scanf("%d", &n);
    

    // We use `malloc` to request `n` chunks of memory, each big enough for an `int`.
    // This memory is on the heap, not the stack.
    int *arr = (int *)malloc(n * sizeof(int));
    
    // Always check if the memory was actually allocated! If the OS is out of memory,
    // `malloc` returns `NULL` and your program will crash if you don't check.
    if (arr == NULL) {
        printf("Memory not available.\n");
        return 1;
    }

    // Now we can use the pointer `arr` just like a regular array name.
    for (int i = 0; i < n; i++) {
        printf("Enter a value for arr[%d]: ", i);
        scanf("%d", &arr[i]);
    }

    // The core logic is the same as before, but we are now working with a
    // flexible, dynamic array.
    small = largest = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] < small)
            small = arr[i];
        if (arr[i] > largest)
            largest = arr[i];
    }
    
    printf("Smallest Num = %d, Largest Num = %d\n", small, largest);

    // This is the most important part of dynamic memory: we have to give it back.
    // If you don't call `free()`, you get a **memory leak**, which is a classic bug
    // that can lead to system instability.
    free(arr);
    
    return 0;
}

// ====================================================================================

// I did the above so that you can see that coding isn't rigid, you can mix and match depending on your skill level. 

// There's no single right way to solve a problem. 

// 1st one - simple fixed-sized array on the stack. 

// 2nd one does a loop optimization starting at 1. 

// 3rd one goes more hardware level memory stuff. 

// Coding is a creative process. You don't have to do it like your fellow friend did it. 

// I know I lost my fun / memeing-mode when writing this code in chapter 2, but am going to be fixing that in future. For now, I just wanted a functional repo. 

