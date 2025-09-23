/*

Conditional compilation in C allows you to include or exclude parts of your code during the compilation process based on certain conditions. This is done using preprocessor directives, and it's a powerful way to customize your program for different situations. Let's break down the key directives involved:

#if and #endif: The #if directive is used to evaluate a constant expression. If the expression evaluates to non-zero (true), the code between #if and the corresponding #endif is compiled. Otherwise, that code is excluded from compilation.
#endif // and

*/


#if constant-expression
// Code to include if the expression is true
#endif



/*
In your example, #if FLAG >= 3 checks if the value of FLAG is greater than or equal to 3. If true, the code between #if and #endif is compiled.

#ifdef and #ifndef: These directives are used to check if a particular macro is defined (#ifdef) or not defined (#ifndef).


#endif // andIf the macro is defined (#ifdef) or not defined (#ifndef), the associated code is included for compilation.
*/

#ifdef macro
// Code to include if the macro is defined
#endif

#ifndef macro
// Code to include if the macro is not defined
#endif


/*
For example, #ifdef DEBUG checks if the macro DEBUG is defined.

#else and #elif: These directives provide alternative code paths. If the condition in an #if or #ifdef directive is false, you can provide an alternative code block using #else or #elif (short for "else if").
*/

#if constant-expression
// Code to include if the expression is true
#else
// Code to include if the expression is false
#endif

#ifdef macro
// Code to include if the macro is defined
#else
// Code to include if the macro is not defined
#endif


/*
This allows you to provide different code paths depending on the condition.

In your example program, when FLAG is defined as 8, the constant expression FLAG >= 3 is true, so the code between #if and #endif is compiled. If you change FLAG to 2, the constant expression becomes false, and the code between #if and #endif is skipped during compilation.

Conditional compilation is useful for scenarios where you want to include or exclude code based on build configurations, debugging options, or platform-specific requirements. It allows you to tailor your code to different situations without having to manually comment out or modify sections of your source code.

=============================================

I see that you've given a code snippet that uses the #if directive to conditionally compile certain parts of the code based on the value of the FLAG macro.

Here's the code you provided:


*/

/*P12.14 Program to understand the use of #if directive*/
#include<stdio.h>
#define FLAG 8

main( ) {
    int a=20, b=4;

    #if FLAG >= 3
    printf("Value of FLAG is greater than or equal to 3 \n");
    a = a + b;
    b = a * b;
    printf("Values of variables a and b have been changed\n");
    #endif

    printf("a = %d, b = %d\n", a, b);
    printf("Program completed\n");
}


/*
This code uses the #if directive to check if the value of the FLAG macro is greater than or equal to 3. If the condition is true, it compiles the code within the #if and #endif blocks. Otherwise, it skips that code during compilation.

The output of this code will depend on the value of FLAG. In your provided code, FLAG is defined as 8, so the condition is true, and the statements within the #if block are compiled. If you change the value of FLAG to 2, for example, the code within the #if block will not be compiled.

=========================================

Here's an explanation of the code you provided that uses #else and #elif directives for conditional compilation:

*/

/*P12.15 Program to understand the use of #else directive*/
#include<stdio.h>
#define FLAG 2

main( ) {
    int a = 20, b = 4;

    #if FLAG >= 3
    printf("Value of FLAG is greater than or equal to 3\n");
    a = a + b;
    b = a * b;
    #else
    printf("Value of FLAG is less than 3\n");
    a = a - b;
    b = a / b;
    #endif

    printf("a = %d, b = %d\n", a, b);
    printf("Program completed\n");
}


/*
In the above code, the FLAG macro is defined as 2. Let's break down how the conditional compilation works:

The code starts with an #if directive that checks if FLAG >= 3. Since FLAG is 2 (less than 3), the compiler skips the statements between #if and #else.

The code inside the #else block is compiled because the previous condition was not met. It prints "Value of FLAG is less than 3" and performs some calculations on variables a and b.

Finally, after the conditional blocks, the code outside the #endif is always compiled. It prints the values of a and b and the message "Program completed."

As a result, when FLAG is set to 2, the program will output:

Value of FLAG is less than 3
a = 16, b = 4
Program completed

The #elif directive can be used to specify additional conditions, and the first true condition encountered will execute its corresponding block of code. If none of the conditions is true, the code inside the #else block will execute.

==============================================

Here's an explanation of the code that uses #ifdef, #ifndef, #undef, and the defined operator in conditional compilation:

*/

/*P12.17 Program to understand the use of #ifdef directive*/
#include <stdio.h>
#define FLAG

main( ) {
    int a = 20, b = 4;

    #ifdef FLAG
    printf("FLAG is defined\n");
    a++;
    b++;
    #endif

    printf("a = %d, b = %d\n", a, b);
    printf("Program completed\n");
}


/*
In the above code, the macro FLAG is defined at the beginning using #define FLAG. Here's how the program works:

The code starts with the #ifdef FLAG directive, which checks if the macro FLAG has been defined. Since FLAG is defined at the beginning of the program, the statements between #ifdef and #endif are compiled.

Inside the block, it prints "FLAG is defined" and performs some arithmetic operations on variables a and b.

After the conditional block, the code continues to execute, printing the updated values of a and b, as well as "Program completed."

As a result, because FLAG is defined, the program will output:

FLAG is defined
a = 21, b = 5
Program completed

==================================================

Now, let's look at another example where the macro is undefined using #undef:

*/

/*P12.18 Program to understand the use of #undef and #ifdef directives*/
#include <stdio.h>
#define FLAG

main( ) {
    int a = 20, b = 4;

    #ifdef FLAG
    printf("FLAG is defined\n");
    a++;
    b++;
    #endif

    #undef FLAG

    #ifdef FLAG
    printf("FLAG is defined after #undef\n");
    a++;
    b++;
    #endif

    printf("a = %d, b = %d\n", a, b);
    printf("Program completed\n");
}

/*
In this modified code, FLAG is undefined using #undef FLAG in the middle of the program. Here's how it works:

The first #ifdef FLAG block checks if FLAG is defined and, as before, prints "FLAG is defined" and performs operations on a and b.

After that, the #undef FLAG directive is used to undefine FLAG.

The second #ifdef FLAG block checks if FLAG is defined again. Since it was undefined using #undef, this block is not compiled.

Finally, the program continues to execute and prints the updated values of a and b, along with "Program completed."

The output will be:

FLAG is defined
a = 21, b = 5
Program completed

This demonstrates how #undef can be used to selectively undefine macros, affecting conditional compilation.

====================================

Writing portable code is essential for ensuring that your program can run on different systems without modification. Conditional compilation directives, like #if, #elif, and #else, are valuable tools for achieving this portability. Here's an example of how you can use these directives to include different header files or execute specific code based on the target machine:

*/

#if MACHINE == ABC
    #define hfile "abc.h"
#elif MACHINE == PQR
    #define hfile "pqr.h"
#elif MACHINE == XYZ
    #define hfile "xyz.h"
#else
    #define hfile "newfile.h"
#endif

#include hfile

/*
In this code:

#if, #elif, and #else directives are used to check the value of the MACHINE macro.

Depending on the value of MACHINE, a specific header file is defined using #define hfile. For example, if MACHINE is ABC, hfile will be defined as "abc.h".

The #include directive is then used to include the appropriate header file based on the value of hfile.

Now, you can define the MACHINE macro according to the target system before compiling your code. For example:
*/

#define MACHINE ABC
//or
#define MACHINE XYZ


/*
By changing the value of MACHINE, you can easily switch between different header files or code blocks tailored to specific systems.

This approach allows you to write code that's portable across various systems by providing different implementations based on the chosen MACHINE value, making your program adaptable to different environments without manual code modifications.

========================================

Debugging is a crucial part of software development to identify and correct errors in your code. Preprocessor directives, such as #ifdef and #endif, can be valuable for managing debugging statements and toggling them on and off as needed. Here's how you can use them effectively:

Define a DEBUG macro: Create a DEBUG macro that can be defined or undefined to control the presence of debugging statements. For example:

*/

#define DEBUG


/*
Use #ifdef and #endif to enclose debugging statements: Wrap your debugging statements with #ifdef DEBUG and #endif preprocessor directives to make them active only when the DEBUG macro is defined:
*/

#ifdef DEBUG
    printf("Debugging statement 1\n");
    // Add more debugging statements here
#endif

/*
Write a SHOW macro: Create a SHOW macro to simplify the inclusion of debugging statements. This macro will include a printf statement if DEBUG is defined, or it will be replaced by nothing if DEBUG is undefined. Here's how you can define the SHOW macro:
*/

#ifdef DEBUG
#define SHOW(message) printf message
#else
#define SHOW(message)
#endif

/*
Use the SHOW macro for debugging: Now, you can use the SHOW macro to display debugging information in a concise way. Include it where you need debugging output:
*/

SHOW(("Debugging statement 1\n"));
SHOW(("Debugging statement 2 with values: %d, %f\n", x, y));


/*
By defining the DEBUG macro when you want to enable debugging and leaving it undefined when you want to disable it, you can easily switch between debugging and normal mode without having to manually add or remove debugging statements from your code. The SHOW macro helps you keep your code clean and concise, making it easier to manage debugging statements throughout your program.

============================================

Conditional compilation directives like #ifdef and #ifndef can indeed be used to comment out parts of your code temporarily. This is a handy technique for debugging or testing different code paths without having to manually remove or add "comment markers/multiline comments" each time.

Here's how you can use these directives to comment and uncomment code sections:

*/

#include <stdio.h>

// Define the COMMENT macro to comment out the code
#define COMMENT

int main() {
#ifndef COMMENT
    printf("This code is active.\n");
#endif

    // This part of the code is always active
    printf("This code is always active.\n");

#ifndef COMMENT
    printf("This code is also active.\n");
#endif

    return 0;
}


/*
In the code above, by defining the COMMENT macro at the beginning, you comment out the sections enclosed by #ifndef COMMENT and #endif. If you want to activate those sections, simply remove or comment out the #define COMMENT line or define it as follows:

// Uncomment the line to activate the commented sections
// #define COMMENT

This way, you can easily control which parts of your code are active and which are commented out by toggling the COMMENT macro.

=================================================

Using conditional compilation directives like #ifndef and #endif to prevent multiple inclusions of header files is a common and essential practice in C programming. It helps ensure that the contents of a header file are included only once, preventing multiple definitions and conflicts in your code.

Here's a typical example of how this is done:

*/

// In stdio.h, or any other header file
#ifndef STDIO_H
#define STDIO_H

// Contents of stdio.h

#endif

/*
When you include this header file in your program, the #ifndef directive checks if the STDIO_H macro is defined. If it's not defined (which is the case the first time it's included), it defines STDIO_H using #define STDIO_H and then includes the contents of the file. On subsequent inclusions of the same header, the #ifndef check finds that STDIO_H is already defined, so it skips the contents of the file.

This technique prevents issues like multiple definitions of constants, functions, or types that can occur when you include the same header file in multiple places in your code. It ensures that header files are included only once and helps maintain code integrity.

===========================================

REPEAT OF THE ABOVE:

Conditional compilation can be used for a variety of purposes, including:

Preventing multiple definitions: This is the most common use case for conditional compilation. By enclosing the definition of a variable, function, class, or other entity in #ifndef and #endif directives, you can ensure that it is only defined once, even if the header file that contains it is included multiple times. This is important to avoid linker errors.

Compiling different code for different platforms or configurations: Conditional compilation can also be used to compile different code for different platforms or configurations. For example, you might use it to compile different versions of a function for different versions of the operating system, or to compile different code for debug and production builds.

Feature flags: Conditional compilation can also be used to implement feature flags. A feature flag is a boolean value that can be used to enable or disable a particular feature of your program. By using conditional compilation to control whether or not certain code is compiled, you can dynamically enable or disable features without having to recompile your program.

The example you provided of using conditional compilation to avoid multiple definitions of the constant NULL is a good one. This is a common practice in C and C++, and it is a good way to ensure that your code is portable and reliable.

Here is another example of how conditional compilation can be used:

*/

#ifdef DEBUG
// This code will only be compiled if the DEBUG macro is defined.
printf("Debug message\n");
#endif

/*
This code snippet will only be compiled if the macro DEBUG is defined. This can be useful for debugging your code, as you can enable or disable debug output without having to recompile your program.

Conditional compilation is a powerful tool that can be used to improve the quality and maintainability of your code.

=============================================

Predefined macro names like __DATE__, __TIME__, __FILE__, and __LINE__ provide valuable information about the code during compilation. Here's a brief explanation of each:

__DATE__: This macro represents the date of compilation in the format "mm dd yyyy," where mm is the month, dd is the day, and yyyy is the year. It helps you track when your code was last compiled.

__TIME__: This macro represents the time of compilation in the format "hh:mm:ss," where hh is the hour, mm is the minute, and ss is the second. It tells you the exact time the code was compiled.

__FILE__: This macro provides a string constant that represents the name of the file being compiled. It helps you identify which source file is currently under compilation.

__LINE__: This macro is a decimal constant representing the line number being compiled. It tells you the line number in the source code where this macro is used.

These predefined macros are handy for debugging, error reporting, and for adding timestamps to your code. They provide useful information about your code's compilation process, which can be helpful when diagnosing issues or tracking changes in your program.

*/

#include <stdio.h>

int main() {
  int x = 10;
  int y = 0;

  if (y == 0) {
    fprintf(stderr, "Error on line %d of file %s: Division by zero.\n", __LINE__, __FILE__);
    return 1;
  }

  int result = x / y;
  printf("%d\n", result);

  return 0;
}

/*
If we compile and run this program, we will get the following output:

Error on line 10 of file main.c: Division by zero. This error message tells us that the error occurred on line 10 of the file main.c. This information can be helpful for debugging the program.

Conditional compilation and predefined macros are powerful tools that can be used to improve the quality and maintainability of your C code.

==================================================

The #line directive in C is used primarily for debugging and controlling line numbering and file naming during compilation. It has the following syntax:

*/

#line decimal_constant [string_constant]

/*
decimal_constant: Any decimal constant, which is typically used to set the line number.
string_constant: Any string constant, used to set the file name. If not specified, the current file name remains unchanged.
Here's how it works:

When you use #line, you set the __LINE__ macro to the specified decimal_constant value, and the __FILE__ macro to the specified string_constant value.

After the #line directive, the __LINE__ and __FILE__ macros will reflect the values you provided.

If you don't specify string_constant, the file name (__FILE__) remains unchanged, but the line number (__LINE__) is set to the specified value.

In the provided program:
*/

#include <stdio.h>

int main() {
    printf("C in depth\n");
    printf("%d. %s\n", __LINE__, __FILE__);

    #line 25 "myprog.c"
    printf("%d %s\n", __LINE__, __FILE__);

    return 0;
}

/*
Here's what happens:

Initially, it prints "C in depth" and the line and file name where main is located.

After the #line directive, it sets the line number to 25 and changes the file name to "myprog.c".

The second printf statement prints these updated values.

This can be useful for generating custom debugging information or for situations where you want to control line numbering and file names explicitly during compilation.
*/

#include <stdio.h>

int main() {
  int x = 10;
  int y = 0;

  if (y == 0) {
#line 25 "myprog.c"
    fprintf(stderr, "Error on line %d of file %s: Division by zero.\n", __LINE__, __FILE__);
    return 1;
  }

  int result = x / y;
  printf("%d\n", result);

  return 0;
}

/*
If we compile and run this program, we will get the following output:

Error on line 25 of file myprog.c: Division by zero. This error message is more informative than the error message in the previous example, because it tells us the exact line number and file name where the error occurred.

The #line directive can be a very useful tool for debugging C code. It can be used to add more informative error messages, to step through your code in a debugger, and to create conditional breakpoints.

------------------------------------------------

the #line directive is used for debugging purposes. It allows you to change the line number and file name that are reported by the compiler for the next line of code. This can be useful for adding more informative error messages or for stepping through your code in a debugger.

The syntax for the #line directive is:

#line line_number file_name
where line_number is the new line number and file_name is the new file name.

Your example program illustrates how to use the #line directive to change the line number and file name reported by the compiler. The program starts by printing the current line number and file name. Then, it uses the #line directive to change the line number to 25 and the file name to myprog.c. Finally, it prints the line number and file name again.

When you compile and run the program, you will see the following output:

6 C:\prog.c
25 myprog.c

As you can see, the #line directive successfully changed the line number and file name that were reported by the compiler for the second printf() statement.

===============================================

The #error preprocessor directive is indeed a valuable debugging tool in C. It is used to stop compilation and display an error message along with it.

This can be particularly helpful in situations where you want to ensure certain conditions are met during compilation, and if not, you want to provide a clear error message to the programmer. Here are a few common use cases for the #error directive:

Check for the Existence of Macros: You can use #error to ensure that specific macros are defined or not defined. For example, in the code:

*/

#ifndef MACRO
#error MACRO is not defined
#endif

/*
If the macro MACRO is not defined, compilation will stop with the error message "MACRO is not defined."

Conditional Compilation: You can use #error to conditionally compile parts of your code based on certain conditions. For instance:
*/

#if defined(_Windows) && !defined(_BUILDRTLDLL)
#error Timer not available for Windows
#endif

/*
This checks if certain macros are defined and, if not, halts compilation with an error message.

Checking for ANSI C Compliance: If you want to ensure that your code adheres to ANSI C standards, you can use:
*/

#ifndef STDC
#error This program should be run using ANSI C
#endif

/*
If your code relies on ANSI C features, you can use this directive to enforce it.

Avoiding Duplicate Inclusions: To prevent multiple headers from being included simultaneously, you can use #error to check for this condition. For instance:

In stdarg.h:
*/

#ifndef STDARG_H
#define __STDARG_H
#ifdef _VARARGS_H
#error Can't include both stdarg.h and varargs.h
#endif
// ... contents of the file ...
#endif


/*
In varargs.h:
*/


#ifndef __VARARGS_H
#define __VARARGS_H
#ifdef STDARG_H
#error Can't include both stdarg.h and varargs.h
#endif
// ... contents of the file ...
#endif

/*
This prevents both stdarg.h and varargs.h from being included in the same compilation unit.

In all these cases, the #error directive helps ensure that the code meets specific conditions and provides clear feedback to the programmer when those conditions are not met, helping in debugging and maintaining code quality.

=========================================

Let's expand on this....

#error directive is a preprocessor directive that can be used for debugging purposes. It stops compilation and displays an error message. The error message can be any string, but it is typically used to indicate that a certain condition has not been met or that a certain macro is not defined.

Your examples of how to use the #error directive are all correct.

Here is another example of how to use the #error directive:
*/

#include <stdio.h>

int main() {
  // Check if the compiler is set to the ANSI C standard.
#ifndef STDC
  #error This program should be run using ANSI C
#endif

  // Print a message to the console.
  printf("Hello, world!\n");

  return 0;
}

/*
If we compile and run this program without setting the compiler to the ANSI C standard, we will get the following error message:

This program should be run using ANSI C
This error message tells us that the program must be compiled with the ANSI C standard enabled.

The #error directive can be a very useful tool for debugging C code. It can be used to ensure that certain conditions are met before the program is compiled, and to generate informative error messages.

Here are some additional tips for using the #error directive:

Use the #error directive to generate informative error messages that tell you what went wrong and where.
Use the #error directive to prevent the program from being compiled if certain conditions are not met.
Be careful not to overuse the #error directive, as this can make your code difficult to read and maintain.

=========================================

The "null directive" in C, consisting only of the symbol #, doesn't have any effect on the program itself. Its primary purpose is to serve as a placeholder for documentation or comments within the preprocessor directives section of your code. This directive is essentially ignored by the compiler and is used solely for human readability and organization of code.

For example:

*/

# This is a comment within the preprocessor directives section

/*
In this case, the # symbol is used to indicate that what follows is a comment or documentation for the preprocessor directives section. It doesn't affect the program's compilation or behavior.

As for the #pragma directive, it's a compiler-specific feature and not part of the C language standard. It allows you to provide compiler-specific instructions or hints to the compiler. The exact behavior and available pragmas can vary between different compilers, so you should consult your compiler's documentation to understand the specific pragmas it supports.

Common uses of #pragma include specifying functions to be called at program startup or exit, controlling compiler warnings, and providing hints for optimizations. Here are a few examples:

#pragma startup: Specifies a function to be called at program startup.


*/

#pragma startup func1

/*
This would call the function func1 before the main() function is executed.

#pragma exit: Specifies a function to be called at program exit.

*/

#pragma exit func2


/*
This would call the function func2 just before the program terminates.

#pragma inline: Informs the compiler that inline assembly code is present in the program.
*/

#pragma inline

/*
This is used to indicate that there is inline assembly code that should be handled appropriately by the compiler.

#pragma warn: Controls compiler warning messages.
*/

#pragma warn -rvl


/*
This example turns off the warning related to variables not being used.

Keep in mind that the availability and behavior of #pragma directives depend on the compiler you're using, and they may not be portable across different compilers. It's essential to refer to your compiler's documentation for specific pragma directives and their usage.

====================================================

To view the code expanded by the C preprocessor, you can follow different procedures depending on your development environment. Here are instructions for Turbo C and UNIX:

For Turbo C:

In Turbo C, there is a utility called cpp (C preprocessor) that you can use to create a file containing the expanded source code.

The expanded code will be saved in a file with the same name as your source code file but with a ".i" extension.

If your source code includes #include directives, you may need to specify the path to the include files using the -I option.

Open your command prompt or terminal.

Navigate to the directory where your source code file is located.

Run the cpp utility with the following command:

***************

cpp yourfile.c

***************

Replace yourfile.c with the name of your source code file.

If your code includes #include directives with include paths, you can specify them with the -I option:

*********************************************

cpp -Ipath/to/includes yourfile.c

*********************************************

The expanded code will be written to a file with a ".i" extension in the same directory as your source code file.

You can view the expanded code using a text editor or by using command-line tools.

For UNIX:

In UNIX-based systems (including Linux), you can view the expanded code using compiler-specific options.

To display the output of the preprocessor on the terminal, use the -E option with the compiler. For example, if you're using GCC (GNU Compiler Collection), you can do the following:

**********************

gcc -E yourfile.c

**********************

This will show the preprocessed code directly on your terminal.

If you want to save the preprocessed code to a file, you can use the -E option with redirection:

******************************

gcc -E yourfile.c > output.i

******************************

This will save the expanded code in a file named output.i.

Similar to Turbo C, if your code includes #include directives with include paths, you can specify them using the -I option:

***************************************

gcc -E -I/path/to/includes yourfile.c

***************************************

You can view the expanded code using a text editor or by inspecting the content of the generated .i file.

Remember to replace yourfile.c with the actual name of your source code file and adjust the paths as needed. The exact commands and options may vary slightly depending on your specific development environment and compiler.

*/



/*
Comment 1
*/

/*
Comment 2
*/

/*
Comment 3
*/

/*
Comment 4
*/

/*
Comment 5
*/

/*
Comment 6
*/

/*
Comment 7
*/

/*
Comment 8
*/

/*
Comment 9
*/

/*
Comment 10
*/



/*
Comment 1
*/

/*
Comment 2
*/

/*
Comment 3
*/

/*
Comment 4
*/

/*
Comment 5
*/

/*
Comment 6
*/

/*
Comment 7
*/

/*
Comment 8
*/

/*
Comment 9
*/

/*
Comment 10
*/



/*
Comment 1
*/

/*
Comment 2
*/

/*
Comment 3
*/

/*
Comment 4
*/

/*
Comment 5
*/

/*
Comment 6
*/

/*
Comment 7
*/

/*
Comment 8
*/

/*
Comment 9
*/

/*
Comment 10
*/


/*
Comment 1
*/

/*
Comment 2
*/

/*
Comment 3
*/

/*
Comment 4
*/

/*
Comment 5
*/

/*
Comment 6
*/

/*
Comment 7
*/

/*
Comment 8
*/

/*
Comment 9
*/

/*
Comment 10
*/

