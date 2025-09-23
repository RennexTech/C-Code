#include <stdio.h>
#include <string.h>

// Macros make the code easier to read and modify.
// `N` is the number of strings we have, and `LEN` is the maximum length of any single string.
#define N 5
#define LEN 10

int main()
{
    // This is a 2D array of characters, which is a classic C-style way to store an array of strings.
    // Think of it as a table where each row is a string. Since it's a fixed-size array, all rows
    // must have the same maximum length (`LEN`).
    char arr[N][LEN] = {
        "white",
        "red",
        "green",
        "yellow",
        "blue"
    };
    
    // We need a temporary character array (`temp`) to help us swap strings.
    // It's like having an empty shelf to temporarily hold a book while you rearrange your bookshelf.
    char temp[LEN];

    // First, we print the array in its original, unsorted order.
    printf("Before sorting: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%s  ", arr[i]);
    }
    printf("\n");

    // This is the **Bubble Sort** algorithm. We use nested loops to compare and sort the strings.
    // The outer loop (`i`) runs through each string.
    // The inner loop (`j`) compares the current string with every other string after it.
    for (int i = 0; i < N; i++)
    {
        for (int j = i + 1; j < N; j++)
        {
            // `strcmp` is a standard C library function that compares two strings alphabetically.
            // It returns a value greater than 0 if the first string comes after the second.
            if (strcmp(arr[i], arr[j]) > 0)
            {
                // If `arr[i]` is alphabetically greater than `arr[j]`, we swap them.
                // We use `strcpy` because you can't just assign one array to another with `=`.
                // `strcpy(destination, source)` copies the contents of the source string to the destination.
                strcpy(temp, arr[i]);     // 1. Copy `arr[i]` into our temporary storage.
                strcpy(arr[i], arr[j]);   // 2. Copy `arr[j]` into `arr[i]`'s spot.
                strcpy(arr[j], temp);     // 3. Copy the original `arr[i]` (from `temp`) into `arr[j]`'s spot.
            }
        }
    }

    // Finally, we print the sorted array.
    printf("After sorting: \n");
    for (int i = 0; i < N; i++)
    {
        printf("%s  ", arr[i]);
    }
    printf("\n"); // This newline ensures the command prompt starts on a fresh line.

    return 0;
}

// Reduce passive consumption online if you want to be good at coding. 

// Boredom is where flowing while coding comes from, do some fasting sometimes, not Biblical necessarily, 

// I mean that stuff makes you sharper, if you always on KFC, you'll never realize that your body can be 

// more active when you deny it fun, its another state of being, it induces flow and coding is way more fun. 

// But don't over do it, I mean, maybe sometimes skip that lunch and wait for supper. See how it goes... 

