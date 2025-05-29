#include <stdio.h>
#include <stdlib.h> // Not strictly needed for this example

// Symbolic constants defined using #define.
// The preprocessor replaces these names with their values before compilation.
#define NAME "Nixon"
#define PI 3.142
#define MAX 100
#define CH 'a'

int main() {
    /*
     * This program demonstrates the use of symbolic constants defined
     * with the #define preprocessor directive. These constants make
     * code more readable and easier to maintain by giving meaningful
     * names to fixed values.
     */
    char my_name[20] = NAME;
    int d = MAX;
    double circumference = PI * d;
    char letter = CH;

    printf("My first name is: %s\n", my_name);
    printf("The circumference of the circle is: %lf\n", circumference);
    printf("The letter requested is: %c\n", letter);
    printf("The maximum value that was used to compute circumference was: %d\n", d);

    return 0;
}
