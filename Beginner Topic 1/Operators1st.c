#include <stdio.h>
#include <stdlib.h>

/*

This is where i build the fully working calculator for doing stuffs.
Make sure your functions are on top of main, no function should be below main or compiler will give errors.



void addition()
{
    printf("Welcome to addition.\n");
    int num;
    int i; //for looping 10 inputs
    double sum = 0.0;
    int choice_addition;

    printf("Enter 10 numbers to add: \n");
    for(i =0; i < 10; i++)
    {
        scanf("%d", &num);
        sum += num;
    }
    printf("The sum is: %.2lf\n", sum);
    printf("Do you want to continue adding? 1.yes\n 2.no\n");
    switch(choice_addition)
    {
    case 1:
        goto addition();
        break;
    case 2:
        printf("Exiting calculator.");
        //how do i exit from this calculator and go back to main?
        goto main();
    }
}
=================================================

The line while (getchar() != '\n') continue; is used to clear the input buffer (stdin) after an invalid input is detected. Let me break down how it works:

getchar() is a function that reads a single character from the input stream (in this case, the standard input, which is typically the keyboard).

getchar() != '\n' checks if the character read is not a newline character ('\n'). A newline character is typically entered when the user presses the Enter key, indicating the end of input for a line.

continue; is a control flow statement that tells the program to skip the rest of the current loop iteration and move to the next iteration. It essentially continues to the next loop iteration.

So, when getchar() detects a character that is not a newline character, it means there is additional input in the buffer (such as extra characters or invalid input). The while loop continues to read characters and discard them until a newline character ('\n') is encountered, effectively clearing the input buffer.

This is often used after a failed input attempt to ensure that any remaining invalid input or extra characters are removed from the input buffer before the program proceeds to the next input operation.



======================================

In the program you provided, sum += num; is a line of code within the addition function, and it's used to accumulate (add up) the numbers entered by the user.

Here's how it works within the context of the program:

sum is a double-precision floating-point variable that is initialized to 0.0 at the start of each iteration of the loop.

num is an integer variable where the user's input is stored. The program reads two integer inputs from the user and adds them to num.

sum += num; is a compound assignment operator that adds the value of num to the current value of sum. It is equivalent to writing sum = sum + num;. So, sum keeps accumulating the numbers entered by the user during each iteration of the loop.

The loop iterates twice (as specified by for (i = 0; i < 2; i++)) to get two integer inputs from the user and add them to sum. The result is the sum of the two numbers.

After the loop, totalSum (initialized to 0.0) is updated by adding sum to it. This means that totalSum keeps a cumulative sum of all the numbers entered by the user in multiple iterations of the loop.

So, sum += num; is used to update the sum of the numbers entered by the user during each iteration of the loop, and totalSum keeps track of the cumulative sum of all these additions as the user continues to input numbers.

=======================================

*/

#include <stdio.h>
#include <stdio.h>

#include <stdio.h>

void addition()
{
    printf("\n");
    printf("---------------------------------------------\n");
    printf("Welcome to addition.\n");
    printf("---------------------------------------------\n");
    int num;
    int i; // for looping 2 inputs
    double sum = 0.0;
    double totalSum = 0.0; // To store the cumulative sum of all additions
    int choice_continue = 1; // Initialize to 1 for the initial loop
    int choice_reset = 1;    // Initialize to 1 for the initial loop

    while (choice_continue == 1) {
        if (choice_reset == 1) {
            sum = 0.0; // Reset the sum for a new addition
        }

        printf("Enter 2 numbers to add:\n");
        for (i = 0; i < 2; i++) {
            if (scanf("%d", &num) != 1) {
                printf("---------------------------------------------\n");
                printf("Invalid input! Please enter a valid number.\n");
                printf("---------------------------------------------\n");
                printf("\n");
                while (getchar() != '\n') continue; // Clear input buffer
                i--; // Decrement i to retry input for this iteration
                continue;
            }
            sum += num;
        }

        totalSum += sum; // Add the current sum to the total

        printf("The sum is: %.2lf\n", totalSum);

        printf("Do you want to continue adding? \n");
        printf("1. Yes\n");
        printf("2. No: ");
        if (scanf("%d", &choice_continue) != 1 || (choice_continue != 1 && choice_continue != 2)) {
            printf("---------------------------------------------\n");
            printf("Invalid choice! Please enter 1 for Yes or 2 for No.\n");
            printf("---------------------------------------------\n");
            while (getchar() != '\n') continue; // Clear input buffer
            choice_continue = 1; // Default to continue on invalid input
        }

        if (choice_continue == 1) {
            printf("---------------------------------------------\n");
            printf("Do you want to continue from the last result or start a new addition?\n");
            printf("---------------------------------------------\n");
            printf("\n1. Continue from last result\n");
            printf("\n2. Start a new addition: \n");
            if (scanf("%d", &choice_reset) != 1 || (choice_reset != 1 && choice_reset != 2)) {
                printf("\nInvalid choice! Please enter 1 to continue from the last result or 2 to start a new addition.\n");
                while (getchar() != '\n') continue; // Clear input buffer
                choice_reset = 1; // Default to continue from the last result on invalid input
            }
            if (choice_reset == 2) {
                totalSum = 0.0; // Reset the total sum for a new addition
            }
        }
    }

    printf("---------------------------------------------\n");
    printf("Exiting calculator.\n");
    printf("---------------------------------------------\n");
}




void subtraction()
{
    printf("Welcome to subtraction. Enter the 10 numbers you want to subtract: \n");

}


void division()
{
    printf("Welcome to division: \n");

}

void modulus()
{
    printf("Welcome to modulus: \n");

}

void multiplication()
{
    printf("Welcome to multiplication \n");

}

int main()
{

    int choice;
    while (1)
    {
        printf("What operation do you want to do? Enter your choice(1 to 5):\n");
        printf("1. Addition\n");
        printf("2. Subtraction\n");
        printf("3. Multiplication\n");
        printf("4. Division\n");
        printf("5. Modulus\n");
        printf("--------------------------\n");

        if (scanf("%d", &choice) == 1 && choice >= 1 && choice <= 5)
        {
            printf("--------------------------\n");
            printf("Success!\n");
            printf("--------------------------\n");
            break; // Break the loop only when valid input is provided
        }
        else
        {
            printf("Please enter a valid choice, 1 to 5.\n");
            // Clear the input buffer to remove any remaining characters
            while (getchar() != '\n')
                continue;
        }
    }

    switch(choice)
    {
    case 1:
        addition();
        break;
    case 2:
        subtraction();
        break;
    case 3:
        multiplication();
        break;
    case 4:
        division();
        break;
    case 5:
        modulus();
        break;
    default:
        printf("---------------------------------------------------\n");
        printf("You entered an invalid choice! Only 1 to 5 allowed!\n");
        printf("---------------------------------------------------\n");
    }
    return 0;
}

/*

In the main, we have done the scanf trick to allow us to only take integers.

It uses scanf to attempt to read an integer from the user input and store it in the choice variable.

The condition (scanf("%d", &choice) != 1 checks whether scanf successfully read an integer. If scanf returns 1, it means that an integer was successfully read. If it returns something other than 1 (e.g., 0 or EOF), it indicates that the input wasn't a valid integer.

If scanf doesn't return 1, the condition choice < 1 || choice > 5 is not evaluated because the || operator is short-circuiting. In other words, if the first part of the condition is true (indicating a failed scanf), the second part won't be evaluated.

If scanf fails (returns something other than 1) or if the entered integer is not within the range of 1 to 5, it displays an error message ("Please enter a valid choice, 1 to 5.") and returns 1, indicating an error condition to the calling function (main in this case).

So, this code ensures that scanf only takes an integer and, in addition, checks if the entered integer is within the specified range of 1 to 5. If the input is not a valid integer or is outside the valid range, it provides an error message and returns an error code (1) to signal the problem.


===========================

The expression scanf("%d", &choice) == 1 is a condition that checks the result of the scanf function call. Here's what it means:

scanf("%d", &choice) is a call to the scanf function, which is used for input in C. In this case, it's trying to read an integer from the user's input and store it in the variable choice (provided as &choice to pass its address).

== 1 is a comparison operator that checks if the result of the scanf function call is equal to 1. In C, scanf returns the number of successfully scanned items, so if it successfully reads an integer from the input, it returns 1. If it fails to read an integer, it returns a value less than 1.

So, scanf("%d", &choice) == 1 is a condition that evaluates to true if scanf successfully reads an integer from the input and false if it fails to do so. It's commonly used to check if the input operation was successful.



*/
