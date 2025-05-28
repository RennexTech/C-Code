/**
 * 
 * while is like your program's 'keep doing this AS LONG AS...' command. 
 * 
 * Imagine you're eating popcorn while the movie is still playing. 
 * 
 * As long as the movie is on (the condition is true), you keep eating popcorn. 
 * 
 * The moment the movie ends (the condition becomes false), you stop. 
 * 
 * It's perfect for repeating a block of code an unknown number of times, 
 * 
 * as long as a certain condition remains true.
 * 
 */

#include <stdio.h>
#include <stdbool.h> // For 'true' and 'false'
#include <unistd.h>  // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("32. while\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("'while' is like your program's 'keep doing this AS LONG AS...' command. Imagine you're eating popcorn **while** the movie is still playing... It's perfect for repeating a block of code an unknown number of times, as long as a certain condition remains true.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int popcorn_count = 5;
    bool movie_playing = true;

    printf("Starting to watch the movie and eat popcorn:\n");
    while (movie_playing) { // As long as the movie is playing...
        if (popcorn_count > 0) {
            printf("Eating a piece of popcorn! (%d left)\n", popcorn_count);
            popcorn_count--;
        } else {
            printf("No more popcorn! Movie is still on, but I'm done. 🍿❌\n");
            movie_playing = false; // Set condition to false to stop the loop
        }
        sleep(1);
    }
    printf("Movie finished (or popcorn ran out!). Time to chill.\n");

    printf("\nCountdown loop (different condition):\n");
    int timer = 3;
    while (timer > 0) {
        printf("Timer: %d...\n", timer);
        timer--;
        sleep(1);
    }
    printf("Timer done! Ding! 🔔\n");
    sleep(5);
    return 0;
}

