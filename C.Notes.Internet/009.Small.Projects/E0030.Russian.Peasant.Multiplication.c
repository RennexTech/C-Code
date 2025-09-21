/* Program to multiply two numbers by Russian peasant method */
#include <stdio.h>

int main() {
    int a, b, x, y, s = 0;
    printf("Enter two number to be multiplied: \n");
    scanf("%d%d", &a, &b);
    
    // We store the original numbers to print at the end, as 'a' and 'b' will be changed
    // inside the loop. Think of it as making a copy of a recipe before you start cooking.
    x = a;
    y = b;
    
    // This is the core of the Russian peasant method. The loop runs until the first number
    // becomes 0.
    while (a >= 1) {
        // We check if the current value of 'a' is odd.
        if (a % 2 != 0)
            // If it is, we add the current value of 'b' to our running sum.
            s = s + b;
        
        // We halve the first number.
        a = a / 2;
        
        // We double the second number.
        b = b * 2;
    }
    
    printf("%d*%d=%d\n", x, y, s);
    return 0;
}