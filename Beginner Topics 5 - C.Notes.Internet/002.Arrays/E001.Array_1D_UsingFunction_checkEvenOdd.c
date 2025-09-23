#include <stdio.h>

// This is the function prototype. It tells the compiler about the `check` function
// before it's used in `main`. It says: "Hey, there's a function named `check` that
// takes one integer (`int num`) and doesn't return anything (`void`)."
void check(int num);

// This is the main function, where our program starts.
int main(void)
{
    // We're declaring an array named `arr` that can hold 10 integers.
    int arr[10];

    // This `for` loop will run 10 times, once for each element of the array.
    for (int i = 0; i < 10; i++)
    {
        // This line asks the user to input a number.
        printf("Enter an array element: ");
        
        // This line reads the integer entered by the user and stores it in the
        // current position of the array (`arr[i]`). The `&` is used to get the
        // memory address of that array element, so `scanf` knows where to store the data.
        scanf("%d", &arr[i]);
        
        // This is a function call. We're passing the number the user just entered
        // (the value of `arr[i]`) to the `check` function to see if it's even or odd.
        check(arr[i]);
    }

    return 0;
}

// This is the `check` function itself. It's like a small, separate program
// that performs a specific task. Its job is to figure out if a number is even or odd.
void check(int num)
{
    // The `%` is the modulo operator. `num % 2` calculates the remainder when `num` is
    // divided by 2.
    
    // If the remainder is 0, the number is evenly divisible by 2, so it's even.
    if (num % 2 == 0)
    {
        printf("Even\n");
    }
    // Otherwise, if the remainder is anything else (in this case, 1), the number is odd.
    else
    {
        printf("Odd\n");
    }
}