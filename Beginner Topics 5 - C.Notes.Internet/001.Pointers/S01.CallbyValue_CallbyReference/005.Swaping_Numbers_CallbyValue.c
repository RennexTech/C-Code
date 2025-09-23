#include<stdio.h>

/*
* This function's whole mission is to swap the values of two variables.
* It doesn't get the values themselves (like 34 and 73), but rather
* their memory addresses. Think of it as a house-sitter with two keys.
* The function can go into those two houses and rearrange the furniture
* (the values) without ever touching the house next door.
*/
int swap(int *x, int *y)
{
    // We create a temporary storage space for one of the values.
    // This is like an empty box you need to hold something while you
    // move things around. We copy the value at the address of x into it.
    // The asterisk (*) here means "the value at this address."
    int temp = *x;
    
    // Now we go to the house at the address of x and place the value
    // from the house at the address of y inside it.
    *x = *y;
    
    // Finally, we go to the house at the address of y and put the
    // original value of x from our temporary storage box into it.
    *y = temp;
    
    // The function returns the original value of x, but this is less important
    // than the fact that the values at the memory addresses we were given
    // have been permanently changed.
    return temp;
}

int main()
{
    int a = 34, b = 73;
    
    // This is what our variables look like before the swap.
    printf("%d and %d\n", a, b);
    
    // Here, we're giving the function the keys (the memory addresses)
    // to our variables `a` and `b`. The `&` symbol means "get the address of."
    // We're not sending the values 34 and 73, but where they live in memory.
    swap(&a, &b);
    
    // Now, we print the values again. Since the swap function used the
    // addresses to change the original variables, the values are now swapped.
    printf("%d and %d\n", a, b);
    
    return 0;
}
