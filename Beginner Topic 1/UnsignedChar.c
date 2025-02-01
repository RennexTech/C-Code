#include <stdio.h>
#include <stdlib.h>

/*
A character can store a string, but it can also store a number.
The ASCII character set, which is the most common character set used
in computers, assigns a unique number to each character.
For example, the character 'A' is assigned the number 65.

An unsigned char can store a number from 0 to 255.
This is because a byte is 8 bits long, and an unsigned char uses
all 8 bits to store a number. The smallest number that an unsigned
char can store is 0, which is represented by all 8 bits being 0.
The largest number that an unsigned char can store is 255,
which is represented by all 8 bits being 1.

So, an unsigned char can store a string,
but it can also store a number from 0 to 255.
The way that you use an unsigned char depends on the context
in which you are using it.


*/

int main()
{
    //To store a string
    char str[10];
    strcpy(str, "Hello World!");
    printf("The string stored is: %s\n", str); // no need for addresses when using arrays.
    printf("The size of string is: %d\n", sizeof(str)); // i dont know if it will work

    //store a single character
    char letter = 'A';
    printf("The letter is: %c\n", letter);
    printf("The size of letter is: %d\n", sizeof(letter));

    //store numbers
    unsigned char number = 65;
    printf("The ASCII value for A is: %d\n", number);
    printf("The size of number is: %d\n", sizeof(number));
    return 0;
}

/*

When you use an array in C, you do not need to specify the address
of the array when you pass it to a function. The reason for this is
that the compiler knows the address of the array when it is declared.

In the code you provided, the printf() function expects a string
as its argument. The str variable is an array of characters,
so it is a string. The compiler will automatically pass the address
of the first element of the array to the printf() function.

Why is the size of array 10 for me?
and hello world! has a space, isn't that considered,
and the sentinel or null character is also there,
is it not occupying space?

The size of the array is 10 because you declared
the array with a size of 10. The str array can store
10 characters, including the space and the null character.

The null character is a special character
that is used to mark the end of a string.
It is represented by the ASCII code 0.
The sizeof() function does not count the null
character when calculating the size of an array.

Therefore, the size of the str array is 10,
even though the string "Hello World!" has 11 characters.

Here is a more detailed explanation of what is happening:

You declared the str array with a size of 10 characters.
The str array can store 10 characters, including the space
and the null character.
The sizeof() function does not count the null character
when calculating the size of an array.
Therefore, the size of the str array is 10, even though
the string "Hello World!" has 11 characters.

  */
