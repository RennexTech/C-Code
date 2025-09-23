#include <stdio.h>
#include <stdlib.h>
#include <string.h> // We need this for strlen() and other string functions

/*
 * Section 1: String Initialization - The Two OG Methods
 *
 * Think of initializing a string like packing a suitcase for a trip.
 * You can either meticulously place each item one by one, or you can
 * just toss a pre-packed bag in there. Both get the job done.
 */

/*
 * Method 1: The Meticulous Packer
 *
 * This is when you initialize a character array with individual characters.
 * It's explicit, like placing each sock and shirt one at a time.
 * The null character ('\0') is your final "zipper" on the suitcase. It's
 * the most crucial part because it tells the compiler, and any function
 * that reads this string, that the data ends right here. Without it,
 * the program will keep reading random memory until it hits a null byte
 * by chance, leading to some wild, unpredictable behavior.
 */
char array_method[] = {'N', 'e', 'w', ' ', 'Y', 'o', 'r', 'k', '\0'};

/*
 * Method 2: The Fast Packer
 *
 * This is the more common, concise way. You use a string literal, which
 * is just a sequence of characters wrapped in double quotes. C is smart
 * enough to know what's up. It automatically adds that 'zipper' ('\0')
 * for you at the end. It's a lifesaver and a major time-saver.
 */
char literal_method[] = "New York";

/*
 * Section 2: Navigating Strings with Pointers
 *
 * In C, a pointer is like a magical GPS that holds a memory address. When
 * you use a pointer to iterate through a string, you're not moving the
 * string itself, you're just moving your GPS marker from one character's
 * location to the next.
 */
int main()
{
    char str[] = "JesusChrist";
    char *p = str; // 'p' is our GPS, and we're setting its initial location to the start of the 'str' array.

    printf("Iterating through the string using a pointer:\n");
    printf("--------------------------------------------\n");

    /*
     * The while loop condition: `*p != '\0'`
     *
     * This is the industry-standard, most robust way to check for the end
     * of a C string. It's like your GPS saying, "Am I at the end of the road?"
     * The null terminator, '\0', is the universal "stop here" sign.
     *
     * IMPORTANT FIX: Your original code used a confusing and inefficient
     * second condition: `p < str + strlen(str)`. This is redundant and
     * a common misconception. For every single character, your program
     * would have to call `strlen()`, which is a function that loops
     * through the WHOLE string to find its length again. It's a performance
     * killer and totally unnecessary. The `*p != '\0'` check is all you need
     * for a properly null-terminated string.
     */
    while (*p != '\0')
    {
        /*
         * Corrected printf format specifiers:
         *
         * The original code used `%u` for printing the pointer address.
         * The correct format specifier is `%p`. Think of it as telling
         * `printf` to display the address in the proper format for a pointer,
         * which is usually in hexadecimal (e.g., `0x7ffc8c8c7d60`). Using `%u`
         * treats the address as a simple, unsigned integer, which is incorrect
         * and can lead to warnings and strange output. It's a rookie mistake,
         * but a crucial one to fix.
         */
        printf("Character = %c\t", *p); // The dereference operator `*` gets the value at the address.
        printf("Address = %p\n", (void*)p); // We cast `p` to `(void*)` for portability with `%p`.

        p++; // The `++` operator moves our GPS marker to the next character's memory address.
    }
    printf("--------------------------------------------\n\n");


    /*
     * Section 3: Safe String Input - The gets() vs. fgets() Showdown
     *
     * This is the most critical fix in these notes. `gets()` is a massive
     * security flaw. Think of it like this: `gets()` is a hungry monster
     * that will eat up whatever you give it, no matter how big the food
     * is, and it will keep eating until it overflows its stomach (the
     * allocated memory) and starts consuming the food meant for other
     * monsters (other parts of your program's memory). This is a buffer
     * overflow, and it's a huge deal in the world of security.
     *
     * The corrected function below uses `fgets()`, which is like using a
     * food portioning bowl. It takes a third argument: the maximum number
     * of bytes to read. This makes it impossible for the user to provide
     * more input than your buffer can handle, preventing a security nightmare.
     */
    char name[20];
    printf("Enter your first name (including spaces): ");

    /*
     * Corrected Input: Using `fgets()`
     * `fgets(destination, size, source)`
     * - `name`: The destination array.
     * - `sizeof(name)`: The maximum size to read.
     * - `stdin`: The source (standard input, i.e., the keyboard).
     */
    fgets(name, sizeof(name), stdin);

    // The line break from `fgets` needs to be removed for clean output
    name[strcspn(name, "\n")] = 0;

    printf("You're called: %s\n", name);

    return 0;
}
