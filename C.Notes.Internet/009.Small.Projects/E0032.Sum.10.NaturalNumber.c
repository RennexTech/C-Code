#include <stdio.h>

int main() {
    int i, sum = 0;
    
    // The for loop is like a metronome, counting from 1 to 10.
    // With each tick, it adds the current number to a running total.
    printf("Natural Numbers are \n");
    for (i = 1; i <= 10; i++) {
        printf("%d\t", i);
        // The `sum = sum + i` line is a classic accumulation pattern.
        // It's like adding an ingredient to a bowl with each step of a recipe.
        sum = sum + i;
    }
    
    printf("\nSum = %d\n", sum);
    return 0;
}