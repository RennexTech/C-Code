#include <stdio.h>
#include <stdlib.h>

/*

This is going to be comprehensive, including both scanf , getchar, printf, putchar and much more, all is going to be covered here.
First, you use standard input output header for this portion of C programming
Functions like scanf, getchar, printf, putchar, and puts are part of the standard C library and are commonly used for input and output operations. However, the usage of these functions might vary depending on the context and the specific requirements of your program.

Here's a breakdown of each function and its common usage:

scanf: This function is used to read formatted input from the user or a file. It's commonly used to read different types of data like integers, floating-point numbers, characters, etc. However, scanf can be error-prone when handling user input, as it can lead to buffer overflow and parsing issues if not used carefully. It's recommended to use safer alternatives like fgets and then parse the input using functions like sscanf if necessary.
getchar: This function is used to read a single character from the input stream. It's often used in simple input scenarios, but it's not commonly used for more complex input processing due to its limited capabilities.
printf: This function is used to format and print output to the console. It supports various format specifiers for different data types. printf is widely used for displaying information to the user.
putchar and puts: putchar is used to write a single character to the output stream, and puts is used to write a string followed by a newline character. puts is often used to display messages or output strings to the user.


*/

#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    ch = getchar();
    printf("You entered: %c\n", ch);
    return 0;
}

#include <stdio.h>

int main() {
    char ch;
    printf("Enter a character: ");
    ch = getchar();
    printf("You entered: %c\n", ch);
    return 0;
}


#include <stdio.h>

int main() {
    int num = 42;
    printf("The answer is: %d\n", num);
    return 0;
}
