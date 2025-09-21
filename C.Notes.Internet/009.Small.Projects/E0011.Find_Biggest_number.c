#include <stdio.h>
int biggestNumber(int a, int b, int c);

int main() {
    int a, b, c;
    printf("Enter 3 Numbers : \n");
    scanf("%d%d%d", &a, &b, &c);

    int result = biggestNumber(a, b, c);

    printf("Biggest Number is : %d\n", result);
    return 0;
}

// Imagine these three numbers are runners in a race.
// We're figuring out who won by doing a series of head-to-head matches.
int biggestNumber(int a, int b, int c) {
    // First, we pit 'a' against 'c'. If 'a' wins...
    if (a > c) {
        // ...we then put 'a' up against 'b'. The winner of this final match is the champion.
        if (a > b) {
            return a;
        } else {
            return b;
        }
    }
    // If 'a' lost to 'c' in the first round...
    else {
        // ...it's now a fight between 'b' and 'c' for the top spot.
        if (b > c) {
            return b;
        } else {
            return c;
        }
    }
}