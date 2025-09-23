/* Write a program to print number from 1 to 80 separated by tab, 8 number per line */
#include <stdio.h>
int main() {
    int i;
    
    // We're going to print numbers from 1 to 80.
    for (i = 1; i <= 80; i++) {
        // We print the current number, followed by a tab.
        // Think of a tab as a quick jump to the next column in a spreadsheet.
        printf("%d\t", i);
        
        // This is the main logic for formatting. The modulo operator `%` gives us the remainder
        // of a division. When `i % 8` equals 0, it means 'i' is perfectly divisible by 8.
        // We use this to trigger a newline after every 8th number, creating a new row.
        if (i % 8 == 0)
            printf("\n");
    }
    return 0;
}