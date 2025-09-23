#include <stdio.h>

// A recursive approach to handle special cases and large numbers.
int roman(int, int, char);

int main() {
    int num;
    printf("Enter a number : ");
    scanf("%d", &num);
    
    // The if statements call the roman function sequentially to handle different denominations.
    if (num >= 1000)
        num = roman(num, 1000, 'm');
    if (num >= 500)
        num = roman(num, 500, 'd');
    if (num >= 100)
        num = roman(num, 100, 'c');
    if (num >= 50)
        num = roman(num, 50, 'l');
    if (num >= 10)
        num = roman(num, 10, 'x');
    if (num >= 5)
        num = roman(num, 5, 'v');
    if (num >= 1)
        num = roman(num, 1, 'i');
        
    printf("\n");
    return 0;
}

// This function acts like a vending machine for Roman numerals.
// You put in a number, and it spits out the right characters until it can't anymore.
// The key is that it passes the remaining value back to the main function.
int roman(int n, int k, char c) {
    // This part handles the special cases for 4 and 9.
    // It's a quick fix that doesn't handle all the subtractive notations like 40, 90, 400, etc.
    // A better approach would be to use a table-based algorithm for a more robust solution.
    if (n == 9) {
        printf("ix");
        return 0;
    }
    if (n == 4) {
        printf("iv");
        return 0;
    }
    
    // As long as the number is greater than or equal to the current denomination,
    // we print the corresponding character and subtract the value.
    while (n >= k) {
        printf("%c", c);
        n = n - k;
    }
    return n;
}