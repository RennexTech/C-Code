#include<stdio.h>

int main()
{
    // These are integer variables to hold the day, month, and year entered by the user.
    int d, m, y;

    // This is an array of character pointers, which is a perfect way to store a list of strings.
    // Each element in the `months` array points to the first character of a string literal
    // (e.g., `months[0]` points to the 'J' in "January").
    // We'll use this array to look up the name of the month based on the number the user provides.
    char *months[] = {
        "Janunary", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"
    };

    // We're prompting the user to enter a date in a specific format (e.g., 25/12/2025).
    printf("Enter date (dd/mm/yyyy): ");

    // `scanf` reads the input. The format specifier `%d/%d/%d` tells `scanf` to expect three
    // integers separated by forward slashes.
    // The `&` operator is used to get the memory addresses of `d`, `m`, and `y`, so `scanf`
    // knows where to store the numbers it reads from the user.
    scanf("%d/%d/%d", &d, &m, &y);

    // This is the final output. We print the day, the month name, and the year.
    // The key part is `months[m-1]`. Since array indexes start at 0, and month numbers start at 1,
    // we have to subtract 1 from the month number to get the correct index.
    // For example, if the user enters 12 for December, we use `months[12-1]`, which is `months[11]`,
    // to access the correct string.
    printf("%d %s %d\n", d, months[m-1], y);
    
    return 0;
}