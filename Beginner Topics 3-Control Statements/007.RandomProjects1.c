#include <stdio.h>
#include <windows.h>
#include <time.h>
#include <math.h>

// This function multiplies two numbers without using the '*' operator.
// Instead, it uses a simple loop and addition. It's a cool way to see
// what's happening at a more basic level, like how a CPU might handle it
// before it gets to the fancy instructions.
void multiply_no_operator() {
    int num1, num2, num3 = 0;
    int j;

    // Get the numbers from the user.
    printf("Enter the first number: ");
    scanf_s("%d", &num1);
    printf("Enter the second number: ");
    scanf_s("%d", &num2);

    // This handles negative numbers.
    // Analogy: If you owe someone money (negative `num2`), this is like
    // turning both the debt and the amount into positive numbers
    // so you can do the math, but the final answer will still have
    // the correct sign because `num1` was flipped. It's a quick hack
    // to make the loop work.
    if (num2 < 0) {
        num1 = -num1;
        num2 = -num2;
    }

    // This is the core logic.
    // Analogy: Think of it like counting reps at the gym. You want to do
    // a total of `num2` reps. This loop is you doing one rep at a time, and
    // each time you do one, you add the value of `num1` to your total `num3`.
    // It's a repetitive process that gets you to the final number.
    for (j = 0; j < num2; j++) {
        num3 = num3 + num1;
    }

    // Display the final total.
    printf("The result of multiplication is: %d\n", num3);
}

// This function generates a series where each number is the sum of the
// two before it—a classic Fibonacci sequence.
void previous_sum() {
    long x, y, z;
    int i, n;
    x = 0;
    y = 1;
    printf("Enter the number of terms: ");
    scanf_s("%ld", &n);
    printf("%ld ", y); // prints the first term, '1'

    // The loop starts here.
    // Analogy: This is like a train with three cars: x, y, and z.
    // `z` is the new car, which gets its size from the two cars before it (`x` and `y`).
    // Then, the whole train slides forward: `y` becomes the new `x`, and `z` becomes the new `y`.
    // It keeps sliding and adding new cars until the train is long enough (`n` terms).
    for (i = 1; i < n; i++) {
        z = x + y;
        printf("%ld ", z);
        x = y;
        y = z;
    }
    printf("\n");
}

// This is the original, slightly broken logic for checking a 3-digit number.
// The `|| allowed` part in the `if` statement is a logical error; it will
// always evaluate to true because `allowed` (the array's address) is non-zero.
void check_digits_original() {
    int number;
    // These leading zeros are interpreted as octal, not decimal. Bad vibes.
    int allowed[10] = {001, 002, 003, 004, 005, 006, 007, 008, 009};

    printf("Enter a number: \n");
    scanf_s("%d", &number);
    // This condition is logically broken. A number like 500 would get through
    // because `allowed` is a non-zero memory address, making the `||` true.
    if (number < 100 && number <= 999 || allowed) {
        printf("The number is 3 digits and is %d\n", number);
    } else {
        printf("Wrong value, must have three digits.\n");
    }
}

// This is the corrected version of the 3-digit checker. It's way more reliable.
void check_digits_corrected() {
    int number;
    // The numbers are now stored as proper integers.
    int allowed[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};

    printf("Enter a number: ");
    scanf_s("%d", &number);

    // This checks if the number is actually in the 3-digit range.
    if (number >= 100 && number <= 999) {
        // This loop acts as a bouncer at a club, checking if the number
        // is on the guest list (`allowed` array).
        int isAllowed = 0;
        for (int i = 0; i < sizeof(allowed) / sizeof(allowed[0]); i++) {
            if (number == allowed[i]) {
                isAllowed = 1;
                break;
            }
        }

        if (isAllowed) {
            printf("The number is 3 digits and is %d\n", number);
        } else {
            printf("The number is 3 digits, but it's not in the list of allowed numbers.\n");
        }
    } else {
        printf("Wrong value, must have three digits.\n");
    }
}

// This function uses `goto` to skip forward in the code.
// While `goto` is generally frowned upon for making code hard to read,
// it's sometimes used in low-level code as a quick "bailout" to
// jump to an error handler or to skip a block of code.
void find_special_numbers_goto() {
    int m, n, p, num;
    int i, k, d1, d2, d3;

    // This loop finds 3-digit numbers where `num`, `2*num`, and `3*num`
    // are all 3-digit numbers with no repeating digits.
    for (num = 100; num <= 333; num++) {

        // Check for repeating digits within `num`, `2*num`, and `3*num`.
        for (i = num; i <= 3 * num; i += num) {
            k = i;
            d1 = k % 10;
            k /= 10;
            d2 = k % 10;
            k /= 10;
            d3 = k % 10;

            if (d1 == d2 || d2 == d3 || d3 == d1)
                goto nextnum; // If a digit repeats, jump to `nextnum`.
        }

        // Check for repeating digits across `num`, `2*num`, and `3*num`.
        for (m = num; m > 0; m /= 10) {
            d1 = m % 10;
            for (n = num * 2; n > 0; n /= 10) {
                d2 = n % 10;
                for (p = num * 3; p > 0; p /= 10) {
                    d3 = p % 10;
                    if (d1 == d2 || d2 == d3 || d3 == d1)
                        goto nextnum;
                }
            }
        }

        printf("%d %d %d\n", num, num * 2, num * 3);

        // The `goto` jumps here, effectively skipping the rest of the loop's code
        // and moving on to the next number.
        nextnum:; // A label with a semicolon so it doesn't complain.
    }
}

// This function calculates the Least Common Multiple (LCM) and Highest Common Factor (HCF).
// The LCM algorithm is a simple race.
// The HCF algorithm is based on the Euclidean algorithm.
void lcm_hcf() {
    int x, y, a, b;
    printf("Enter two numbers: ");
    scanf_s("%d %d", &x, &y);

    a = x;
    b = y;

    // Calculate LCM
    // Analogy: Two cars start at the same line, one takes steps of size `x`, the other `y`.
    // The loop runs until they land on the same spot. That spot is the LCM.
    while (a != b) {
        if (a < b)
            a += x;
        else
            b += y;
    }
    printf("LCM of %d and %d is %d\n", x, y, a);

    a = x;
    b = y;

    // Calculate HCF
    // Analogy: Two piles of blocks, `a` and `b`. The loop runs until they're the same size.
    // In each step, the bigger pile gets some blocks removed until it's the same size as the smaller one.
    // This is repeated until both piles are equal, and that size is the HCF.
    while (a != b) {
        if (a > b)
            a -= b;
        else
            b -= a;
    }
    printf("HCF of %d and %d is %d\n", x, y, a);
}

// These functions use nested loops to draw patterns.
// Analogy: Think of the outer loop as a robot arm that moves from one row to the next,
// and the inner loop is the pencil it uses to draw in that row.
void draw_triangle() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("*");
        }
        printf("\n");
    }
}

void draw_number_triangle() {
    int n = 5;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= i; j++) {
            printf("%d", j);
        }
        printf("\n");
    }
}

void draw_diamond() {
    int n = 5;
    // This loop builds the top half of the diamond.
    for (int i = 1; i <= n; i++) {
        // Prints the leading spaces to center the pattern.
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        // Prints the stars for the current row.
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }

    // This loop builds the bottom half. It works backward to mirror the top.
    for (int i = n - 1; i >= 1; i--) {
        for (int j = 1; j <= n - i; j++) {
            printf(" ");
        }
        for (int k = 1; k <= 2 * i - 1; k++) {
            printf("*");
        }
        printf("\n");
    }
}

// Main entry point to run all the examples.
int main() {
    printf("--- Running LCM and HCF Example ---\n");
    lcm_hcf();
    printf("\n--- Running Pattern Examples ---\n");
    printf("--- Triangle Pattern ---\n");
    draw_triangle();
    printf("\n--- Number Triangle Pattern ---\n");
    draw_number_triangle();
    printf("\n--- Diamond Pattern ---\n");
    draw_diamond();
    printf("\n--- Running Multiplication Example ---\n");
    multiply_no_operator();
    printf("\n--- Running Fibonacci Example ---\n");
    previous_sum();
    printf("\n--- Running 3-Digit Checker (Original) ---\n");
    check_digits_original();
    printf("\n--- Running 3-Digit Checker (Corrected) ---\n");
    check_digits_corrected();
    printf("\n--- Running `goto` Example ---\n");
    find_special_numbers_goto();

    return 0;
}
