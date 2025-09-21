/*

Let's break down the concept of subscripting a pointer to a 2-D array in C programming.

Suppose we have a 2-D array named arr with 3 rows and 4 columns, and we also have a pointer to an array of 4 integers named ptr that contains the base address of the arr array. Here's what it looks like:

// Different ways to initialize two-dimensional array

int c[2][3] = {{1, 3, 0}, {-1, 5, 9}};

int c[][3] = {{1, 3, 0}, {-1, 5, 9}};

int c[2][3] = {1, 3, 0, -1, 5, 9};


*/
void arr1()
{
        int arr[3][4] = {
        {10, 11, 12, 13},
        {20, 21, 22, 23},
        {30, 31, 32, 33}
    };

    int (*ptr)[4]; //points to an array with 4 elements, which can be other arrays.
    ptr = arr; //We assign the base address of the arr array to ptr.

}


/*

In the code above, arr is a 2-D array with three rows and four columns, and ptr is a pointer to an array of four integers. We assign the base address of the arr array to ptr.

Now, let's understand how to access elements in this 2-D array using pointer notation.

ptr + i points to the i-th row of the 2-D array.

This is because ptr is a pointer to an array of four integers, so when we add i to it, it moves to the i-th row.

*(ptr + i) gives us the base address of the i-th row.

By dereferencing ptr + i, we get the starting address of the i-th row.

To access the address of the j-th element of the i-th row, we can add j to the pointer expression *(ptr + i).

Finally, *(*(ptr + i) + j) gives us the value of the j-th element of the i-th row.

So, in summary, *(*(ptr + i) + j) is equivalent to the subscript expression arr[i][j].

It allows you to access elements in a 2-D array when you have a pointer to that array.

For example, if you want to access the element at the 2nd row and 3rd column (i.e., arr[1][2]), you can use *(*(ptr + 1) + 2).


*/


#include <stdio.h>

int main()
{
    int i, arr[3][4] = {{10,11,12,13}, {20,21,22,23}, {30,31,32,33}};
    int (*ptr)[4]; // Declare a pointer to an array of 4 integers
    ptr = arr;// Assign the base address of 'arr' to 'ptr'

    // Printing addresses using pointer arithmetic
    printf("%u %u %u\n", ptr, ptr+1, ptr+2);

    // Printing base addresses of rows
    printf("%u %u %u\n", *ptr, *(ptr+1), *(ptr+2));

    // Printing values using pointer dereferencing
    printf("%u %u %u\n", **ptr, *(*(ptr+1)+2), *(*(ptr+2)+3));

    // Printing elements using array subscripting
    printf("%u %u %u\n", ptr[0][0], ptr[1][2], ptr[2][3]);
    return 0;

}

/*
My output:(yours will be different)

6421984 6422000 6422016
6421984 6422000 6422016
10 22 33
10 22 33

============================================

int (*ptr)[4];: This declares a pointer ptr to an array of 4 integers. In our case, it will be used to point to the rows of the 2-D array arr.

ptr = arr;: This assigns the base address of the 2-D array arr to the pointer ptr. Now, ptr points to the first row of arr.

printf("%u %u %u\n", ptr, ptr + 1, ptr + 2);: This line prints the addresses of the rows using pointer arithmetic. ptr points to the first row, ptr + 1 points to the second row, and ptr + 2 points to the third row.

printf("%u %u %u\n", *ptr, *(ptr + 1), *(ptr + 2));: Here, we print the base addresses of the rows. *ptr gives the address of the first row, *(ptr + 1) gives the address of the second row, and so on.

printf("%u %u %u\n", **ptr, *(*(ptr + 1) + 2), *(*(ptr + 2) + 3));: This line prints the values using pointer dereferencing. **ptr gives the value of the element in the first row and first column (i.e., arr[0][0]). *(*(ptr + 1) + 2) gives the value of the element in the second row and third column (i.e., arr[1][2]). *(*(ptr + 2) + 3) gives the value of the element in the third row and fourth column (i.e., arr[2][3]).

printf("%u %u %u\n", ptr[0][0], ptr[1][2], ptr[2][3]);: Finally, this line prints the elements using array subscripting. ptr[0][0] is equivalent to arr[0][0], ptr[1][2] is equivalent to arr[1][2], and ptr[2][3] is equivalent to arr[2][3].

So, the program demonstrates different ways to access and print elements of a 2-D array using both pointer notation and array subscripting. It's a useful example to understand how pointers can be used to work with multi-dimensional arrays in C.
*/

