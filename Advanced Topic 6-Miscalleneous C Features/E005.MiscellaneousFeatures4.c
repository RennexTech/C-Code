/*

Let's break down the concept of functions with variable numbers of arguments (variadic functions) step by step:

Variadic Functions in C

In C, you can create functions that accept a variable number of arguments. These are called variadic functions. A classic example of such functions is printf and scanf, where you can pass different numbers and types of arguments.

How to Create Variadic Functions:

Include the header file stdarg.h, which provides the tools needed to work with variable arguments.

Define your function with an ellipsis (...) in the argument list. However, you must have at least one fixed argument before the ellipsis. For example:

*/


void func(char *str, int num, ...);

/*

In this example, func takes two fixed arguments (str and num) and can accept any number of additional arguments after that.

Inside your function, declare a variable of type va_list to manage the variable arguments. Conventionally, this variable is named ap.

va_list ap;

Initialize the va_list using the va_start macro. This sets it up to point to the first unnamed argument. You provide va_start with the va_list variable and the name of the last fixed argument.

va_start(ap, num);

Retrieve individual variable arguments using the va_arg macro. You specify the va_list variable and the data type of the argument you want to retrieve.

arg = va_arg(ap, datatype);

This macro returns the value of the current argument and increments the va_list pointer to the next argument.

After you're done using the variable arguments, call va_end to clean up. This macro sets the va_list pointer to NULL.

va_end(ap);

It's important to note that there's no built-in way to determine how many arguments were passed or what their types are. Typically, you rely on fixed arguments (like a format string) to convey this information.

In summary, variadic functions allow you to work with variable numbers and types of arguments, but you need to manage the va_list and use fixed arguments to communicate the expected format of the variable arguments.

================================

Let's break down the concepts of variadic functions and a custom print function step by step:

Variadic Functions in C.

Variadic functions in C are functions that can accept a variable number of arguments. They are defined using the stdarg.h library, which provides the va_list, va_start, va_arg, and va_end macros for working with these arguments.

Here's an example program demonstrating a variadic function:

*/
#include <stdarg.h>
#include <stdio.h>

int sum(int num, ...);

int main() {
    printf("Total %d\n", sum(2, 99, 68));
    printf("Total %d\n", sum(3, 11, 79, 32));
    printf("Total %d\n", sum(5, 23, 34, 45, 56, 78));
    return 0;
}

int sum(int num, ...) {
    int i;
    va_list ap;
    int arg, total = 0;

    va_start(ap, num);

    for (i = 0; i < num; i++) {
        arg = va_arg(ap, int);
        printf("%d ", arg);
        total += arg;
    }

    va_end(ap);

    return total;
}

/*

In this program, the sum function takes a variable number of integer arguments. It uses the va_list, va_start, and va_arg macros to access and sum these arguments.

Custom print Function

This program also includes a custom print function, which simulates some aspects of printf. It takes a format string and variable arguments of different types and prints them accordingly.

Here's the custom print function:

*/

void print(char *format, ...);

void print(char *format, ...) {
    char *p, *str;
    int k;
    float l;
    va_list ap;
    va_start(ap, format);

    for (p = format; *p != '\0'; p++) {
        if (*p == '%') {
            p++;
            switch (*p) {
                case 'b':
                    k = va_arg(ap, int);
                    i_to_str(k, str, 2);
                    fputs(str, stdout);
                    break;
                case 'd':
                    k = va_arg(ap, int);
                    i_to_str(k, str, 10);
                    fputs(str, stdout);
                    break;
                case 'o':
                    k = va_arg(ap, int);
                    i_to_str(k, str, 8);
                    fputs(str, stdout);
                    break;
                case 'x':
                    k = va_arg(ap, int);
                    i_to_str(k, str, 16);
                    fputs(str, stdout);
                    break;
                case 'c':
                    k = va_arg(ap, int);
                    putchar(k);
                    break;
                case 's':
                    str = va_arg(ap, char *);
                    fputs(str, stdout);
                    break;
                case 'f':
                    l = va_arg(ap, double);
                    f_to_str(l, str);
                    fputs(str, stdout);
                    break;
                case '%':
                    putchar('%');
                    break;
            }
        } else {
            putchar(*p);
        }
    }

    va_end(ap);
}


/*

This print function mimics some of the behavior of printf. It takes a format string with format specifiers (%d, %s, etc.) and uses va_arg to extract and print variable arguments of different types accordingly.

Note that the functions i_to_str and f_to_str are used to convert integers and floats to strings, respectively.

In summary, this program demonstrates variadic functions and a custom print function that can handle variable argument lists with different types and format specifiers.

-------------------------------------------

Let's expand on a few key concepts from the previous explanation:

Variadic Functions in C:

Variadic functions are functions that can accept a variable number of arguments.
They are defined using the stdarg.h library, which provides macros for handling variable arguments.

The main macros are:

va_list: A type to declare argument pointer variables.
va_start: Initializes the argument pointer variable.
va_arg: Retrieves the current argument and increments the argument pointer.
va_end: Cleans up after processing variable arguments.

Custom print Function:

The custom print function simulates aspects of printf by taking a format string and variable arguments.
It iterates through the format string, looking for format specifiers (e.g., %d, %s, %f) preceded by %.
For each format specifier found, it uses va_arg to extract the corresponding variable argument from the argument list.
The extracted argument is then printed according to the format specifier.

The print function handles various format specifiers such as:

%b for binary.
%d for decimal.
%o for octal.
%x for hexadecimal.
%c for characters.
%s for strings.
%f for floating-point numbers.
%% for printing a literal %.

Conversion Functions:

The program uses two additional functions: i_to_str and f_to_str.
i_to_str converts an integer to a string with a specified base (e.g., binary, decimal, hexadecimal).
f_to_str converts a floating-point number to a string.

Handling Negative Numbers:

The program doesn't handle negative numbers by default. To support negative numbers, you would need to add a conditional check and handle them accordingly.

Variable Argument Promotion:

In C, when variable arguments are passed, default argument promotions are applied:
Arguments of type char and short int are promoted to int.
Arguments of type float are promoted to double.
This affects the way you retrieve and handle variable arguments inside a variadic function.

Use of va_start and va_end:

You must always use va_start to initialize the argument pointer before accessing variable arguments.

It's crucial to use va_end to clean up after processing variable arguments. Once va_end is called, you can't access variable arguments again without reinitializing.
Format String:

The format string is crucial for the print function to interpret how to print the variable arguments correctly. It specifies the type and order of expected arguments.

Putting It All Together:

The provided code demonstrates how to create a custom print function that can handle variable arguments of different types and format specifiers, making it a flexible tool for formatted output.


*/



















