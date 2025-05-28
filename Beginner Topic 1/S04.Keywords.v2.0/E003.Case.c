/**
 * The case keyword is like saying, 'Alright, if this happens, here’s what we do.' 
 * 
 * It’s used inside a switch — kinda like choosing a character in a video game. 
 * 
 * Case 1? Pick Mario. Case 2? Pick Luigi. 
 * 
 * The switch checks the value and jumps to the matching case to run that code.
 * 
 */

#include <stdio.h>
#include <unistd.h> // For sleep

int main() {
    printf("--------------------------------------------\n");
    printf("3. case\n");
    sleep(1);
    printf("--------------------------------------------\n");
    printf("The 'case' keyword is like saying, 'Alright, if this happens, here’s what we do.' It’s used inside a switch — kinda like choosing a character in a video game. Case 1? Pick Mario. Case 2? Pick Luigi. The switch checks the value and jumps to the matching case to run that code.\n");
    printf("--------------------------------------------\n");
    sleep(1);

    int choice = 2; // User's choice, like picking a character

    printf("Choosing character for game... (choice: %d)\n", choice);
    switch (choice) {
        case 1:
            printf("You picked Mario! It's-a me!\n");
            break; // Don't fall through to other cases
        case 2:
            printf("You picked Luigi! Let's-a go!\n");
            break;
        case 3:
            printf("You picked Princess Peach! Yay!\n");
            break;
        default:
            printf("Invalid choice. Picking default character, Toad.\n");
            break;
    }
    sleep(5);
    return 0;
}