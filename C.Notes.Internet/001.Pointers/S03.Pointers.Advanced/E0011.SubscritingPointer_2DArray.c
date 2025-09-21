#include<stdio.h>
int main()
{
    // This is our 2D array, which is a table of integers with 3 rows and 4 columns.
    // Think of this as a building with 3 floors, and each floor has 4 rooms.
    int arr[3][4] = {{10, 11, 12, 13}, {20, 21, 22, 23}, {30, 31, 32, 33}};

    // This is a "pointer to an array." It's a special kind of pointer that is designed
    // to hold the address of an entire row (an array of 4 integers).
    // Think of it as a blueprint that holds the address of the first floor.
    int (*ptr)[4];

    // We're assigning the address of the first row (`arr`) to our pointer `ptr`.
    // In C, the name of an array, `arr`, points to its first element, which in this
    // case is the first row.
    ptr = arr;

    // --- Let's explore how pointer arithmetic works with `ptr` ---

    // This line prints the addresses of the floors.
    // `ptr`: The address of the first floor.
    // `ptr + 1`: Moves the pointer forward by the size of a whole row (16 bytes, since 4 ints * 4 bytes/int).
    // This is the address of the second floor.
    // `ptr + 2`: Moves forward by another whole row, giving the address of the third floor.
    printf("%p %p %p\n", ptr, ptr + 1, ptr + 2);

    // This line is a bit trickier. The `*` dereferences the pointer.
    // `*ptr`: Go to the address `ptr` is holding (the first floor) and get the value.
    // What's the "value" of a floor? It's a pointer to the first room on that floor.
    
    // So, `*ptr` is the address of the very first element, `&arr[0][0]`.
    // `*ptr + 1`: Moves one step forward from that first room, pointing to the next room (`&arr[0][1]`).
    // `*ptr + 2`: Points to the next room (`&arr[0][2]`).
    // All three of these addresses are on the same, first floor.
    printf("%p %p %p\n", *ptr, *ptr + 1, *ptr + 2);

    // --- Let's access the values now ---

    // `**ptr`: This is a double dereference.
    // 1. `*ptr` gets you the address of the first room on the first floor.
    // 2. The second `*` gets you the value at that address: `10`.
    // `*(*(ptr + 1) + 2)`:
    
    // 1. `ptr + 1`: Gets the address of the second floor.
    // 2. `*(ptr + 1)`: Gets the address of the first room on the second floor.
    // 3. `*(ptr + 1) + 2`: Moves two steps forward to the third room on the second floor.
    // 4. The outer `*` gets the value: `22`.
    // `*(*(ptr + 2) + 3)`: Similar logic to get the last value: `33`.
    printf("%d %d %d\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));

    // This last line shows a beautiful truth: the `ptr[i][j]` syntax is just a cleaner
    // way of writing the complex pointer arithmetic above. The compiler handles the
    // translations for you. 
    printf("%d %d %d\n", ptr[0][0], ptr[1][2], ptr[2][3]);

    return 0;
}