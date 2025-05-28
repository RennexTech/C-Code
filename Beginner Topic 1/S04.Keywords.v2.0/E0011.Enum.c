/**
 * 
 * The enum keyword lets you give meaningful names to numbers, turning cryptic digits into clear labels. 
 * 
 * Imagine you're coding a traffic light. Instead of saying: 'If light_state == 0, turn red.' '
 * 
 * If light_state == 1, turn yellow.' 'If light_state == 2, turn green.' 
 * 
 * which is super easy to mess up or forget what 0, 1, or 2 means... 
 * 
 * You use enum to define: RED = 0, YELLOW = 1, GREEN = 2. 
 * 
 * Now, your code says: 'If light_state == RED, turn red.' 'If light_state == GREEN, turn green.' 
 * 
 * See? It's like having a clear, self-explaining menu for your numbers. 
 * 
 * Makes your code infinitely easier to read, understand, and debug, 
 * 
 * so you don't have to guess what '1' was supposed to be!
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

// Define your squad of named constants for game states
enum GameState {
    PLAYING,      // Default value is 0
    PAUSED,       // Default value is 1
    GAME_OVER     // Default value is 2
};

// Another example for traffic light colors
enum TrafficLight {
    RED,          // 0
    YELLOW,       // 1
    GREEN         // 2
};

int main() {
    printf("--------------------------------------------\n");
    printf("11. enum\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'enum' keyword lets you give meaningful names to numbers, turning cryptic digits into clear labels. Imagine you're coding a traffic light... See? It's like having a clear, self-explaining menu for your numbers. Makes your code infinitely easier to read, understand, and debug, so you don't have to guess what '1' was supposed to be!\n");
    printf("--------------------------------------------\n");
    sleep(1);

    enum GameState current_game_state = PAUSED; // WAY better than "state = 1"

    printf("Current Game State: ");
    if (current_game_state == PLAYING) {
        printf("Game is running! 🎮\n");
    } else if (current_game_state == PAUSED) {
        printf("Game paused! ⏸️ (Value: %d)\n", current_game_state); // No magic numbers!
    } else if (current_game_state == GAME_OVER) {
        printf("Game over! 💀\n");
    }

    enum TrafficLight light = GREEN;
    printf("Traffic Light Status: ");
    switch (light) {
        case RED:
            printf("STOP! 🔴\n");
            break;
        case YELLOW:
            printf("SLOW DOWN! 🟡\n");
            break;
        case GREEN:
            printf("GO! 🟢 (Value: %d)\n", light);
            break;
    }
    sleep(5);
    return 0;
}