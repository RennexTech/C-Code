#include <stdio.h>
int main() {
    int n, f1, f2, f3;
    printf("Enter a Number : ");
    scanf("%d", &n);

    // The first two Fibonacci numbers are a bit of a special case, so we check for them up front.
    // Think of them as the foundation of the sequence.
    if (n == 0 || n == 1) {
        printf("%d is a fibonacci number : ", n);
    } else {
        f1 = 0;
        f2 = 1;
        f3 = f1 + f2;
    }

    // We're essentially generating the Fibonacci sequence, one number at a time,
    // and stopping when our generated number is equal to or greater than the input number.
    while (f3 < n) {
        // We're shifting our numbers over to get ready for the next one in the sequence.
        // It's like a hand-off in a relay race.
        f1 = f2;
        f2 = f3;
        f3 = f1 + f2;
    }

    // After the loop, we check if we found a perfect match.
    // If our generated number is exactly the same as the user's input, it's a hit.
    if (f3 == n) {
        printf("%d is a fibonacci number ", n);
    } else {
        printf("%d is not a fibonacci number ", n);
    }
    return 0;
}