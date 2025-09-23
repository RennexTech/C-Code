#include <stdio.h>
#include <math.h>

// Function prototype for the `printprimes` function. It takes two integers and doesn't return a value.
void printprimes(int num1, int num2);

// Function prototype for the `isprime` function. It takes an integer and returns an integer.
int isprime(int n);

int main()
{
    int num1, num2;
    printf("Enter two numbers: \n");
    scanf("%d%d", &num1, &num2);
    
    printf("Prime numbers between %d and %d are: \n", num1, num2);
    printprimes(num1, num2);

    return 0;
}

// This function iterates through a range of numbers and prints those that are prime.
void printprimes(int num1, int num2)
{
    // The `for` loop goes from the first number to the second, checking each one.
    for (int i = num1; i <= num2; i++) {
        // We call our `isprime` function to check if the current number is prime.
        if (isprime(i)) {
            // If `isprime` returns 1 (true), we print the number.
            printf("%d\n", i);
        }
    }
}

// This function determines if a number is prime. It's a key part of the program's logic.
int isprime(int n)
{
    // The number 1 is a special case; by definition, it's not a prime number.
    if (n <= 1) {
        return 0;
    }

    // A prime number is only divisible by 1 and itself. We check for divisibility
    // starting from 2 up to the square root of the number.
    // Why the square root? 
    // If a number has a divisor larger than its square root, it must also have a
    // divisor smaller than its square root. So, we only need to check up to the square root to find all potential divisors.
    for (int i = 2; i <= sqrt(n); i++) {
        // The modulo operator (`%`) gives the remainder of a division.
        // If the remainder is 0, the number is evenly divisible by `i`,
        // meaning it's not prime. We return 0 (false) immediately.
        if (n % i == 0) {
            return 0;
        }
    }
    
    // If the loop finishes without finding any divisors, the number is prime. We return 1 (true).
    return 1;
}