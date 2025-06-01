#include <stdio.h>   // For printf, our program's mic.
#include <unistd.h>  // For sleep() to chill between outputs, keep the flow smooth.

/**
 * 
 * @brief ✨ C Symbolic Constants: Giving Your Code Nicknames
 *
 * @analog Ever used a shortcut or given someone a nickname?
 * Like calling your bestie "BFF" or setting up a quick link to your
 * favorite streaming service?
 *
 * In C, `#define` lets you do exactly that for values! You give a fixed value
 * a cool, memorable name. The compiler then *automatically replaces* that name
 * with its actual value everywhere in your code *before* it even runs.
 *
 * Why do we do this?
 * 1. Readability: `MAX_PLAYERS` is way clearer than just `100`.
 * 2. Maintainability: If the `MAX_PLAYERS` changes to `200`, you ONLY UPDATE IT IN ONE PLACE, not everywhere it's used! Big brain moves. 🧠
 *
 * This program is your playground to see these constant aliases in action.
 * 
 * 
 */

// --- Symbolic Constants: Our Code's Nicknames! ---
// @analog: These are like global settings for your app. Set once, used everywhere.
#define GAME_TITLE "Cosmic Blaster 3000" // Name of our epic game
#define MAX_PLAYERS 4                   // Max players for a multiplayer game
#define STARTING_LIVES 3                // How many tries you get at the beginning
#define PI_VALUE 3.14159                // A super important math number, accurate!
#define DEBUG_MODE 1                    // 1 means 'ON', 0 means 'OFF' for debugging features
#define BOSS_LEVEL_MESSAGE "Watch out! The Cosmic Tyrant approaches!" // An epic warning

int main() {
    printf("=============================================================\n");
    printf("  C Symbolic Constants: Giving Your Code Nicknames! ✨     \n");
    printf("=============================================================\n");
    sleep(1);

    printf("\n--- Setting the Game Vibes with Constants! ---\n");
    printf("    @analog: We're using our defined nicknames to build parts of our game.\n");
    printf("    It's cleaner, easier to change, and just looks better. Periodt.\n");
    sleep(2);

    // Using our defined constants in the code
    char game_name[50]; // A char array to hold our game title
    sprintf(game_name, "%s", GAME_TITLE); // Copying the constant string into a variable

    int current_players = MAX_PLAYERS;
    double area_of_circle = PI_VALUE * 5 * 5; // Area = PI * radius * radius (radius is 5 here)
    char debug_status = (DEBUG_MODE == 1) ? 'Y' : 'N'; // Convert 1/0 to Y/N
    int player_tries = STARTING_LIVES;

    printf("\n");
    printf("Welcome to '%s'! Get ready to play! 🚀\n", game_name);
    sleep(1);

    printf("Max players for this session: %d\n", current_players);
    sleep(1);

    printf("Your starting lives: %d (Don't mess this up! 😉)\n", player_tries);
    sleep(1);

    printf("If our cosmic ship has a radius of 5 units, its area is: %.2lf units squared. 🪐\n", area_of_circle);
    printf("    (Calculated using our precise PI_VALUE: %.5lf)\n", PI_VALUE);
    sleep(1);

    printf("Is Debug Mode currently ON? %c (If this is 'Y', things might get wild!)\n", debug_status);
    sleep(1);

    printf("And a special message from our game: \"%s\"\n", BOSS_LEVEL_MESSAGE);
    sleep(2);

    printf("\n--- The Takeaway: Why Constants Slay! 🔥 ---\n");
    printf("    See how easy it was to use those named values?\n");
    printf("    If we wanted to change the `MAX_PLAYERS` to 8, we just change it ONCE at the top,\n");
    printf("    and it updates everywhere automatically. That's efficiency, baby! 💯\n");
    sleep(2);

    printf("=============================================================\n");
    printf("You just mastered C Symbolic Constants! Your code is leveling up! ⬆️\n");
    printf("=============================================================\n");

    return 0; // Program finished successfully. GG! 🎮
}
