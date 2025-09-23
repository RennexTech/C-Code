#include <stdio.h>

int main() {
    int i = 0, n, sum = 0;
    float avg;

    printf("Enter 10 positive numbers:\n");

    while (i < 10) {
        printf("Enter number %d: ", i + 1);
        scanf("%d", &n);

        // If the number is negative, we're not gonna count it.
        // It's like you're baking cookies, and one of them falls on the floor.
        // You're not going to eat it, and you're not going to count it
        // towards your final batch. You just leave it there and bake another one.
        // The `continue` statement here skips the rest of the loop for this
        // specific number and goes straight to the next round of baking.
        if (n < 0) {
            printf("Error: Please enter a positive number.\n");
            continue;
        }

        sum += n;
        i++; // Only count the good numbers.
    }

    // This is where we get the average. Dividing by `10.0` ensures the result
    // is a decimal, so you get an accurate average instead of a rounded integer.
    avg = sum / 10.0;

    printf("\nSum = %d\nAverage = %.2f\n", sum, avg);

    return 0;
}