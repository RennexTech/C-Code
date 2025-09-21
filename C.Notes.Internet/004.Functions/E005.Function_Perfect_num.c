#include <stdio.h>

// This is the function prototype for `isPerfect`. It tells the compiler that we have
// a function that takes one integer (`num`) and returns an integer.
int isPerfect(int num);

int main()
{
    // We declare a variable to hold the number the user enters.
    int num;

    // We prompt the user for input and store it in the `num` variable.
    printf("Enter an integer number: ");
    scanf("%d", &num);

    // We call our `isPerfect` function. The function returns 1 for true (it is perfect)
    // or 0 for false (it is not). Based on the result, we print a message.
    if (isPerfect(num))
    {
        printf("%d is a perfect number.\n", num);
    }
    else
    {
        printf("%d is not a perfect number.\n", num);
    }

    return 0;
}

// This function checks if a number is a perfect number.
int isPerfect(int num)
{
    // We'll use `i` as our loop counter and `sum` to accumulate the sum of the divisors.
    int i, sum = 0;

    // A perfect number must be a positive integer. We handle this check first.
    if (num <= 0) {
        return 0;
    }
    
    // We loop from 1 up to (but not including) the number itself.
    // We're looking for all the number's proper divisors.
    for (i = 1; i < num; i++)
    {
        // The modulo operator (`%`) gives us the remainder of a division.
        // If the remainder is 0, it means `i` is a divisor of `num`.
        if (num % i == 0)
        {
            // If `i` is a divisor, we add it to our running `sum`.
            sum = sum + i;
        }
    }

    // Finally, we check our condition. A number is perfect if the sum of its
    // proper divisors is equal to the number itself.
    // If they match, we return 1 (true).
    if (sum == num)
        return 1;
    // Otherwise, we return 0 (false).
    else
        return 0;
}