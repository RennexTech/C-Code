#include <stdio.h>

// This is the function prototype. It tells the compiler that we have a function
// named `product` that takes an integer and returns an integer.
int product(int num);

int main()
{
    // Declaring our variables. `num` will store the number from the user,
    // and `prod` will store the final product of its digits.
    int num, prod;

    // Prompting the user to enter a number and then reading that number.
    printf("Enter a number: \n");
    scanf("%d", &num);

    // We call our `product` function, passing the user's number to it.
    // The result is stored in the `prod` variable.
    prod = product(num);

    // Finally, we print the result.
    printf("%d\n", prod);

    return 0;
}

// This function calculates the product of the digits of a given number.
int product(int num)
{
    // `rem` will store the remainder, which is the last digit of the number.
    // `prod` is our running product, initialized to 1. We use 1 because
    // multiplying by 0 would make the result always 0.
    int rem, prod = 1;

    // This `while` loop is the core of the algorithm. It keeps running as long as the
    // number is not equal to 0.
    while (num != 0)
    {
        // Step 1: `num % 10` gives us the last digit of the number.
        // For example, if `num` is 123, `123 % 10` equals 3. 
        rem = num % 10;
        
        // Step 2: We multiply our current product by this last digit.
        prod = prod * rem;

        // Step 3: We get rid of the last digit by performing integer division.
        // `num / 10` effectively "chops off" the last digit.
        // For example, if `num` is 123, `123 / 10` equals 12.
        num = num / 10;
    }
    
    // Once the loop is done, `prod` holds the product of all the digits.
    return prod;
}

// Small, consistent progress beats grand, rare efforts.

