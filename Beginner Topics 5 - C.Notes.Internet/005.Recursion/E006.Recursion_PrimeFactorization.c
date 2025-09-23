/* The recursive function for printing the prime factors of a number */

#include <stdio.h>

// This is the function prototype for `pFactors`. It tells the compiler about the function
// which takes an integer and doesn't return a value.
void pFactors(int num);

int main()
{
    // We declare a variable `num` to hold the number the user enters.
    int num;

    printf("Enter a positive integer: ");
    scanf("%d", &num);
    
    // We add a check for valid input, as prime factorization is for numbers greater than 1.
    if (num <= 1) {
        printf("Prime factorization is not defined for numbers less than or equal to 1.\n");
        return 1;
    }
    
    printf("The prime factors of %d are: ", num);
    
    // We call our `pFactors` function to do the work.
    pFactors(num);
    
    printf("\n"); // Print a newline for clean output.

    return 0;
}

// This function finds and prints the prime factors of a number using recursion.
void pFactors(int num)
{
    // `i` is our potential prime factor, starting from 2.
    int i = 2;
    
    // This is the **base case**. When `num` is reduced to 1, we have found all
    // the factors, and the recursion stops.
    if (num == 1)
        return;
    
    // This `while` loop finds the smallest prime factor of the current `num`.
    // It keeps incrementing `i` until it finds a number that evenly divides `num`.
    while (num % i != 0)
    {
        i++;
    }
    
    // Once a factor is found, we print it.
    printf("%d ", i);
    
    // This is the **recursive step**. We call the `pFactors` function again with
    // the new number (`num / i`). This breaks the problem down into a smaller part.
    // The next recursive call will find the smallest prime factor of the new, smaller number.
    pFactors(num / i);
    
    return;
}


/*

What is Prime Factorization?

Prime factorization is the process of breaking down a composite number into its prime factors.  

A prime number is a number greater than 1 that has only two divisors: 1 and itself. 

Every composite number can be written as a unique product of prime numbers.

For example, the prime factorization of 12 is 2×2×3.

The Analogy: A Chain of Division 🔗

Imagine you have a number, say 12, and you want to find its prime factors. The recursive function works like a machine that performs a chain of divisions:

First Call: pFactors(12)

The machine starts checking for a divisor, beginning with 2.

It finds that 12÷2=6 with no remainder.

It prints 2 and then calls itself with the new number, 6: pFactors(6).

Second Call: pFactors(6)

The new machine starts checking for a divisor, beginning with 2.

It finds that 6÷2=3 with no remainder.

It prints 2 and then calls itself with the new number, 3: pFactors(3).

Third Call: pFactors(3)

The new machine starts checking for a divisor, beginning with 2.

It finds that 3 % 2 is not 0, so it increments its check to 3.

It finds that 3÷3=1 with no remainder.

It prints 3 and then calls itself with the new number, 1: pFactors(1).

Base Case: pFactors(1)

The final machine gets the number 1.

The base case is triggered. It returns without doing anything, and the chain of recursive calls ends.

The program's output will be the numbers printed in each step of this chain: 2 2 3.

*/