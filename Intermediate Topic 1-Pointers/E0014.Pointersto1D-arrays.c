#include <stdio.h>
#include <stdlib.h>


/*

It seems you're providing information about the relationship between pointers and one-dimensional arrays in C. This information is correct and essential to understand how pointers and arrays work together. Here's a summary of the key points you've mentioned:

Elements of an array are stored in consecutive memory locations.

When you declare an array, its elements are allocated in contiguous memory locations. For example, int arr[5] will store its elements in sequential memory addresses.

The name of an array is a constant pointer that points to the first element of the array.

The array name, such as arr, acts as a constant pointer pointing to the address of the first element in the array. It's often referred to as the base address of the array.

Pointer arithmetic allows you to move through array elements.

When you increment a pointer variable, it moves to the next location of its base type. In the case of an integer array, incrementing a pointer to int will point to the next integer in memory.
Here's an example based on your provided data:

*/
int main()
{
    int arr[5] = {5, 10, 15, 20, 25};

    printf("Hello world!\n");
    return 0;
}


/*

In this array:

arr is the name of the array, acting as a constant pointer to the first element.

arr[0] is the first element, which is 5.
arr[1] is the second element, which is 10.
arr[2] is the third element, which is 15.
arr[3] is the fourth element, which is 20.
arr[4] is the fifth element, which is 25.

You can access these elements using array subscript notation (arr[i]) or by using pointer arithmetic with the array name (*arr, *(arr + 1), and so on). Understanding this relationship between arrays and pointers is fundamental in C programming.

*/

/*

The program below correctly shows that array elements are stored in consecutive memory locations.

*/

int main1() {
    int arr[5] = {5, 10, 15, 20, 25};
    int i;

    for (i = 0; i < 5; i++) {
        //print value where we are in the array, our current position
        printf("Value of arr[%d] = %d\n", i, arr[i]);
        //print the address of where we are in the array, our current position
        printf("Address of arr[%d] = %u\n", i, &arr[i]);
        //current position is indicated by arr[i]
        //meaning that exact position, that exact index
    }

    return 0;
}


/*

Explanation:

You declare an integer array arr with 5 elements and initialize it with values.

In a for loop, you iterate through the elements of the array from 0 to 4 (inclusive).

Within the loop, you use printf to print both the value and the address of each element in the array.

arr[i] gives the value of the current element.
&arr[i] gives the address of the current element.

Output:

Value of arr[0] = 5
Address of arr[0] = 2000
Value of arr[1] = 10
Address of arr[1] = 2002
Value of arr[2] = 15
Address of arr[2] = 2004
Value of arr[3] = 20
Address of arr[3] = 2006
Value of arr[4] = 25
Address of arr[4] = 2008


The output clearly shows that each element of the array has a consecutive memory address, and the values and addresses are printed accordingly. This is a great example of how arrays are stored in memory and how you can access their elements and addresses in C.


Let's clarify the key points:

The name of the array 'arr' represents the address of the 0th element of the array, which is 2000 in your example. It's important to note that 'arr' and '&arr[0]' are equivalent and both represent the address of the first element.

The name of an array is indeed a constant pointer to its first element. It behaves like a pointer in many ways.

Pointer arithmetic allows you to move through elements of the same base type. When you add an integer to a pointer (e.g., (arr + 1)), you get the address of the next element of the same base type.

So, (arr + 1) represents the address of the second element (arr[1]), (arr + 2) represents the address of the third element (arr[2]), and so on.

In essence, you can use pointer expressions like (arr + i) to navigate through the array elements, and it's equivalent to using array subscript notation (arr[i]).

Understanding these relationships is crucial when working with arrays and pointers in C programming. Your understanding aligns perfectly with these fundamental concepts.

======================================

REMEMBER!!!!!!!!!!!

Arrays start from index 0, not 1. So 0 is the first index.

Absolutely, that's a crucial point to remember in many programming languages, including C. In arrays, the first element is accessed using index 0, not 1. This means that when you have an array with 'n' elements, the valid indices range from 0 to n-1. So, the element at index 0 is the first element, the element at index 1 is the second element, and so on. Thank you for emphasizing this important detail!

n-1
n-1
n-1

I've repeated that coz n is the last index, and since we started from 0, we subtract 1 from the number of items in the array.

Say, arr[10]

So, n-1 indexes from 0 to 9.

So, 10-1 indexes which is 9 indexes(0 to 9).

In short, in arrays, the last index 'n-1' represents the final element because indexing starts from 0. For example, in an array 'arr[10]', the valid indices range from 0 to 9. So, 'n-1' is used to denote the last index, which covers all the elements from the first (index 0) to the last (index 'n-1').

======================================

The pointer expression (arr + i) denotes the same address as &arr[i]. When we dereference arr, we obtain the 0th element of the array.

In other words, the expression *arr or *(arr + 0) represents the 0th element of the array.

Similarly, by dereferencing (arr + 1), we access the 1st element, and so forth for higher indices in the array.

This demonstrates the relationship between pointer arithmetic and array indexing.

So in subscript notation the address of an array element is &arr[i] and its value is arr[i], while in pointer notation the address is (arr+i). and the element is *(arr+i).

======================================

In subscript notation, the address of an array element is &arr[i], and its value is arr[i].

In pointer notation, the address is (arr + i), and the element's value is *(arr + i).

This encapsulates the relationship between array subscript notation and pointer notation, showing how to access both addresses and values of array elements using these two notations in C programming. Well done!

======================================

You scanf like arr[i], not &arr[i], that is if its an integer array, what if its a string array?

======================================

You're correct in your observation. When using scanf for input in C, you typically specify the variable where you want to store the input value directly, without using the address-of operator &, for certain data types like integers, characters, and strings.

Here's a distinction between integer and string arrays:

Integer Array:

When reading an integer into an integer array, you generally use scanf like this: scanf("%d", &arr[i]);. This is because scanf expects a pointer to the variable where it will store the integer value, and you provide the address of arr[i].

String Array:

When dealing with a string array (an array of characters), you don't use the address-of operator & because a string in C is essentially an array of characters terminated by a null character '\0'.

To read a string into a character array, you typically use scanf like this: scanf("%s", arr[i]);. In this case, arr[i] itself acts as a pointer to the first character of the string, so you don't need the & operator.


*/

int intArr[5];
char strArr[5][20]; // Array of 5 strings, each with a maximum length of 19 characters

for (int i = 0; i < 5; i++) {
    printf("Enter an integer: ");
    scanf("%d", &intArr[i]); // Reading integers

    printf("Enter a string: ");
    scanf("%s", strArr[i]);  // Reading strings
}


/*

When reading an integer into an integer array, you generally use scanf like this: scanf("%d", &arr[i]);. This is because scanf expects a pointer to the variable where it will store the integer value, and you provide the address of arr[i]. why should i use & and the arr name points to the first integer element's address?

*/

int intArr[5];

for (int i = 0; i < 5; i++) {
    printf("Enter an integer: ");
    scanf("%d", &intArr[i]); // Correct usage, providing the address of intArr[i]
}

/*

So this only applies to strings, the rule that don't use & when reading strings and arrays of strings, only use & when reading in integers and integer arrays?

Yes, that's correct. The rule about not using the & operator when reading strings using scanf applies specifically to character arrays (arrays of characters) or arrays of strings.

For other data types like integers, floating-point numbers, or individual characters, you should use the & operator to provide the address of the variable where scanf should store the input value. This is consistent with how scanf works for these data types.

However, when you are reading a string into a character array or an array of strings (an array of character arrays), you don't use the & operator because the array itself is already a pointer to the first element of the array, which is a character in the case of strings. This is a specific behavior related to strings and character arrays in C.

======================================

Access Speed: Accessing array elements by pointer notation is typically faster than accessing them by subscript notation. This is because, in practice, the compiler often translates subscript notation into pointer notation before accessing the array elements.

When you want to use values from an array in C, you can do it in two ways: one using numbers like arr[0], arr[1], and so on, and the other using something called pointers, which are like shortcuts. Using pointers is often faster because the computer can understand them better.

======================================

Commutative Property: Array subscripting is commutative, meaning that arr[i] is equivalent to i[arr]. This might seem unusual but is true due to the equivalence between pointer arithmetic and array subscripting.

You know how in math, adding numbers is the same whether you write it as 2 + 3 or 3 + 2? Well, in programming, something similar happens with arrays. You can swap the order and write arr[i] or i[arr], and the computer is totally okay with it.

======================================

Equivalent Expressions: You correctly point out that arr[i] is equivalent to *(i + arr) in pointer notation, and it can also be written as i[arr] in subscript notation. This demonstrates the interchangeability of these notations when accessing array elements.

It's like saying "apple" or "fruit that's red and tasty." When you write arr[i], it's like saying "get me the i-th thing from the array called arr." But you can also say it differently as *(i + arr) in computer-speak. And guess what, you can even flip it and say i[arr]. They all mean the same thing - "give me that i-th thing from the array."

======================================

These insights are valuable for understanding how arrays and pointers work together in C and how array subscript notation and pointer notation can be used interchangeably in certain situations.

*/



int main3() {
    int arr[5] = {5, 10, 15, 20, 25};
    int i;

    for (i = 0; i < 5; i++) {
        printf("Value of arr[%d] = %d\t", i, arr[i]);
        printf("%d\t", *(arr + i)); // Using pointer notation
        printf("%d\t", *(i + arr)); // Another way using pointer notation
        printf("%d\n", i[arr]);     // Using a different way with subscript notation
        printf("Address of arr[%d] = %u\n", i, &arr[i]);
    }

    return 0;
}

/*

Explanation:

This program prints the values of array elements both using subscript notation (arr[i]) and pointer notation (*(arr + i) and *(i + arr)).

It also demonstrates that you can use different notations interchangeably to access array elements, which is a unique feature in C.

======================================

Output:


Value of arr[0] = 5   5   5   5
Address of arr[0] = 2000
Value of arr[1] = 10  10  10  10
Address of arr[1] = 2002
Value of arr[2] = 15  15  15  15
Address of arr[2] = 2004
Value of arr[3] = 20  20  20  20
Address of arr[3] = 2006
Value of arr[4] = 25  25  25  25
Address of arr[4] = 2008

======================================

Mine:

Value of arr[0] = 5     5       5       5
Address of arr[0] = 6422016
Value of arr[1] = 10    10      10      10
Address of arr[1] = 6422020
Value of arr[2] = 15    15      15      15
Address of arr[2] = 6422024
Value of arr[3] = 20    20      20      20
Address of arr[3] = 6422028
Value of arr[4] = 25    25      25      25
Address of arr[4] = 6422032

======================================

Explained:

Let's break down what you're seeing:

Value of arr[0]: This is the value of the 0th element of the array arr. It's displayed four times because there are four different ways to access it in the code:

arr[i]: Subscript notation
*(arr + i): Pointer notation
*(i + arr): Another pointer notation (it's commutative)
i[arr]: Subscript notation with the order swapped (also valid)
In this case, the value is 5.

Address of arr[0]: This is the memory address where the 0th element of the array arr is stored. It's displayed only once. The address is 6422016 in your case.

Value of arr[1]: Similar to the 0th element, this is the value of the 1st element of the array arr. It's displayed four times, like the 0th element. In this case, the value is 10.

Address of arr[1]: This is the memory address where the 1st element of the array arr is stored. It's displayed only once. The address is 6422020 in your case.

Value of arr[2]: This is the value of the 2nd element of the array arr, displayed four times. In this case, the value is 15.

Address of arr[2]: The memory address where the 2nd element of the array arr is stored, displayed only once. The address is 6422024 in your case.

Value of arr[3]: This is the value of the 3rd element of the array arr, displayed four times. In this case, the value is 20.

Address of arr[3]: The memory address where the 3rd element of the array arr is stored, displayed only once. The address is 6422028 in your case.

Value of arr[4]: This is the value of the 4th element of the array arr, displayed four times. In this case, the value is 25.

Address of arr[4]: The memory address where the 4th element of the array arr is stored, displayed only once. The address is 6422032 in your case.

The repetition of values is due to the different ways you're accessing the array elements in the code, and each access method results in the same value. However, the memory addresses are unique for each element and are displayed only once per element.

*/

/*

SUBSCRIPTING POINTER VARIABLES:

When we have a pointer variable ptr initialized with the address of the 0th element of an array, we can use pointer arithmetic and dereferencing to access array elements. Specifically:

The expression (ptr + i) represents the address of the ith element in the array.
The expression *(ptr + i) represents the value of the ith element in the array.

According to the principles of both pointer and subscript notations, *(ptr + i) can be written as ptr[i].

This means that if we have a pointer pointing to the 0th element of an array, we can access array elements using subscript notation.

This equivalence between pointer and subscript notations is useful, especially in dynamic arrays and when passing arrays to functions.

Now, let's clarify the relationship between the name of an array and a pointer variable:

The name of an array, when used in an expression, effectively points to the address of the 0th element of the array.

However, it's important to note that the name of an array is not a variable. It cannot be reassigned to point to a different address, nor can it be incremented or decremented like a pointer variable. It remains fixed at the address of the 0th element of the array.

This reformulation emphasizes the relationship between pointers and arrays, especially when accessing array elements, and also clarifies the immutability of the name of an array in this context.

*/

arr = &num; //illegal
arr++; //illegal
arr = arr - 1; //illegal

//But since ptr is a pointer variable, all these operations are valid for it.

ptr = &num; //now ptr points to variable num
ptr++; //ptr now points to the next location
ptr = ptr - 1; // *ptr points to the previous location

/*

Printing the Value and Address of Array Elements Using Subscripting and a Pointer Variable:

In this program, we have an integer array arr with values {5, 10, 15, 20, 25} and a pointer variable p initialized to point to the first element of the array.

*/

#include <stdio.h>

int main() {
    int arr[5] = {5, 10, 15, 20, 25};
    int i, *p;

    p = arr; // Pointer p is set to the address of arr[0]

    for (i = 0; i < 5; i++) {
        printf("Address of arr[%d] = %u %u %u %u\n", i, &arr[i], arr + i, p + i, &p[i]);
        printf("Value of arr[%d] = %d %d %d %d\n", i, arr[i], *(arr + i), *(p + i), p[i]);
    }

    return 0;
}



/*

Output Explanation:

This program prints the addresses and values of the array elements in various ways, using both subscripting (arr[i]) and pointer notation (*(arr + i) and *(p + i)).

It demonstrates that you can access elements in the array in equivalent ways, whether using subscripting or pointers.

The addresses printed for each element are the same, whether obtained through array indexing, pointer arithmetic, or the combination of both.

Similarly, the values printed for each element are also the same, regardless of the notation used.
This program showcases the equivalence between subscripting and pointer notation when accessing array elements and emphasizes that different notations yield the same results.

*/


































