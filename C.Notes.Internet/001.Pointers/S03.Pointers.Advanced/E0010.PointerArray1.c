#include<stdio.h>
int main()
{
    // This is our main array. Think of `arr` as a bookshelf with four books on it,
    // holding the numbers 5, 10, 15, and 20.
    int i, arr[4] = {5, 10, 15, 20};

    // This is an array of pointers. It's a list with four blank lines,
    // where we can write down addresses.
    int *pa[4];

    // This loop populates our list of addresses.
    // We're iterating through each book on the shelf (`arr[i]`) and
    // writing down its exact location (memory address) on our list (`pa[i]`).
    // `&arr[i]` gets the address of the i-th book.
    for (int i = 0; i < 4; i++)
    {
        pa[i] = &arr[i];
    }

    // Now, we're using our list of addresses to access the books and their contents.
    for (int i = 0; i < 4; i++)
    {
        // This first line prints the **address** stored at the i-th position of our list.
        // It's like reading the address written on line `i`.
        printf("pa[%d] = %p\t", i, pa[i]);

        // This second line prints the **value** at that address.
        // The `*` operator means "go to the address on this line and tell me what's there."
        // We're using our list to find the book and read its number.
        printf("*pa[%d] = %d\n", i, *pa[i]);
    }

    return 0;
}