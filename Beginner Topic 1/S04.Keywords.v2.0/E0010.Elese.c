/**
 * 
 * The else keyword is like the plan B for your if statement. 
 * 
 * When the if or else if conditions fail, else jumps in and says, 
 * 
 * 'Alright, here’s what happens next because these two brothers of mine failed to execute.' 
 * 
 * It’s your way to cover all the bases and keep the code flowing.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("10. else\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'else' keyword is like the plan B for your if statement. When the 'if' or 'else if' conditions fail, 'else' jumps in and says, 'Alright, here’s what happens next because these two brothers of mine failed to execute.' It’s your way to cover all the bases and keep the code flowing.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int temperature = 28; // Current room temperature

    printf("Checking room temperature (%d degrees C):\n", temperature);
    if (temperature > 30) {
        printf("It's scorching hot! Turn on the AC! 🥵\n");
    } else if (temperature < 15) {
        printf("It's freezing! Grab a blanket! 🥶\n");
    } else {
        printf("Temperature is just right. Chillin'. 😎\n"); // Plan B
    }

    int baby_status = 1; // 1 for hungry, 0 for not hungry

    printf("\nBaby status check (1=hungry, 0=not hungry):\n");
    if (baby_status == 1) {
        printf("Baby is hungry! Time to eat! 🍼\n");
    } else {
        printf("Baby is not hungry. Maybe they're sleeping or playing. 😴\n"); // Plan B
    }
    sleep(5);
    return 0;
}