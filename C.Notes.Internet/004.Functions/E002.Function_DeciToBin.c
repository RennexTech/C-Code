/**
 * 
 * The variable num in main is declared as a long int but the binary function's parameter is an int. This could
 * lead to data loss or incorrect results for large numbers. The logic in the binary function is correct for a
 * specific approach, but it assumes the binary representation will fit within a long int (which it won't for
 * large numbers). Also, there is a mismatch in the scanf and printf format specifiers.
 * 
 */

#include <stdio.h>
long int binary(int num);
int main()
{
    long int num;
    printf("Enter a number : \n");
    scanf("%ld", &num);
    printf("Decimal=%ld, Binary=%ld\n", num, binary(num));
    return 0;
}
long int binary(int num)
{
    int rem, a = 1, bin = 0;
    while (num > 0)
    {
        rem = num % 2;
        bin = bin + rem * a;
        num = num / 2;
        a *= 10;
    }
    return bin;
}


// =======================================================
// CORRECTED VERSION

/* Convert Decimal to Binary Number */

#include <stdio.h>

// This is the function prototype for our `binary` function. It tells the compiler
// that `binary` takes an integer as input and will return a `long long` integer.
// We're using `long long` to handle larger binary numbers, which can get very long.
long long int binary(int num);

int main()
{
    // `num` is a standard integer. It's what the user will input.
    int num;
    
    printf("Enter a number: \n");
    
    // We're reading the user's input and storing it in `num`.
    // The `%d` format specifier is used for an `int`.
    scanf("%d", &num);
    
    // We call our `binary` function, passing `num` to it. The function returns
    // the binary equivalent, which we then print.
    // We use `%lld` to print a `long long int`.
    printf("Decimal = %d, Binary = %lld\n", num, binary(num));
    
    return 0;
}

// This function takes a decimal number and converts it to its binary representation.
// It returns the result as a `long long int`.
long long int binary(int num)
{
    // Our variables.
    // `rem` will hold the remainder after division by 2.
    // `a` is our "place value multiplier." It starts at 1, then becomes 10, 100, 1000, etc.
    // `bin` will be our final binary number. We use `long long` to prevent overflow.
    int rem;
    long long int a = 1, bin = 0;
    
    // The `while` loop is the heart of the conversion. It keeps running as long as `num` is greater than 0.
    while (num > 0)
    {
        // Step 1: Find the remainder when the number is divided by 2. This gives us the last digit (bit)
        // of the binary number. For example, 13 % 2 = 1.
        rem = num % 2;
        
        // Step 2: Add this digit to our `bin` variable, in the correct place value.
        // For example, if `rem` is 1 and `a` is 10, we add 10 to `bin`.
        bin = bin + rem * a;
        
        // Step 3: Prepare for the next digit by dividing the number by 2.
        // For example, 13 / 2 = 6 (integer division).
        num = num / 2;
        
        // Step 4: Update the place value multiplier by multiplying it by 10.
        // `a` goes from 1 to 10, then 100, then 1000, and so on.
        a *= 10;
    }
    
    // Once the loop is done, `bin` holds the complete binary number.
    return bin;
}

