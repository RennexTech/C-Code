#include <stdio.h>

int main()
{
    // Let's create an array, which is like a row of identical boxes.
    // We'll call this row `arr` and give it 5 boxes, each holding an integer.
    // The numbers {5, 10, 15, 20, 25} are the items we're placing in our boxes.
    int arr[5] = {5, 10, 15, 20, 25};

    // We'll use a `for` loop to look inside each box, one by one.
    // The variable `i` is our 'box number' or 'index', starting at 0.
    for (int i = 0; i < 5; i++)
    {
        // This first line is about the **content** of the box.
        // `arr[i]` means "the value inside the box at position `i`."
        // We're saying: "The item in box number `i` is `arr[i]`."
        printf("Value of arr[%d] = %d\t", i, arr[i]);

        // This second line is about the **location** of the box.
        // `&arr[i]` means "the memory address of the box at position `i`."
        // Think of this as the physical street address of each box.
        // Notice how the addresses are right next to each other?
        // This is the key idea of an array: all its elements are stored
        // in a single, contiguous block of memory. It's like a solid
        // line of houses with sequential house numbers. 
        printf("Address of arr[%d] = %p\n", i, &arr[i]);
    }

    return 0;
}