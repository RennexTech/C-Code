#include <stdio.h>

int main() {
    int n;

    printf("Enter a number: ");
    scanf("%d", &n);

    // Check if the number is positive or negative.
    if (n >= 0) {
        printf("The number is positive.\n");
    } else {
        printf("The number is negative.\n");
    }

    // Check if the number is even or odd using the modulus operator.
    if (n % 2 == 0) {
        printf("The number is even.\n");
    } else {
        printf("The number is odd.\n");
    }

    return 0;
}