#include <stdio.h>

int main() {
    /*
     *
     * ## The Array of Pointers: Your Memory Address Book
     *
     * In C, an array of pointers is exactly what it sounds like: an array where each
     * element is a pointer. Think of it as a special address book. Each page in this
     * book isn't a person's name; it's a physical street address. You can have these
     * addresses point to anything—a single house on one street, an apartment in a
     * large complex, or even the beginning of an entire street.
     *
     * The syntax `int *pa[3];` is what declares this address book. It says, "Create
     * an array named `pa` that can hold 3 entries, and each entry will be a pointer
     * to an integer." This is different from a pointer to an array. If you see this in
     * a binary, it's a dead giveaway that the code is setting up a list of memory
     * locations it wants to jump to later, which is a common technique in malware for
     * indirect function calls or obfuscating data.
     *
     */

    printf("## Example 1: Pointers to Individual, Unrelated Variables\n");

    int *pa_individual[3]; // An array of 3 integer pointers
    int a = 5, b = 10, c = 15;

    // We're assigning the unique street address of each variable to our
    // address book. The houses (variables `a`, `b`, `c`) are not next
    // to each other in memory, but our address book can still find them.
    pa_individual[0] = &a;
    pa_individual[1] = &b;
    pa_individual[2] = &c;

    for (int i = 0; i < 3; i++) {
        // `pa_individual[i]` gives us the address (the page in our book).
        // `*pa_individual[i]` is like visiting that address to get the value.
        printf("Address in pa[%d] = %p\tValue at that address = %d\n",
               i, (void *)pa_individual[i], *pa_individual[i]);
    }
    printf("\n");

    printf("## Example 2: Pointers to Elements of a 1D Array\n");

    int *pa_1d[4]; // An array of 4 integer pointers
    int arr[4] = {5, 10, 15, 20};

    // Here, our address book points to apartments within a single apartment complex
    // (the `arr` array). The addresses are next to each other in memory, but our
    // address book is still a separate list of pointers.
    for (int i = 0; i < 4; i++) {
        pa_1d[i] = &arr[i];
    }

    for (int i = 0; i < 4; i++) {
        printf("Address in pa[%d] = %p\tValue at that address = %d\n",
               i, (void *)pa_1d[i], *pa_1d[i]);
    }
    printf("\n");


    printf("## Example 3: Pointers to Rows of a 2D Array\n");
    /*
     *
     * This is where it gets spicy. A 2D array in C is an "array of 1D arrays."
     * This means that `arr_2d[0]` is not a single value; it's a pointer to the
     * first element of the first row. It's an address.
     *
     * So, when we do `pa_2d[i] = arr_2d[i];`, we are taking the starting address
     * of each row and putting it into our array of pointers. Our address book
     * now holds the starting address for each of the three streets.
     *
     * The `pa_2d[i][j]` syntax is pure C magic. The compiler sees this and knows
     * what's up. It goes to entry `i` in the `pa_2d` array, gets the starting
     * address for that row, and then moves forward `j` positions to get the
     * final value.
     *
     * A pro tip for your reverse engineering journey: When you see a list of
     * addresses in a program's data section, it's often a "jump table" or "dispatch
     * table." The program finds an index, looks up the corresponding address in
     * the table, and jumps to that location. An array of pointers is the high-level
     * C equivalent of that.
     *
     */
    int arr_2d[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };
    int *pa_2d[3]; // An array of 3 integer pointers

    // Assigning the base address of each row to an element in our pointer array.
    for (int i = 0; i < 3; i++) {
        pa_2d[i] = arr_2d[i];
    }

    // Now we can use `pa_2d[i][j]` as if `pa_2d` were a 2D array itself.
    printf("Accessing 2D array elements using the array of pointers:\n");
    for (int i = 0; i < 3; i++) {
        for (int j = 0; j < 4; j++) {
            printf("%d ", pa_2d[i][j]);
        }
        printf("\n");
    }

    return 0;
}
