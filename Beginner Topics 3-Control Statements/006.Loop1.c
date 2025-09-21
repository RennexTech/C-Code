#include <stdio.h>
#include <windows.h>
#include <time.h>

// This function multiplies two numbers using only addition and a loop.
// It's a low-level way of doing a basic operation. In reverse engineering,
// you might see a compiler turn a simple multiplication into a loop like this
// for certain optimizations or in obfuscated code to hide its purpose.
void multiply_no_operator() {
    int num1, num2, num3 = 0;
    int j;

    // Get the numbers from the user.
    printf("Enter the first number: ");
    scanf_s("%d", &num1);
    printf("Enter the second number: ");
    scanf_s("%d", &num2);

    // This block handles negative numbers before the loop starts.
    // Think of it as a pre-flight check: if the second number is negative,
    // we flip the sign on both numbers. This makes sure the loop runs
    // a positive number of times, but the final result still has
    // the correct sign. A simple, smart move.
    if (num2 < 0) {
        num1 = -num1;
        num2 = -num2;
    }

    // This is the core engine.
    // The loop's job is to run `num2` number of times. Each time it runs,
    // it takes the value of `num1` and adds it to our total `num3`.
    // It’s the brute force method, but it gets the job done.
    for (j = 0; j < num2; j++) {
        num3 = num3 + num1;
        printf("Num1 is currently: %d\n", num1);
    }

    // Display the final total.
    printf("The result of multiplication is: %d\n", num3);
}

// This function generates a Fibonacci-style sequence, where each
// number is the sum of the two before it. It’s a common pattern
// in algorithms and a good mental exercise.
void previous_sum() {
    long x, y, z;
    int i, n;
    x = 0;
    y = 1;
    printf("Enter the number of terms: ");
    scanf_s("%ld", &n);
    printf("%ld ", y);

    // This loop builds the sequence one number at a time.
    // Analogy: Imagine you're building a tower of blocks. To place a new block (`z`),
    // you look at the size of the last two blocks you placed (`x` and `y`).
    // Once you've placed the new block, you have to shift your focus to the
    // two most recent blocks so you're ready for the next one.
    for (i = 1; i < n; i++) {
        z = x + y;
        printf("%ld ", z);
        x = y;
        y = z;
    }
    printf("\n");
}

// The main entry point for the program.
int main() {
    int i;
    int num = 0;

    // This loop is a textbook example of a `for` loop, which you use when
    // you know exactly how many times you need to run something.
    // The `for` loop has three parts that work together:
    // 1. The setup (`i = 0`): Get your variables ready.
    // 2. The check (`i < 100`): Keep going as long as this is true.
    // 3. The update (`i++`): Change something after each run so you can eventually stop.
    // It's a clean way to manage a known number of iterations.
    for (i = 0; i < 100; i++) {
        num += 1;
        printf("The current number is: %d\n", num);
    }
    printf("\n");

    // Call our two other functions to show them off.
    multiply_no_operator();
    printf("\n");
    previous_sum();

    return 0;
}
