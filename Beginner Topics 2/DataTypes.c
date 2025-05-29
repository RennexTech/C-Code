#include <stdio.h>
#include <stdlib.h>

/*

When you specify %3f as a format specifier in C's printf or scanf functions, you are indicating that the width of the value to be printed should be at least 3 characters wide. In other words, it should occupy at least 3 characters of space when printed. If the value's width is less than 3 characters, additional space (padding) will be added to meet the specified width.

Here's how it works:

%3f: The % character indicates that you're using a format specifier.
3: This number specifies the minimum width for the value.
f: This part specifies the data type, which is a floating-point number (e.g., float or double).
So, when you use %3f to format a floating-point number, it ensures that the printed number will occupy at least 3 characters. If the number itself has fewer than 3 characters (e.g., 1.2), it will be padded with spaces to meet the minimum width (e.g., " 1.2" with one space before "1.2").

In summary, %3f ensures that the value is at least 3 characters wide, adding padding if necessary.

"%u\n" without any "/" character. The "%u\n" format specifier is used to print an unsigned decimal integer followed by a newline character ("\n").
Don't be confused like me, %u - unsigned , \n newline - i was confused at first seeing that combination %u\n

Now that's all with chapter 1 , we can move on to  opetors and stuff...

*/

int main()
{
    //first data-type is character
    char letter = 'a';
    printf("This character is: %c\n", letter);
    //second data-type is integers
    int number1 = 399;
    int number2 = 5003;
    int sum;
    sum = number1 + number2;
    printf("The sum of the numbers is: %d\n", sum);

    float division;
    division = number1/9;
    printf("Your division results are: %f\n", division);

    double majorMarks;
    majorMarks = number2/593;
    printf("Your major grade after 593 exams is: %lf\n", majorMarks);

    double precision1 = 3.52523532452345235245243525232423432;
    printf("The reduced double precision is: %.10lf\n", precision1);

    float precision2 = 235.2323423423423423423423423423423234;
    printf("The reduced float precision is: %.7f\n", precision2);

    float precision3 = 235.2323423423423423423423423423423234;
    printf("The reduced float precision minimum number of space to be occupied is 7 is: %7f\n", precision3);
    /*

    Minimum number of characters the output should occupy
    note the above have differences .7 and 7f

    In the context of the width specifier, when you specify a width of,
    say, 10 characters, it includes all characters in the printed output,
    including digits, decimal points, signs, and any padding spaces.

    If you double eg 3.22323523523523523523 is just short like this
    3.4523 and you want 10lf , it will give you a result with spaces before the
    actual 3.4523 eg below

    */

    double pie = 3.1453;
    printf("The spaced version of pie is: %10lf\n", pie);

    /*

    The above gives a minimum spacing of 3 infront and adds zeros
    at the end of the result so that the minimum output will not be
    less than 10 characters

    */

    /*

    Let's move on to booleans, and in C booleans are not internally supported
    First you import the header file <stdbool.h>
    C uses integers to represent booleans, where 0 is false and non zero is
    true, meaning even  negative numbers can be used to represent true values.

    */



    return 0;
}
