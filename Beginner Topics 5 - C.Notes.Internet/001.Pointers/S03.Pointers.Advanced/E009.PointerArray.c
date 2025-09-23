#include<stdio.h>
int main()
{
    // We're creating an array of pointers to integers.
    // Think of `pa` as a small notebook with three empty lines. Each line is for writing down a memory address.
    int *pa[3];

    // These are our three integer variables. They're like three separate houses.
    int a = 5, b = 10, c = 15;

    // We're now filling our notebook. We're writing the address of house `a` on the first line,
    // the address of house `b` on the second, and the address of house `c` on the third.
    // The `&` operator gives us the memory address of each variable.
    pa[0] = &a;
    pa[1] = &b;
    pa[2] = &c;

    // This loop lets us look at what we've written in our notebook.
    for (int i = 0; i < 3; i++)
    {
        // This first line prints the **value** inside each slot of our notebook (`pa`).
        // The value is the memory address of one of our houses.
        printf("pa[%d] = %p\t", i, pa[i]);

        // This second line is about dereferencing the pointer. The `*` operator means
        // "go to the address stored in `pa[i]` and get the value you find there."
        // We are using the address in our notebook to visit the house and see what number is inside.
        printf("*pa[%d] = %d\n", i, *pa[i]);
    }

    return 0;
}


// ============================================================================


#include<stdio.h>
int main()
{
    // Let's create an array of pointers to integers.
    // Think of `pa` as a small notebook with three empty pages. Each page can hold a memory address.
    int *pa[3];

    // We have three individual variables, stored in separate, non-contiguous locations in memory.
    // These are like three separate houses on different streets.
    int a = 5, b = 10, c = 15;

    // Now, we'll write the address of each house onto a separate page in our notebook.
    // The `&` operator gives us the memory address of each variable.
    pa[0] = &a; // Page 0 in the notebook has the address of house 'a'.
    pa[1] = &b; // Page 1 has the address of house 'b'.
    pa[2] = &c; // Page 2 has the address of house 'c'.

    // We can use our notebook to visit each house.
    for (int i = 0; i < 3; i++)
    {
        // This first line prints the **address** written on each page of our notebook.
        // It shows where each variable is located in memory.
        printf("The address on page %d of our notebook is %p\t", i, pa[i]);

        // This second line prints the **value** we find at that address.
        // The `*` operator means "go to the address on this page and get the value."
        printf("The value inside the house at that address is %d\n", *pa[i]);
    }

    return 0;
}

// ============================================================================

