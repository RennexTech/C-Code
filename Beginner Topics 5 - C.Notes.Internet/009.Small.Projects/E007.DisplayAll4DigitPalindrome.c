#include <stdio.h>

int main() {
    int num, rev, rem, start, end, temp;

    printf("Enter the lower limit: ");
    scanf("%d", &start);
    printf("Enter the upper limit: ");
    scanf("%d", &end);

    printf("Palindrome numbers between %d and %d are:\n", start, end);

    for (num = start; num <= end; num++) {
        rev = 0; // Reset our "reverse" counter for a new number.
        temp = num;

        // Imagine you're taking a number, like 121, and you're building
        // a mirror image of it, digit by digit. You take the last digit (1),
        // then the next (2), and the next (1), and stitch them together in
        // reverse order to create a new number.
        while (temp > 0) {
            rem = temp % 10;
            rev = rev * 10 + rem;
            temp = temp / 10;
        }

        // Now, we're checking if the original number and its mirror image
        // are the same. If they are, it's a palindrome.
        if (num == rev) {
            printf("%d\n", num);
        }
    }

    return 0;
}