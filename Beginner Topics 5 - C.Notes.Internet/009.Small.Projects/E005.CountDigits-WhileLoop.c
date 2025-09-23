#include <stdio.h>

int main() {
    int num, count = 0;

    printf("Enter a number: ");
    scanf("%d", &num);

    // Handle the special case where the number is 0.
    if (num == 0) {
        count = 1;
    } else {
        // Use a temporary variable so we don't change the original number.
        int temp = num;

        // The loop continues as long as `temp` is not 0.
        // In each iteration, we remove the last digit by integer division.
        while (temp != 0) {
            temp /= 10;
            count++;
        }
    }

    printf("The number of digits in %d is: %d\n", num, count);

    return 0;
}