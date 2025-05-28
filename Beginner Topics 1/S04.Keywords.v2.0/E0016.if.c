/**
 * 
 * if is the decision-maker, the bouncer at the logic club. 
 * 
 * You give it a condition, and if it's true, it lets your code in. 
 * 
 * Real life: if (baby_is_hungry) → eat(); else → cry(); 
 * 
 * Clean, direct, no unnecessary drama. Unless you're nesting 5 levels deep😑.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("16. if\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("if is the decision-maker, the bouncer at the logic club. You give it a condition, and if it's true, it lets your code in. Real life: if (baby_is_hungry) → eat(); else → cry(); Clean, direct, no unnecessary drama. Unless you're nesting 5 levels deep 😅\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int temperature = 22; // Current temperature in Celsius

    printf("Current temperature: %d°C\n", temperature);
    if (temperature > 25) { // Is the condition true?
        printf("It's hot! Time for ice cream! 🍦\n");
    } else { // If the first condition is false, do this
        printf("Temperature is cool. Perfect for coding. 💻\n");
    }

    int score = 85;
    printf("\nYour test score: %d\n", score);
    if (score >= 90) {
        printf("You got an A! Amazing! 🎉\n");
    } else if (score >= 80) { // If first 'if' was false, check this
        printf("You got a B! Good job! 👍\n");
    } else { // If both above were false, do this
        printf("Keep studying! You got this! 💪\n");
    }
    sleep(5);
    return 0;
}

