#include <stdio.h>
#include <windows.h>
#include <time.h>

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
        printf("Num1 is currently: %d\n", num1);
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

// The main function where it all starts.
int main() {
    int i;
    int num = 0;

    // This is a simple counter loop.
    // We're just telling the computer, "Hey, count from 0 to 99,
    // and print each number as you go." It's a perfect example of
    // when a `for` loop is ideal, because you know exactly how many
    // times you need to run the code.
    for (i = 0; i < 100; i++) {
        num += 1;
        printf("The current number is: %d\n", num);
    }
    printf("\n");

    // We're calling our two other functions to run.
    multiply_no_operator();
    printf("\n");
    previous_sum();

    return 0;
}
