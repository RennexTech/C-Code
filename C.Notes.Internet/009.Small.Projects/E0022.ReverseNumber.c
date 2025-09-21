/* Write a program to enter numbers and find revers of that numbers */
#include <stdio.h>
int main() {
    int n, rev = 0, rem;
    printf("Enter a numbers :");
    scanf("%d", &n);
    
    // Imagine this loop is like taking apart a number, digit by digit, and
    // then building a new number from the pieces, but in reverse.
    while (n != 0) {
        // We get the last digit of the number using the remainder.
        rem = n % 10;
        
        // We tack the new digit onto our `rev` number. Multiplying by 10
        // shifts the existing digits to the left, making space for the new one.
        rev = rev * 10 + rem;
        
        // We cut off the last digit from the original number,
        // getting it ready for the next round.
        n = n / 10;
    }
    
    printf("Reverse numbers : %d", rev);
    return 0;
}