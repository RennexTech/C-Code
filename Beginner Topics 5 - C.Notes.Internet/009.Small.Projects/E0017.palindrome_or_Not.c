#include <stdio.h>
int main() {
    int n, rev = 0, rem, originalN;
    printf("Enter a Numbers : ");
    scanf("%d", &n);
    
    // We make a copy of the number so we can mess with it in the loop
    // without losing the original value. Think of it like taking a photo
    // of a sculpture before you start chiseling.
    originalN = n;
    
    // This loop is the heart of the check. It's like taking a word and
    // spelling it backward, one letter (digit) at a time.
    while (n != 0) {
        // We grab the last digit. This is like isolating the last letter.
        rem = n % 10;
        
        // We add the digit to our reversed number, effectively building it backward.
        rev = rev * 10 + rem;
        
        // We then cut off the last digit from the original number,
        // so we can move on to the next one.
        n = n / 10;
    }
    
    // Once we're done, we just compare the original number to our new, reversed one.
    // If they're the same, it's a palindrome.
    if (originalN == rev) {
        printf("%d is Palindrome Number", originalN);
    } else {
        printf("%d is Not Palindromw Number", originalN);
    }
    return 0;
}