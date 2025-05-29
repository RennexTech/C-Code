#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#import <math.h>

double main()
{
    /*

    I used double for main function and it run.
    Your program will still run if you have two main() functions.
    However, this is not recommended because it can lead to unexpected behavior.
    The main() function is the entry point of a C program.
    It is the first function that is executed when the program starts.
    There can only be one main() function in a C program.
    If you have two main() functions, the compiler will only choose one of them to be the entry point of the program.
    The other main() function will never be executed.
    The behavior of the program will depend on which main() function the compiler chooses.
    If the compiler chooses the first main() function, the program will run as expected.
    However, if the compiler chooses the second main() function, the program will not run as expected.
    To avoid this problem, it is best to avoid using two main() functions in a C program.
    If you need to have multiple entry points to your program, you can use function pointers.
    Unary operators operate on a single operand.
    The only unary arithmetic operator in C is the unary minus (-) operator, which negates the operand.
    For example, the expression -x is equivalent to x * -1.
    Binary operators operate on two operands.
    The five binary arithmetic operators in C are:

    Addition (+)
    Subtraction (-)
    Multiplication (*)
    Division (/)
    Modulus (%)

    Operand is the data we are working on eg 2, 3
    prdouble("This is a unary operator: +y , -x");

    */
    int main_choice;

    printf("----------------------------------\n");
    printf("WELCOME TO MY TINY CALCULATOR.\n");
    printf("This is an infinite calculator, you just take the former result and put it as the new number and your math continues\n.");
    printf("----------------------------------\n");
    printf("\n");
    printf("What would you like to do?\n");
    printf("\n");
    printf("1. Addition\n");
    printf("2. Subtraction\n");
    printf("3. Multiplication\n");
    printf("4. Division\n");
    printf("5. Modulus\n");
    printf("6. Decimal Point Modulus\n");

    printf("\n");
    scanf("%d", &main_choice);

    while(1)
    {
        switch(main_choice)
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
            case 6:
                floating_point_modulus();
            default:
                sleep(2);
                printf("You didn't supply any value. Exiting calculator...\n");
                exit(1);

        }
    }


}

/*

In this example, the array numbers is declared to be of size 100. This means that it can store up to 100 doubleegers. The variable n is used to store the number of inputs that the user wants to enter.

The for loop is used to read the numbers from the user. The loop iterates for n times, and each time it reads a number from the user and stores it in the array numbers at index i.

The sum variable is used to store the sum of the numbers. The for loop is used to calculate the sum of the numbers. The loop iterates for n times, and each time it adds the number at index i to the sum.

The printf() function is used to prdouble the sum of the numbers.

This is just one way to take in an infinite number of inputs in C. There are other ways to do it, and the best way will depend on your specific needs.

I hope this helps!




void addition()
{
    double sum, i, n;
    double numbers[100]; //for looping so we can store a lot of numbers that the user enters

    printf("\n");
    printf("Welcome to addition!");
    printf("\n");
    printf("How many numbers do you want to add?\n");
    scanf("%lf", &n);

    //Read the numbers from teh user
    for(i = 0; i < n; i++)
    {

        printf("Enter number %lf: ", i+1);
        scanf("%lf\n", &numbers[i]);

    }

    //Do the summation
    sum = 0;
    for(i = 0; i < n; i++)
    {
        sum += numbers[i];
    }

    //Prdouble the sum
    printf("The sum is %lf\n", sum);



}*/


void addition()
{

    double addition_result, add1, add2;
    printf("Enter first number: \n");
    scanf("%lf", &add1);
    printf("Enter second number: \n");
    scanf("%lf", &add2);
    addition_result = add1 + add2;
    printf("The result is: %lf\n", addition_result);

}
void subtraction()
{
    double subtraction_result, sub1, sub2;
    printf("Enter first number: \n");
    scanf("%lf", &sub1);
    printf("Enter second number: \n");
    scanf("%lf", &sub2);
    subtraction_result = sub1 - sub2;
    printf("The result is: %lf\n", subtraction_result);
}

void multiplication()
{
    double multiplication_result, mul1, mul2;
    printf("Enter first number: \n");
    scanf("%lf", &mul1);
    printf("Enter second number: \n");
    scanf("%lf", &mul2);
    //how do i prevent scanf from taking in an input that is not a number?
    multiplication_result = mul1 * mul2;
    printf("The result is: %lf\n", multiplication_result);

}

void division()
{
    double division_result_quotient, div1, div2;
    printf("Enter first number(dividend): \n");
    scanf("%lf", &div1);
    printf("Enter second number(divisor/bottom number): \n");
    scanf("%lf", &div2);
    division_result_quotient = div1 / div2;
    printf("The result is: %lf\n", division_result_quotient);
}

/*

Yes, the modulus operator (%) only works with integers. If you use the modulus operator with floating-point numbers, the result will be undefined.

The modulus operator returns the remainder of the division of the first operand by the second operand. For example, the expression 10 % 3 is equal to 1, because 10 divided by 3 is 3 with a remainder of 1.

If you try to use the modulus operator with floating-point numbers, the result will be undefined because floating-point numbers can have decimal places. For example, the expression 10.0 % 3.0 is undefined because 10.0 divided by 3.0 is 3.333333333333333 with a remainder of 0.0.

The reason why the modulus operator only works with integers is because the remainder of a division operation is always an integer. When you divide two integers, the remainder is the difference between the dividend and the product of the divisor and the quotient. The quotient is always an integer, so the remainder must also be an integer.

If you need to calculate the remainder of a division operation involving floating-point numbers, you can use the fmod() function. The fmod() function returns the floating-point remainder of the division of the first operand by the second operand.

*/

void modulus()
{
    printf("Here, modulus only works with integers not decimal point numbers.\n");
    int modulus_result, mod1, mod2;
    printf("Enter first number(dividend/top): \n");
    scanf("%d", &mod1);
    printf("Enter second number(divisor/bottom): \n");
    scanf("%d", &mod2);
    modulus_result = mod1 % mod2;
    printf("The result is: %d\n", modulus_result);

}

void floating_point_modulus()
{
    printf("---------------------------------\n");
    printf("Enter floats or doubles like 2.0000 not integers eg 2, or you won't get the answer.\n");
    printf("Do you know what this is for? We are checking for remainder after division, so if you see the result is 0, that's the remainder after dividing your numbers.\n");
    printf("---------------------------------\n");

    float floating_mod_result, float_mod1, float_mod2;
    printf("Enter the dividend(top) as a float/decimal: \n");
    scanf("%f", &float_mod1);
    printf("Enter the divisor(bottom) as a float/decimal: \n");
    scanf("%f", &float_mod2);
    floating_mod_result = fmod(float_mod1, float_mod2);
    printf("Your result is: %f\n", floating_mod_result);

}

//we can also call the functions with arguments eg floating_point_modulus(int float_mod1, int float_mod2);
//make sure you import math.h header to use fmod to find modulus of floats or doubles.
