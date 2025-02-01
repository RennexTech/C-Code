#include <stdio.h>
#include <limits.h>
#include <float.h>
/*

putting the funtion on top of main so that it may be able to be called
i noticed whenever i was able to call a function after i put it on top of the main, whenever i put it below main and tried to call it, it  refuses to be called.
In C, functions must be declared or defined before they are used (called) in the code. If you define a function below the main function and then try to call it before the definition, the compiler won't know about the function, and it will result in a compilation error.

*/

void format_specifiers() {
    sleep(2);
    printf("+-------+----------------------------------------+\n");
    printf("| Format| Description                            |\n");
    printf("+-------+----------------------------------------+\n");
    printf("|   %%d  | A decimal integer                     |\n");
    printf("|   %%f  | A floating-point number               |\n");
    printf("|   %%e  | A floating-point number (scientific)  |\n");
    printf("|   %%g  | A floating-point number (shortest)    |\n");
    printf("|   %%lf | A double (long range floating point)  |\n");
    printf("|   %%h  | A short integer                       |\n");
    printf("|   %%o  | An octal integer                      |\n");
    printf("|   %%x  | A hexadecimal integer                |\n");
    printf("|   %%i  | A decimal, octal, or hexadecimal int  |\n");
    printf("|   %%s  | A string                              |\n");
    printf("|   %%u  | An unsigned decimal integer           |\n");
    printf("+-------+----------------------------------------+\n");

    printf("\n");
    sleep(2);

    printf("+---------+-------------------------------------------------------------+\n");
    printf("| Format  | Description                                                 |\n");
    printf("+---------+-------------------------------------------------------------+\n");
    printf("|   %%hd   | Short integer (signed)                                     |\n");
    printf("|   %%hu   | Short integer (unsigned)                                   |\n");
    printf("|   %%ld   | Long integer (signed)                                      |\n");
    printf("|   %%lu   | Long integer (unsigned)                                    |\n");
    printf("|   %%lld  | Long long integer (signed)                                 |\n");
    printf("|   %%llu  | Long long integer (unsigned)                               |\n");
    printf("|   %%Lf   | Long double                                               |\n");
    printf("|   %%e    | Floating-point number (standard, e.g., 3.14)                |\n");
    printf("|   %%Le   | Long double (scientific, e.g., 3.14E+02)                    |\n");
    printf("|   %%f    | Floating-point number (standard, e.g., 3.14)                |\n");
    printf("|   %%Lf   | Long double                                               |\n");
    printf("|   %%g    | Floating-point number (standard or scientific)             |\n");
    printf("|   %%e    | Floating-point number (scientific, e.g., 3.14E+02)        |\n");
    printf("|   %%Le   | Long double (scientific, e.g., 3.14E+02)                    |\n");
    printf("+---------+-------------------------------------------------------------+\n");

    printf("\n");
    sleep(2);

    printf("Format Specifiers with Modifiers:\n\n");

    printf("%%hd: Short integer (signed)\n");
    printf("Size: %2lu bytes\n", sizeof(short));
    printf("Range: %d to %d\n", SHRT_MIN, SHRT_MAX);
    printf("\n");

    printf("%%hu: Short integer (unsigned)\n");
    printf("Size: %2lu bytes\n", sizeof(unsigned short));
    printf("Range: 0 to %u\n", USHRT_MAX);
    printf("\n");

    printf("%%ld: Long integer (signed)\n");
    printf("Size: %2lu bytes\n", sizeof(long));
    printf("Range: %ld to %ld\n", LONG_MIN, LONG_MAX);
    printf("\n");

    printf("%%lu: Long integer (unsigned)\n");
    printf("Size: %2lu bytes\n", sizeof(unsigned long));
    printf("Range: 0 to %lu\n", ULONG_MAX);
    printf("\n");

    printf("%%lld: Long long integer (signed)\n");
    printf("Size: %2lu bytes\n", sizeof(long long));
    printf("Range: %lld to %lld\n", LLONG_MIN, LLONG_MAX);
    printf("\n");

    printf("%%llu: Long long integer (unsigned)\n");
    printf("Size: %2lu bytes\n", sizeof(unsigned long long));
    printf("Range: 0 to %llu\n", ULLONG_MAX);
    printf("\n");

    printf("%%Lf: Long double\n");
    printf("Size: %2lu bytes\n", sizeof(long double));
    printf("Range: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    printf("\n");

    printf("%%e: Floating-point number (standard)\n");
    printf("Size: %2lu bytes\n", sizeof(float));
    printf("Range: %e to %e\n", FLT_MIN, FLT_MAX);
    printf("\n");

    printf("%%Le: Long double (scientific)\n");
    printf("Size: %2lu bytes\n", sizeof(double));
    printf("Range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("\n");

    printf("%%f: Floating-point number (standard)\n");
    printf("Size: %2lu bytes\n", sizeof(double));
    printf("Range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("\n");

    printf("%%g: Floating-point number (standard or scientific)\n");
    printf("Size: %2lu bytes\n", sizeof(double));
    printf("Range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("\n");

    printf("%%e: Floating-point number (scientific)\n");
    printf("Size: %2lu bytes\n", sizeof(double));
    printf("Range: %e to %e\n", DBL_MIN, DBL_MAX);
    printf("\n");

    printf("%%Le: Long double (scientific)\n");
    printf("Size: %2lu bytes\n", sizeof(long double));
    printf("Range: %Le to %Le\n", LDBL_MIN, LDBL_MAX);
    printf("\n");


}

int main() {
    printf("+------------------+----------------------------------------------------+\n");
    printf("| Function         | Usage                                              |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| scanf            | Used to read formatted input from the user or file. |\n");
    printf("|                  | Example: scanf(\"%%d\", &num);                         |\n");
    printf("|                  | Reads an integer and stores it in 'num'.            |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| printf           | Used to format and print output to the console.     |\n");
    printf("|                  | Example: printf(\"The answer is: %%d\\n\", num);        |\n");
    printf("|                  | Displays the value of 'num' with a message.         |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| getchar          | Used to read a single character from the input      |\n");
    printf("|                  | stream.                                            |\n");
    printf("|                  | Example: ch = getchar();                            |\n");
    printf("|                  | Reads a character and stores it in 'ch'.            |\n");
    printf("+------------------+----------------------------------------------------+\n");
    printf("| putchar          | Used to write a single character to the output      |\n");
    printf("|                  | stream.                                            |\n");
    printf("|                  | Example: putchar('H');                              |\n");
    printf("|                  | Displays the character 'H'.                         |\n");
    printf("+------------------+----------------------------------------------------+\n");

    printf("\n");

    //trying the i/o functions out in program code
    //I know how to use printf and scanf
    putchar('a'); //this one works
    puts("This is a random statement. I am using puts() to display it.");
    printf("This is a random statement. I am using printf() to display it.");

    printf("\n");

    //When you enter a digit between 0 and 9, such as '5', it's treated as a character and printed as is.
    char ch;
    printf("Enter a single character: \n");
    ch = getchar();
    printf("The character you entered is: %c\n", ch);

    printf("\n");

    format_specifiers();
    date();

    return 0;
}


