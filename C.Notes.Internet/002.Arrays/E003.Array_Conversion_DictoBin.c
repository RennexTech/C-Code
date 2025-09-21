#include <stdio.h>

int main()
{
    // These are our variables.
    // `num` will store the decimal number the user enters.
    // `arr[15]` is an array to store the binary digits (either 0 or 1). We'll use this
    // to build the binary number.
    // `i` and `j` are just loop counters.
    int num, arr[15], i, j;

    // We're asking the user to give us a whole number.
    printf("Enter a decimal number: ");

    // `scanf` reads the number the user types and stores it in the `num` variable.
    // The `&` symbol means "give me the memory address of `num`." This tells `scanf`
    // exactly where to put the number it reads.
    scanf("%d", &num);

    // We're setting our counter `i` to 0. This will be the index for our `arr` array.
    i = 0;

    // This `while` loop is the core of our decimal-to-binary conversion. It keeps running
    // as long as the number (`num`) is greater than 0.
    while (num > 0)
    {
        // This is the first step of the conversion: finding the remainder when `num` is divided by 2.
        // This remainder will always be either 0 or 1, which is exactly what we need for a binary number.
        // We store this result in our array `arr` at the current position `i`.
        arr[i] = num % 2;

        // This is the second step: dividing the number by 2. This prepares the number for the next loop.
        // The integer division automatically discards any remainder.
        num = num / 2;

        // We increment `i` so that the next binary digit will be stored in the next position in the array.
        i++;
    }

    // Now that we've collected all the binary digits, we need to print them.
    printf("Binary Number is: ");

    // The `while` loop filled the array with the digits in **reverse order**.
    // The first digit we found (the remainder of the first division) is the least significant bit,
    // but in a binary number, we write it last. So, we need to loop backwards to print
    // the digits in the correct order.
    for (j = i - 1; j >= 0; j--)
    {
        // This prints the digit from our array.
        printf("%d", arr[j]);
    }
    
    // This prints a new line to make the output clean.
    printf("\n");
    
    return 0;
}